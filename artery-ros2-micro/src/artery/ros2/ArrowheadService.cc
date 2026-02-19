#include "artery/ros2/ArrowheadService.h"

#include <omnetpp/cpacket.h>

#include <vanetza/btp/data_request.hpp>
#include <vanetza/dcc/profile.hpp>
#include <vanetza/geonet/interface.hpp>

#include <inet/common/ModuleAccess.h>
#include <inet/common/geometry/common/CanvasProjection.h>
#include <inet/common/geometry/common/CoordinateSystem.h>
#include <inet/features.h>

#include <ros2/RobotObject.h>
#include <ros2/ServiceObject.h>

using namespace omnetpp;
using namespace vanetza;

namespace artery
{

/* signal emitted by ArrowheadRobotInetMobility */
static const simsignal_t serviceRegistryUpdatedSignal =
    cComponent::registerSignal("serviceRegistryUpdatedSignal");

Define_Module(ArrowheadService);

ArrowheadService::ArrowheadService()
    : rosNode(Ros2Node::getInstance())
{
}

ArrowheadService::~ArrowheadService()
{
    cancelAndDelete(m_self_msg);
}

void ArrowheadService::indicate(
    const btp::DataIndication& ind,
    cPacket* packet,
    const NetworkInterface& net)
{
    Enter_Method("indicate");

    EV_INFO << "ArrowheadService received ITS-G5 packet on channel "
            << net.channel << "\n";

    delete packet;
}


void ArrowheadService::initialize()
{
    ItsG5Service::initialize();

    EV_INFO << "Initializing ArrowheadService\n";

    m_self_msg = new cMessage("ArrowheadServiceSelfMsg");

    /* Subscribe to ServiceObject signal */
    subscribe(serviceRegistryUpdatedSignal);

    /* Optional periodic self event */
    scheduleAt(simTime() + 1.0, m_self_msg);

    /* Optional coordinate system (only if needed later) */
    if (hasPar("coordinateSystemModule"))
        mCoordinateSystem =
            inet::getModuleFromPar<inet::IGeographicCoordinateSystem>(
                par("coordinateSystemModule"), this);

    /* Create ROS publisher */

    auto& robot = getFacilities().getConst<ros2::RobotObject>();
    std::string robotId = robot.getId();

    std::string topic = robotId + "/arrowhead/service_registry";

    publisher =
        rosNode.getRosNode()->create_publisher<
            arrowhead_msgs::msg::ServiceRegistration>(topic, 10);

    EV_INFO << "ArrowheadService publishing to topic: " << topic << "\n";
}

void ArrowheadService::finish()
{
    ItsG5Service::finish();
}

void ArrowheadService::handleMessage(cMessage* msg)
{
    Enter_Method("handleMessage");

    if (msg == m_self_msg) {
        EV_INFO << "ArrowheadService self-message triggered\n";

        /* Reschedule if periodic behaviour desired */
        scheduleAt(simTime() + 5.0, m_self_msg);
    }
}


void ArrowheadService::trigger()
{
    Enter_Method("trigger");

    /* Example test packet transmission (same as Ros2Service) */

    static const vanetza::ItsAid exampleAid = 16480;

    auto& mco = getFacilities().get_const<MultiChannelPolicy>();
    auto& networks = getFacilities().get_const<NetworkInterfaceTable>();

    for (auto channel : mco.allChannels(exampleAid)) {

        auto network = networks.select(channel);

        if (!network) {
            EV_ERROR << "No network interface for channel "
                     << channel << "\n";
            continue;
        }

        btp::DataRequestB req;

        req.destination_port = host_cast(getPortNumber(channel));
        req.gn.transport_type = geonet::TransportType::SHB;
        req.gn.traffic_class.tc_id(
            static_cast<unsigned>(dcc::Profile::DP3));
        req.gn.communication_profile =
            geonet::CommunicationProfile::ITS_G5;
        req.gn.its_aid = exampleAid;

        cPacket* packet = new cPacket("ArrowheadTestPacket");
        packet->setByteLength(64);

        request(req, packet, network.get());
    }
}

void ArrowheadService::receiveSignal(
    cComponent* source,
    simsignal_t signal,
    cObject* object,
    cObject* details)
{
    Enter_Method("receiveSignal");

    /* We expect a ServiceObject from mobility */

    auto* service = dynamic_cast<ros2::ServiceObject*>(object);

    if (!service) {
        EV_WARN << "ArrowheadService received unknown signal object\n";
        return;
    }

    EV_INFO << "ArrowheadService received ServiceObject, converting to ROS msg\n";

    arrowhead_msgs::msg::ServiceRegistration msg;

    /* Top-level fields */

    msg.service_validation = service->getServiceValidation();
    msg.server_addrport    = service->getServerAddrPort();

    /* ServiceData */

    msg.service_data.service_definition =
        service->getServiceDefinition();

    msg.service_data.service_uri =
        service->getServiceURI();

    msg.service_data.version =
        service->getVersion();

    msg.service_data.secure =
        service->getSecure();

    msg.service_data.interfaces =
        service->getInterfaces();

    /* Metadata */

    msg.service_data.metadata.highway_name =
        service->getHighwayName();

    msg.service_data.metadata.entrance_number =
        service->getEntranceNumber();

    /* ProviderSystem */

    msg.service_data.provider_system.system_name =
        service->getSystemName();

    msg.service_data.provider_system.address =
        service->getAddress();

    msg.service_data.provider_system.port =
        service->getPort();

    msg.service_data.provider_system.authentication_info =
        service->getAuthenticationInfo();

    /* Publish to ROS */

    publisher->publish(msg);

    EV_INFO << "ArrowheadService published ServiceRegistration to ROS\n";
}

} // namespace artery
