// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from services_discovery_interfaces:srv/RequestInterface.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "services_discovery_interfaces/srv/detail/request_interface__rosidl_typesupport_introspection_c.h"
#include "services_discovery_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "services_discovery_interfaces/srv/detail/request_interface__functions.h"
#include "services_discovery_interfaces/srv/detail/request_interface__struct.h"


// Include directives for member types
// Member `services_to_look_for`
// Member `json_base_configuration`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  services_discovery_interfaces__srv__RequestInterface_Request__init(message_memory);
}

void RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_fini_function(void * message_memory)
{
  services_discovery_interfaces__srv__RequestInterface_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_message_member_array[2] = {
  {
    "services_to_look_for",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_discovery_interfaces__srv__RequestInterface_Request, services_to_look_for),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "json_base_configuration",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_discovery_interfaces__srv__RequestInterface_Request, json_base_configuration),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_message_members = {
  "services_discovery_interfaces__srv",  // message namespace
  "RequestInterface_Request",  // message name
  2,  // number of fields
  sizeof(services_discovery_interfaces__srv__RequestInterface_Request),
  RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_message_member_array,  // message members
  RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_message_type_support_handle = {
  0,
  &RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_services_discovery_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_discovery_interfaces, srv, RequestInterface_Request)() {
  if (!RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_message_type_support_handle.typesupport_identifier) {
    RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &RequestInterface_Request__rosidl_typesupport_introspection_c__RequestInterface_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "services_discovery_interfaces/srv/detail/request_interface__rosidl_typesupport_introspection_c.h"
// already included above
// #include "services_discovery_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "services_discovery_interfaces/srv/detail/request_interface__functions.h"
// already included above
// #include "services_discovery_interfaces/srv/detail/request_interface__struct.h"


// Include directives for member types
// Member `services_found`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  services_discovery_interfaces__srv__RequestInterface_Response__init(message_memory);
}

void RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_fini_function(void * message_memory)
{
  services_discovery_interfaces__srv__RequestInterface_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_message_member_array[1] = {
  {
    "services_found",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_discovery_interfaces__srv__RequestInterface_Response, services_found),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_message_members = {
  "services_discovery_interfaces__srv",  // message namespace
  "RequestInterface_Response",  // message name
  1,  // number of fields
  sizeof(services_discovery_interfaces__srv__RequestInterface_Response),
  RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_message_member_array,  // message members
  RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_message_type_support_handle = {
  0,
  &RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_services_discovery_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_discovery_interfaces, srv, RequestInterface_Response)() {
  if (!RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_message_type_support_handle.typesupport_identifier) {
    RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &RequestInterface_Response__rosidl_typesupport_introspection_c__RequestInterface_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "services_discovery_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "services_discovery_interfaces/srv/detail/request_interface__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers services_discovery_interfaces__srv__detail__request_interface__rosidl_typesupport_introspection_c__RequestInterface_service_members = {
  "services_discovery_interfaces__srv",  // service namespace
  "RequestInterface",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // services_discovery_interfaces__srv__detail__request_interface__rosidl_typesupport_introspection_c__RequestInterface_Request_message_type_support_handle,
  NULL  // response message
  // services_discovery_interfaces__srv__detail__request_interface__rosidl_typesupport_introspection_c__RequestInterface_Response_message_type_support_handle
};

static rosidl_service_type_support_t services_discovery_interfaces__srv__detail__request_interface__rosidl_typesupport_introspection_c__RequestInterface_service_type_support_handle = {
  0,
  &services_discovery_interfaces__srv__detail__request_interface__rosidl_typesupport_introspection_c__RequestInterface_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_discovery_interfaces, srv, RequestInterface_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_discovery_interfaces, srv, RequestInterface_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_services_discovery_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_discovery_interfaces, srv, RequestInterface)() {
  if (!services_discovery_interfaces__srv__detail__request_interface__rosidl_typesupport_introspection_c__RequestInterface_service_type_support_handle.typesupport_identifier) {
    services_discovery_interfaces__srv__detail__request_interface__rosidl_typesupport_introspection_c__RequestInterface_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)services_discovery_interfaces__srv__detail__request_interface__rosidl_typesupport_introspection_c__RequestInterface_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_discovery_interfaces, srv, RequestInterface_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_discovery_interfaces, srv, RequestInterface_Response)()->data;
  }

  return &services_discovery_interfaces__srv__detail__request_interface__rosidl_typesupport_introspection_c__RequestInterface_service_type_support_handle;
}
