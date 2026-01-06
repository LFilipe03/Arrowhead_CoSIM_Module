// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from services_discovery_interfaces:srv/RequestInterface.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "services_discovery_interfaces/srv/detail/request_interface__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace services_discovery_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void RequestInterface_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) services_discovery_interfaces::srv::RequestInterface_Request(_init);
}

void RequestInterface_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<services_discovery_interfaces::srv::RequestInterface_Request *>(message_memory);
  typed_message->~RequestInterface_Request();
}

size_t size_function__RequestInterface_Request__services_to_look_for(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RequestInterface_Request__services_to_look_for(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__RequestInterface_Request__services_to_look_for(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void resize_function__RequestInterface_Request__services_to_look_for(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RequestInterface_Request_message_member_array[2] = {
  {
    "services_to_look_for",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_discovery_interfaces::srv::RequestInterface_Request, services_to_look_for),  // bytes offset in struct
    nullptr,  // default value
    size_function__RequestInterface_Request__services_to_look_for,  // size() function pointer
    get_const_function__RequestInterface_Request__services_to_look_for,  // get_const(index) function pointer
    get_function__RequestInterface_Request__services_to_look_for,  // get(index) function pointer
    resize_function__RequestInterface_Request__services_to_look_for  // resize(index) function pointer
  },
  {
    "json_base_configuration",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_discovery_interfaces::srv::RequestInterface_Request, json_base_configuration),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RequestInterface_Request_message_members = {
  "services_discovery_interfaces::srv",  // message namespace
  "RequestInterface_Request",  // message name
  2,  // number of fields
  sizeof(services_discovery_interfaces::srv::RequestInterface_Request),
  RequestInterface_Request_message_member_array,  // message members
  RequestInterface_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  RequestInterface_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RequestInterface_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RequestInterface_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace services_discovery_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<services_discovery_interfaces::srv::RequestInterface_Request>()
{
  return &::services_discovery_interfaces::srv::rosidl_typesupport_introspection_cpp::RequestInterface_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, services_discovery_interfaces, srv, RequestInterface_Request)() {
  return &::services_discovery_interfaces::srv::rosidl_typesupport_introspection_cpp::RequestInterface_Request_message_type_support_handle;
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
// #include "services_discovery_interfaces/srv/detail/request_interface__struct.hpp"
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

namespace services_discovery_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void RequestInterface_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) services_discovery_interfaces::srv::RequestInterface_Response(_init);
}

void RequestInterface_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<services_discovery_interfaces::srv::RequestInterface_Response *>(message_memory);
  typed_message->~RequestInterface_Response();
}

size_t size_function__RequestInterface_Response__services_found(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__RequestInterface_Response__services_found(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__RequestInterface_Response__services_found(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void resize_function__RequestInterface_Response__services_found(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember RequestInterface_Response_message_member_array[1] = {
  {
    "services_found",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_discovery_interfaces::srv::RequestInterface_Response, services_found),  // bytes offset in struct
    nullptr,  // default value
    size_function__RequestInterface_Response__services_found,  // size() function pointer
    get_const_function__RequestInterface_Response__services_found,  // get_const(index) function pointer
    get_function__RequestInterface_Response__services_found,  // get(index) function pointer
    resize_function__RequestInterface_Response__services_found  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers RequestInterface_Response_message_members = {
  "services_discovery_interfaces::srv",  // message namespace
  "RequestInterface_Response",  // message name
  1,  // number of fields
  sizeof(services_discovery_interfaces::srv::RequestInterface_Response),
  RequestInterface_Response_message_member_array,  // message members
  RequestInterface_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  RequestInterface_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t RequestInterface_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RequestInterface_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace services_discovery_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<services_discovery_interfaces::srv::RequestInterface_Response>()
{
  return &::services_discovery_interfaces::srv::rosidl_typesupport_introspection_cpp::RequestInterface_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, services_discovery_interfaces, srv, RequestInterface_Response)() {
  return &::services_discovery_interfaces::srv::rosidl_typesupport_introspection_cpp::RequestInterface_Response_message_type_support_handle;
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
// #include "services_discovery_interfaces/srv/detail/request_interface__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace services_discovery_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers RequestInterface_service_members = {
  "services_discovery_interfaces::srv",  // service namespace
  "RequestInterface",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<services_discovery_interfaces::srv::RequestInterface>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t RequestInterface_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &RequestInterface_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace services_discovery_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<services_discovery_interfaces::srv::RequestInterface>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::services_discovery_interfaces::srv::rosidl_typesupport_introspection_cpp::RequestInterface_service_type_support_handle;
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
        ::services_discovery_interfaces::srv::RequestInterface_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::services_discovery_interfaces::srv::RequestInterface_Response
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
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, services_discovery_interfaces, srv, RequestInterface)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<services_discovery_interfaces::srv::RequestInterface>();
}

#ifdef __cplusplus
}
#endif
