#include <ros2/ServiceObject.h>
#include <limits>

namespace ros2
{

Register_Abstract_Class(ServiceObject)

ServiceObject::ServiceObject() :
    m_service_validation(0),
    m_version(0),
    m_port(0),
    m_entrance_number(0)
{
    // Default initialization
}

} // namespace ros2
