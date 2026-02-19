#ifndef ARTERY_ROS2_ARROWHEADROBOTINETMOBILITY_H_9C4E2B
#define ARTERY_ROS2_ARROWHEADROBOTINETMOBILITY_H_9C4E2B

#include "artery/utility/Geometry.h"
#include "ros2/RobotSink.h"
#include "ros2/ServiceSink.h"
#include "ros2/ServiceObject.h"
#include <inet/mobility/contract/IMobility.h>
#include <omnetpp/csimplemodule.h>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <etsi_its_msgs/msg/cam.hpp>
#include <micro_its_msgs/msg/cam.hpp>
#include <arrowhead_msgs/msg/service_registration.hpp>


#include <ros2/Ros2Node.h>

namespace inet {
    class CanvasProjection;
    class IGeographicCoordinateSystem;
} // inet

namespace artery
{

class ArrowheadRobotInetMobility :
    public inet::IMobility, public ros2::RobotSink, public ros2::ServiceSink,
    public omnetpp::cSimpleModule
{
public:
    ArrowheadRobotInetMobility();
    virtual ~ArrowheadRobotInetMobility();

    void initialize(int stage) override;
    int numInitStages() const override;

    // inet::IMobility interface
    double getMaxSpeed() const override;
    inet::Coord getCurrentPosition() override;
    inet::Coord getCurrentSpeed() override;
    inet::EulerAngles getCurrentAngularPosition() override;
    inet::EulerAngles getCurrentAngularSpeed() override;
    inet::Coord getConstraintAreaMax() const override;
    inet::Coord getConstraintAreaMin() const override;

    // ros2::RobotSink
    void initialize(const ros2::RobotObject&) override;
    void update(const ros2::RobotObject&) override;

    // ros2::ServiceSink
    void initialize(const ros2::ServiceObject&) override;
 

    const ros2::RobotObject& getLastRobotObject() const { return mLastRobotObject; }
    const ros2::RobotObject& getLastSimulationRobotObject() const { return mLastSimulationRobotObject; }
    Position getSimulationPosition() const;
    GeoPosition getSimulationGeoPosition() const;
    Position getPosition() const;
    GeoPosition getGeoPosition() const;
    double getSpeed() const;
    Angle getHeading() const;
    Angle getYawRate() const;

protected:
    virtual void setInetProperties(const ros2::RobotObject&);
    virtual void updateVisualRepresentation();

private:
    ros2::RobotObject mLastRobotObject;
    ros2::ServiceObject mLastServiceObject;
    ros2::RobotObject mLastSimulationRobotObject;
    inet::Coord mSimulationPosition;
    inet::Coord mPosition;
    inet::Coord mSpeed;
    inet::EulerAngles mOrientation;
    inet::EulerAngles mYawRate;
    omnetpp::cModule* mVisualRepresentation = nullptr;
    const inet::CanvasProjection* mCanvasProjection = nullptr;
    const inet::IGeographicCoordinateSystem* mCoordinateSystem = nullptr;

    Ros2Node rosNode;
    rclcpp::Subscription<etsi_its_msgs::msg::CAM>::SharedPtr localizationSub;
    rclcpp::Subscription<micro_its_msgs::msg::CAM>::SharedPtr simulationSub;
    rclcpp::Subscription<arrowhead_msgs::msg::ServiceRegistration>::SharedPtr arrowheadserviceregistrySub;
    void localization_callback(const etsi_its_msgs::msg::CAM::SharedPtr);
    void simulation_callback(const micro_its_msgs::msg::CAM::SharedPtr);
    void arrowhead_callback(const arrowhead_msgs::msg::ServiceRegistration::SharedPtr);
};

} // namespace artery

#endif /* ARTERY_ROS2_ARROWHEADROBOTINETMOBILITY_H_9C4E2B */