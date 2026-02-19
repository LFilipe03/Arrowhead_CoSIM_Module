#ifndef ROS2_SERVICESINK_H_2RZI4UCS
#define ROS2_SERVICESINK_H_2RZI4UCS

#include "ros2/ServiceObject.h"

namespace ros2
{

class ServiceSink
{
public:
    virtual void initialize(const ServiceObject&) = 0;
    //virtual void update(const ServiceObject&) = 0;
    virtual ~ServiceSink() = default;
};

} // namespace ros2

#endif /* ROS2_SERVICESINK_H_2RZI4UCS */
