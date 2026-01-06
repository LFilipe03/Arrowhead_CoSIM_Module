// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from services_registry_interfaces:srv/RegistrationInterface.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "services_registry_interfaces/srv/detail/registration_interface__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace services_registry_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void RegistrationInterface_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) services_registry_interfaces::srv::RegistrationInterface_Request(_init);
}

void RegistrationInterface_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<services_registry_interfaces::srv::RegistrationInterface_Request *>(message_memory);
  typed_message->~RegistrationInterface_Request();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RegistrationInterface_Request_message_member_array[3] = {
  {
    "registration_data_json",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_registry_interfaces::srv::RegistrationInterface_Request, registration_data_json),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "service_id_with_update",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_registry_interfaces::srv::RegistrationInterface_Request, service_id_with_update),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "method",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_registry_interfaces::srv::RegistrationInterface_Request, method),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RegistrationInterface_Request_message_members = {
  "services_registry_interfaces::srv",  // message namespace
  "RegistrationInterface_Request",  // message name
  3,  // number of fields
  sizeof(services_registry_interfaces::srv::RegistrationInterface_Request),
  RegistrationInterface_Request_message_member_array,  // message members
  RegistrationInterface_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  RegistrationInterface_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RegistrationInterface_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RegistrationInterface_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace services_registry_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<services_registry_interfaces::srv::RegistrationInterface_Request>()
{
  return &::services_registry_interfaces::srv::rosidl_typesupport_introspection_cpp::RegistrationInterface_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, services_registry_interfaces, srv, RegistrationInterface_Request)() {
  return &::services_registry_interfaces::srv::rosidl_typesupport_introspection_cpp::RegistrationInterface_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace services_registry_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void RegistrationInterface_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) services_registry_interfaces::srv::RegistrationInterface_Response(_init);
}

void RegistrationInterface_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<services_registry_interfaces::srv::RegistrationInterface_Response *>(message_memory);
  typed_message->~RegistrationInterface_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RegistrationInterface_Response_message_member_array[1] = {
  {
    "value_returned",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_registry_interfaces::srv::RegistrationInterface_Response, value_returned),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RegistrationInterface_Response_message_members = {
  "services_registry_interfaces::srv",  // message namespace
  "RegistrationInterface_Response",  // message name
  1,  // number of fields
  sizeof(services_registry_interfaces::srv::RegistrationInterface_Response),
  RegistrationInterface_Response_message_member_array,  // message members
  RegistrationInterface_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  RegistrationInterface_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RegistrationInterface_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RegistrationInterface_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace services_registry_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<services_registry_interfaces::srv::RegistrationInterface_Response>()
{
  return &::services_registry_interfaces::srv::rosidl_typesupport_introspection_cpp::RegistrationInterface_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, services_registry_interfaces, srv, RegistrationInterface_Response)() {
  return &::services_registry_interfaces::srv::rosidl_typesupport_introspection_cpp::RegistrationInterface_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace services_registry_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers RegistrationInterface_service_members = {
  "services_registry_interfaces::srv",  // service namespace
  "RegistrationInterface",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<services_registry_interfaces::srv::RegistrationInterface>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t RegistrationInterface_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RegistrationInterface_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace services_registry_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<services_registry_interfaces::srv::RegistrationInterface>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::services_registry_interfaces::srv::rosidl_typesupport_introspection_cpp::RegistrationInterface_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::services_registry_interfaces::srv::RegistrationInterface_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::services_registry_interfaces::srv::RegistrationInterface_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, services_registry_interfaces, srv, RegistrationInterface)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<services_registry_interfaces::srv::RegistrationInterface>();
}

#ifdef __cplusplus
}
#endif
