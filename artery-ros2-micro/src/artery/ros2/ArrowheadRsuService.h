#ifndef ARROWHEADRSUSERVICE_H_
#define ARROWHEADRSUSERVICE_H_

#include "artery/application/ItsG5Service.h"
#include "artery/application/NetworkInterface.h"
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <ros2/Ros2Node.h>

namespace artery
{

class CloudNode;

class ArrowheadRsuService : public ItsG5Service
{
public:
    ArrowheadRsuService();

    void indicate(const vanetza::btp::DataIndication&, omnetpp::cPacket*, const NetworkInterface&) override;
    void trigger() override;

protected:
    void initialize() override;
    void finish() override;

private:
    void onRequest(const std_msgs::msg::String::SharedPtr msg);

    Ros2Node rosNode;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    CloudNode* mCloudNode = nullptr;
};

} // namespace artery

#endif /* ARROWHEADRSUSERVICE_H_ */
