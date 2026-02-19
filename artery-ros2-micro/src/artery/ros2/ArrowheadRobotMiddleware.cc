#include "artery/ros2/ArrowheadRobotMiddleware.h"
#include "artery/ros2/ArrowheadRobotInetMobility.h"
#include "artery/utility/InitStages.h"
#include "ros2/RobotObject.h"
#include <inet/common/ModuleAccess.h>

namespace artery
{

Define_Module(ArrowheadRobotMiddleware)

using namespace omnetpp;

namespace
{
const simsignal_t robotPositionChangedSignal = cComponent::registerSignal("robotPositionChanged");
} // namespace

ArrowheadRobotMiddleware::ArrowheadRobotMiddleware() :
    mVehicleDataProvider(0)
{
}

void ArrowheadRobotMiddleware::initialize(int stage)
{
    if (stage == InitStages::Self) {
        mMobility = inet::getModuleFromPar<ArrowheadRobotInetMobility>(par("mobilityModule"), this);
        mMobility->subscribe(robotPositionChangedSignal, this);
        initializeStationType(mMobility->getLastRobotObject().getType());
        mVehicleDataProvider.update(getKinematics(*mMobility));
        getFacilities().register_const(&mVehicleDataProvider);
        getFacilities().register_const(&mMobility->getLastRobotObject());

        auto& robot = getFacilities().getConst<ros2::RobotObject>();
        std::string mRobotId = robot.getId();

        //Add the occupancygrid to vehicle data
        mVehicleDataProvider.setOccupancyGrid(mMobility->getLastRobotObject().getOccupancyGrid());

        // Identity not random anymore, last digits determine robot ID for Ros2
        Identity identity;
        identity.application = 1000000000 + (int)mRobotId.back() - '0';
        mVehicleDataProvider.setStationId(identity.application);
        emit(Identity::changeSignal, Identity::ChangeStationId, &identity);
    }

    Middleware::initialize(stage);
}

void ArrowheadRobotMiddleware::receiveSignal(cComponent*, simsignal_t signal, cObject*, cObject*)
{
    if (signal == robotPositionChangedSignal && mMobility) {
        mVehicleDataProvider.update(getKinematics(*mMobility));
        //Add occupancygrid
        mVehicleDataProvider.setOccupancyGrid(mMobility->getLastRobotObject().getOccupancyGrid());
    }
}

void ArrowheadRobotMiddleware::initializeStationType(const std::string& robotType)
{
    using vanetza::geonet::StationType;
    StationType gnStationType = StationType::Unknown;

    if (robotType == "CAR") {
        gnStationType = StationType::Passenger_Car;
    } else if (robotType == "EMERGENCY_VEHICLE") {
        gnStationType = StationType::Special_Vehicle;
    } else if (robotType == "BUS" || robotType == "SCHEDULED_BUS") {
        gnStationType = StationType::Bus;
    } else if (robotType == "VAN") {
        gnStationType = StationType::Light_Truck;
    } else if (robotType == "TRUCK") {
        gnStationType = StationType::Heavy_Truck;
    } else if (robotType == "BICYCLE") {
        gnStationType = StationType::Cyclist;
    } else if (robotType == "PEDESTRIAN") {
        gnStationType = StationType::Pedestrian;
    } else if (robotType == "MOPED") {
        gnStationType = StationType::Moped;
    }

    setStationType(gnStationType);
    mVehicleDataProvider.setStationType(gnStationType);
}

VehicleKinematics ArrowheadRobotMiddleware::getKinematics(const ArrowheadRobotInetMobility& mobility) const
{
    using namespace vanetza::units::si;

    VehicleKinematics kinematics;
    kinematics.position = mobility.getPosition();
    kinematics.geo_position = mobility.getGeoPosition();
    kinematics.speed = mobility.getLastRobotObject().getSpeed() * meter_per_second;
    kinematics.acceleration = mobility.getLastRobotObject().getAcceleration() * meter_per_second_squared;
    kinematics.heading = mobility.getLastRobotObject().getHeadingRad() * radian;
    kinematics.yaw_rate = mobility.getLastRobotObject().getYawRateRad() * radian_per_second;
    return kinematics;
}

} // namespace artery
