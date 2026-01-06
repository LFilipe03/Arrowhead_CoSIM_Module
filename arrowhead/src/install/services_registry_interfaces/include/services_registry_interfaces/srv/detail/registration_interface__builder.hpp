// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from services_registry_interfaces:srv/RegistrationInterface.idl
// generated code does not contain a copyright notice

#ifndef SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__BUILDER_HPP_
#define SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__BUILDER_HPP_

#include "services_registry_interfaces/srv/detail/registration_interface__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace services_registry_interfaces
{

namespace srv
{

namespace builder
{

class Init_RegistrationInterface_Request_method
{
public:
  explicit Init_RegistrationInterface_Request_method(::services_registry_interfaces::srv::RegistrationInterface_Request & msg)
  : msg_(msg)
  {}
  ::services_registry_interfaces::srv::RegistrationInterface_Request method(::services_registry_interfaces::srv::RegistrationInterface_Request::_method_type arg)
  {
    msg_.method = std::move(arg);
    return std::move(msg_);
  }

private:
  ::services_registry_interfaces::srv::RegistrationInterface_Request msg_;
};

class Init_RegistrationInterface_Request_service_id_with_update
{
public:
  explicit Init_RegistrationInterface_Request_service_id_with_update(::services_registry_interfaces::srv::RegistrationInterface_Request & msg)
  : msg_(msg)
  {}
  Init_RegistrationInterface_Request_method service_id_with_update(::services_registry_interfaces::srv::RegistrationInterface_Request::_service_id_with_update_type arg)
  {
    msg_.service_id_with_update = std::move(arg);
    return Init_RegistrationInterface_Request_method(msg_);
  }

private:
  ::services_registry_interfaces::srv::RegistrationInterface_Request msg_;
};

class Init_RegistrationInterface_Request_registration_data_json
{
public:
  Init_RegistrationInterface_Request_registration_data_json()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RegistrationInterface_Request_service_id_with_update registration_data_json(::services_registry_interfaces::srv::RegistrationInterface_Request::_registration_data_json_type arg)
  {
    msg_.registration_data_json = std::move(arg);
    return Init_RegistrationInterface_Request_service_id_with_update(msg_);
  }

private:
  ::services_registry_interfaces::srv::RegistrationInterface_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::services_registry_interfaces::srv::RegistrationInterface_Request>()
{
  return services_registry_interfaces::srv::builder::Init_RegistrationInterface_Request_registration_data_json();
}

}  // namespace services_registry_interfaces


namespace services_registry_interfaces
{

namespace srv
{

namespace builder
{

class Init_RegistrationInterface_Response_value_returned
{
public:
  Init_RegistrationInterface_Response_value_returned()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::services_registry_interfaces::srv::RegistrationInterface_Response value_returned(::services_registry_interfaces::srv::RegistrationInterface_Response::_value_returned_type arg)
  {
    msg_.value_returned = std::move(arg);
    return std::move(msg_);
  }

private:
  ::services_registry_interfaces::srv::RegistrationInterface_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::services_registry_interfaces::srv::RegistrationInterface_Response>()
{
  return services_registry_interfaces::srv::builder::Init_RegistrationInterface_Response_value_returned();
}

}  // namespace services_registry_interfaces

#endif  // SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__BUILDER_HPP_
