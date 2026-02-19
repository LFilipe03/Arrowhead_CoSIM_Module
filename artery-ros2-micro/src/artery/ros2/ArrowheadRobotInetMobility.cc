#include "artery/ros2/ArrowheadRobotInetMobility.h"
#include <inet/common/ModuleAccess.h>
#include <inet/common/geometry/common/CanvasProjection.h>
#include <inet/common/geometry/common/CoordinateSystem.h>
#include <inet/features.h>
#include <cmath>

#ifdef WITH_VISUALIZERS
#   include <inet/visualizer/mobility/MobilityCanvasVisualizer.h>
#else
#   include <cstdio>
#endif

namespace artery
{

Define_Module(ArrowheadRobotInetMobility)

namespace
{

using namespace omnetpp;
const simsignal_t robotPositionChangedSignal = cComponent::registerSignal("robotPositionChanged");
const simsignal_t simulationPositionChangedSignal = cComponent::registerSignal("simulationPositionChanged");
const simsignal_t serviceRegistryUpdatedSignal = cComponent::registerSignal("serviceRegistryUpdated");

} // namespace

ArrowheadRobotInetMobility::ArrowheadRobotInetMobility() : rosNode(Ros2Node::getInstance())
{
}

ArrowheadRobotInetMobility::~ArrowheadRobotInetMobility()
{
}

int ArrowheadRobotInetMobility::numInitStages() const
{
    return inet::INITSTAGE_PHYSICAL_ENVIRONMENT_2 + 1;
}

void ArrowheadRobotInetMobility::initialize(int stage)
{
    if (stage == inet::INITSTAGE_LOCAL) {

        mSimulationPosition = inet::Coord(0, 0, 0);
        mPosition = inet::Coord(0, 0, 0);
        mSpeed = inet::Coord(0, 0, 0);

        mOrientation.alpha = 0;
        mYawRate.alpha = 0;

        ros2::RobotObject robot;
        robot.setHeading(0);
        robot.setSpeed(0);
        robot.setYawRate(0);
        robot.setPosition({0,0,0});
        mLastRobotObject = robot;
        robot.setId("ArrowheadRobot");
        mLastSimulationRobotObject = robot;

        mVisualRepresentation = inet::getModuleFromPar<cModule>(par("visualRepresentation"), this, false);
        mCoordinateSystem = inet::getModuleFromPar<inet::IGeographicCoordinateSystem>(par("coordinateSystemModule"), this);
        omnetpp::createWatch("position", mPosition);
        omnetpp::createWatch("simulationPosition", mSimulationPosition);
        omnetpp::createWatch("speed", mSpeed);
        omnetpp::createWatch("orientation", mOrientation);
        omnetpp::createWatch("ROBOT ID", mLastRobotObject.getId());
        localizationSub = rosNode.getRosNode()->create_subscription<etsi_its_msgs::msg::CAM>(mLastRobotObject.getId()+"/cam_out",1,std::bind(&ArrowheadRobotInetMobility::localization_callback,this,std::placeholders::_1));
        simulationSub = rosNode.getRosNode()->create_subscription<micro_its_msgs::msg::CAM>(mLastRobotObject.getId()+"/simulation_pose",1,std::bind(&ArrowheadRobotInetMobility::simulation_callback,this,std::placeholders::_1));
        arrowheadserviceregistrySub = rosNode.getRosNode()->create_subscription<arrowhead_msgs::msg::ServiceRegistration>(mLastRobotObject.getId()+"/Arrowhead_Service_Registry",1,std::bind(&ArrowheadRobotInetMobility::arrowhead_callback,this,std::placeholders::_1));
    } else if (stage == inet::INITSTAGE_PHYSICAL_ENVIRONMENT_2) {
        if (mVisualRepresentation) {
            auto target = mVisualRepresentation->getParentModule();
            mCanvasProjection = inet::CanvasProjection::getCanvasProjection(target->getCanvas());
        }
        updateVisualRepresentation();
    }
}

void ArrowheadRobotInetMobility::localization_callback(const etsi_its_msgs::msg::CAM::SharedPtr msg)
{
    ros2::RobotObject robot;
    robot.setId(mLastRobotObject.getId());
    robot.setType("PASSENGER_CAR");
    // flix y-axis (positive is up in Ros vs. negative is up in OMNeT++/INET)
    robot.setPosition({msg->reference_position.longitude/10, -(msg->reference_position.latitude/10), msg->reference_position.altitude.value/100 });
    // Scale back the received heading value to [0,360]
    robot.setHeading((double)msg->high_frequency_container.heading.value/10);
    // Scale back the received speed value to m/s
    robot.setSpeed((double)msg->high_frequency_container.speed.value/100);
    robot.setDriveDirection(msg->high_frequency_container.drive_direction.value);
    robot.setVehicleLength(msg->high_frequency_container.vehicle_length.value);
    robot.setVehicleWidth(msg->high_frequency_container.vehicle_width.value);
    // Scale the acceleration value to m/s^2
    robot.setAcceleration((double)msg->high_frequency_container.longitudinal_acceleration.value/10);
    robot.setCurvature(msg->high_frequency_container.curvature.value);
    // Scale the yaw rate value to degree/s
    robot.setYawRate((double)msg->high_frequency_container.yaw_rate.value/100);
    robot.setOccupancyGrid(msg->occupancygrid);
    
    mLastRobotObject = robot;
    std::tie(mPosition.x, mPosition.y, mPosition.z) = robot.getPosition();

    emit(robotPositionChangedSignal, &robot);
}

void ArrowheadRobotInetMobility::simulation_callback(const micro_its_msgs::msg::CAM::SharedPtr msg)
{
    ros2::RobotObject robot;
    robot.setId(mLastRobotObject.getId());
    robot.setType("PASSENGER_CAR");
    // flix y-axis (positive is up in Ros vs. negative is up in OMNeT++/INET)
    robot.setPosition({msg->x, -msg->y, msg->z });
    robot.setHeading((double)msg->theta);
    robot.setSpeed((double)msg->v);
    robot.setDriveDirection(msg->drive_direction);
    robot.setVehicleLength(msg->vehicle_length);
    robot.setVehicleWidth(msg->vehicle_width);
    robot.setAcceleration((double)msg->vdot);
    robot.setCurvature(msg->curv);
    robot.setYawRate((double)msg->thetadot);

    update(robot);
}

void ArrowheadRobotInetMobility::arrowhead_callback(const arrowhead_msgs::msg::ServiceRegistration::SharedPtr msg)
{
    ros2::ServiceObject service;

    service.setServiceValidation(msg->service_validation);
    service.setServerAddrPort(msg->server_addrport);

    // ServiceData
    service.setServiceDefinition(msg->service_data.service_definition);
    service.setServiceURI(msg->service_data.service_uri);
    service.setVersion(msg->service_data.version);
    service.setSecure(msg->service_data.secure);
    service.setInterfaces(msg->service_data.interfaces);

    // Metadata
    service.setHighwayName(msg->service_data.metadata.highway_name);
    service.setEntranceNumber(msg->service_data.metadata.entrance_number);

    // ProviderSystem
    service.setSystemName(msg->service_data.provider_system.system_name);
    service.setAddress(msg->service_data.provider_system.address);
    service.setPort(msg->service_data.provider_system.port);
    service.setAuthenticationInfo(
        msg->service_data.provider_system.authentication_info);

    mLastServiceObject = service;

    emit(serviceRegistryUpdatedSignal, &service);
}

double ArrowheadRobotInetMobility::getMaxSpeed() const
{
    return NaN;
}

inet::Coord ArrowheadRobotInetMobility::getCurrentPosition()
{
    return mSimulationPosition;
}

inet::Coord ArrowheadRobotInetMobility::getCurrentSpeed()
{
    return mSpeed;
}

inet::EulerAngles ArrowheadRobotInetMobility::getCurrentAngularPosition()
{
    return mOrientation;
}

inet::EulerAngles ArrowheadRobotInetMobility::getCurrentAngularSpeed()
{
    return mYawRate;
}

inet::Coord ArrowheadRobotInetMobility::getConstraintAreaMax() const
{
    return inet::Coord::NIL;
}

inet::Coord ArrowheadRobotInetMobility::getConstraintAreaMin() const
{
    return inet::Coord::NIL;
}

void ArrowheadRobotInetMobility::initialize(const ros2::RobotObject& robot)
{
    setInetProperties(robot);
    mLastRobotObject = robot;
    mLastSimulationRobotObject = robot;
}

void ArrowheadRobotInetMobility::update(const ros2::RobotObject& robot)
{
    setInetProperties(robot);
    //copyable as a base class, because then you don't need to write a copy constructor, assignment operator, and dup() function, spaemit(inet::IMobility::mobilityStateChangedSignal, this);
    emit(simulationPositionChangedSignal, &robot);
    updateVisualRepresentation();
    mLastSimulationRobotObject = robot;
}

void ArrowheadRobotInetMobility::initialize(const ros2::ServiceObject& service)
{
    mLastServiceObject = service;
}




void ArrowheadRobotInetMobility::setInetProperties(const ros2::RobotObject& robot)
{
    const double headingRad = robot.getHeadingRad();
    const inet::Coord direction { std::cos(headingRad), -std::sin(headingRad) };
    mOrientation.alpha = -headingRad;
    mYawRate.alpha = robot.getYawRate();
    mSpeed = direction * pow(-1,robot.getDriveDirection()) * robot.getSpeed();
    std::tie(mSimulationPosition.x, mSimulationPosition.y, mSimulationPosition.z) = robot.getPosition();
}

void ArrowheadRobotInetMobility::updateVisualRepresentation()
{
    // following code is taken from INET's MobilityBase::updateVisualRepresentation
    if (hasGUI() && mVisualRepresentation) {
#ifdef WITH_VISUALIZERS
        using inet::visualizer::MobilityCanvasVisualizer;
        MobilityCanvasVisualizer::setPosition(mVisualRepresentation, mCanvasProjection->computeCanvasPoint(getCurrentPosition()));
#else
        auto position = mCanvasProjection->computeCanvasPoint(getCurrentPosition());
        char buf[32];
        snprintf(buf, sizeof(buf), "%lf", position.x);
        buf[sizeof(buf) - 1] = 0;
        mVisualRepresentation->getDisplayString().setTagArg("p", 0, buf);
        snprintf(buf, sizeof(buf), "%lf", position.y);
        buf[sizeof(buf) - 1] = 0;
        mVisualRepresentation->getDisplayString().setTagArg("p", 1, buf);
#endif
    }
}

Position ArrowheadRobotInetMobility::getPosition() const
{
    return Position {mPosition.x, mPosition.y};
}

GeoPosition ArrowheadRobotInetMobility::getGeoPosition() const
{
    inet::GeoCoord inet = mCoordinateSystem->computeGeographicCoordinate(mPosition);
    GeoPosition pos;
    pos.latitude = inet.latitude * boost::units::degree::degree;
    pos.longitude = inet.longitude * boost::units::degree::degree;

    return pos;
}

Position ArrowheadRobotInetMobility::getSimulationPosition() const
{
    return Position {mSimulationPosition.x, mSimulationPosition.y};
}

GeoPosition ArrowheadRobotInetMobility::getSimulationGeoPosition() const
{
    inet::GeoCoord inet = mCoordinateSystem->computeGeographicCoordinate(mSimulationPosition);
    GeoPosition pos;
    pos.latitude = inet.latitude * boost::units::degree::degree;
    pos.longitude = inet.longitude * boost::units::degree::degree;

    return pos;
}

double ArrowheadRobotInetMobility::getSpeed() const
{
    return double { mLastRobotObject.getSpeed() };
}

Angle ArrowheadRobotInetMobility::getHeading() const
{
    return Angle { mLastRobotObject.getHeadingRad() };
}

Angle ArrowheadRobotInetMobility::getYawRate() const
{
    return Angle { mLastRobotObject.getYawRateRad() };
}

} // namespace artery
