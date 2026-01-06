// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from services_discovery_interfaces:srv/RequestInterface.idl
// generated code does not contain a copyright notice

#ifndef SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__BUILDER_HPP_
#define SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__BUILDER_HPP_

#include "services_discovery_interfaces/srv/detail/request_interface__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace services_discovery_interfaces
{

namespace srv
{

namespace builder
{

class Init_RequestInterface_Request_json_base_configuration
{
public:
  explicit Init_RequestInterface_Request_json_base_configuration(::services_discovery_interfaces::srv::RequestInterface_Request & msg)
  : msg_(msg)
  {}
  ::services_discovery_interfaces::srv::RequestInterface_Request json_base_configuration(::services_discovery_interfaces::srv::RequestInterface_Request::_json_base_configuration_type arg)
  {
    msg_.json_base_configuration = std::move(arg);
    return std::move(msg_);
  }

private:
  ::services_discovery_interfaces::srv::RequestInterface_Request msg_;
};

class Init_RequestInterface_Request_services_to_look_for
{
public:
  Init_RequestInterface_Request_services_to_look_for()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RequestInterface_Request_json_base_configuration services_to_look_for(::services_discovery_interfaces::srv::RequestInterface_Request::_services_to_look_for_type arg)
  {
    msg_.services_to_look_for = std::move(arg);
    return Init_RequestInterface_Request_json_base_configuration(msg_);
  }

private:
  ::services_discovery_interfaces::srv::RequestInterface_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::services_discovery_interfaces::srv::RequestInterface_Request>()
{
  return services_discovery_interfaces::srv::builder::Init_RequestInterface_Request_services_to_look_for();
}

}  // namespace services_discovery_interfaces


namespace services_discovery_interfaces
{

namespace srv
{

namespace builder
{

class Init_RequestInterface_Response_services_found
{
public:
  Init_RequestInterface_Response_services_found()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::services_discovery_interfaces::srv::RequestInterface_Response services_found(::services_discovery_interfaces::srv::RequestInterface_Response::_services_found_type arg)
  {
    msg_.services_found = std::move(arg);
    return std::move(msg_);
  }

private:
  ::services_discovery_interfaces::srv::RequestInterface_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::services_discovery_interfaces::srv::RequestInterface_Response>()
{
  return services_discovery_interfaces::srv::builder::Init_RequestInterface_Response_services_found();
}

}  // namespace services_discovery_interfaces

#endif  // SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__BUILDER_HPP_
