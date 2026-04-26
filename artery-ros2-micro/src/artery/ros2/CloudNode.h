#ifndef CLOUDNODE_H_
#define CLOUDNODE_H_

#include <omnetpp/csimplemodule.h>
#include <rclcpp/rclcpp.hpp>
#include <arrowhead_msgs/msg/arrowhead_response.hpp>
#include <ros2/Ros2Node.h>
#include <curl/curl.h>
#include <string>

namespace artery
{

class CloudNode : public omnetpp::cSimpleModule
{
public:
    CloudNode();
    void handleRequest(const std::string& carId);

protected:
    void initialize() override;
    void handleMessage(omnetpp::cMessage* msg) override;

private:
    std::string requestOrchestration(const std::string& carId);

    Ros2Node rosNode;
    rclcpp::Publisher<arrowhead_msgs::msg::ArrowheadResponse>::SharedPtr publisher_;
};

} // namespace artery

#endif /* CLOUDNODE_H_ */
