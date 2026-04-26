#include "artery/ros2/ArrowheadRsuService.h"
#include "artery/ros2/CloudNode.h"
#include <omnetpp.h>

using namespace omnetpp;

namespace artery
{

Define_Module(ArrowheadRsuService);

ArrowheadRsuService::ArrowheadRsuService()
    : rosNode(Ros2Node::getInstance())
{
}

void ArrowheadRsuService::initialize()
{
    ItsG5Service::initialize();

    mCloudNode = dynamic_cast<CloudNode*>(
        getSimulation()->getSystemModule()->getSubmodule("cloudNode"));

    if (!mCloudNode) {
        EV_ERROR << "ArrowheadRsuService: cloudNode not found in network\n";
    }

    subscription_ = rosNode.getRosNode()->create_subscription<std_msgs::msg::String>(
        "arrowhead_request", 10,
        std::bind(&ArrowheadRsuService::onRequest, this, std::placeholders::_1));

    EV_INFO << "ArrowheadRsuService initialized, subscribed to /arrowhead_request\n";
}

void ArrowheadRsuService::finish()
{
    ItsG5Service::finish();
}

void ArrowheadRsuService::onRequest(const std_msgs::msg::String::SharedPtr msg)
{
    EV_INFO << "ArrowheadRsuService forwarding request for: " << msg->data << " to CloudNode\n";

    if (mCloudNode) {
        mCloudNode->handleRequest(msg->data);
    }
}

void ArrowheadRsuService::indicate(
    const vanetza::btp::DataIndication&,
    omnetpp::cPacket* packet,
    const NetworkInterface&)
{
    Enter_Method("indicate");
    delete packet;
}

void ArrowheadRsuService::trigger()
{
    Enter_Method("trigger");
}

} // namespace artery
