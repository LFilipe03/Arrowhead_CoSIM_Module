#include <ros2/ServiceObject.h>
#include <omnetpp.h>
#include <limits>

namespace ros2
{

Register_Abstract_Class(ServiceObject)

ServiceObject::ServiceObject() :
    m_service_validation(0),
    m_server_addrport(""),
    m_service_definition(""),
    m_service_uri(""),
    m_version(0),
    m_secure(""),
    m_interfaces(),
    m_highway_name(""),
    m_entrance_number(-1),
    m_system_name(""),
    m_address(""),
    m_port(0),
    m_authentication_info("")
{
}

} // namespace ros2
