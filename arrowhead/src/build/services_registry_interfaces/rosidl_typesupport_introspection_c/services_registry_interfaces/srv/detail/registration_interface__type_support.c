// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from services_registry_interfaces:srv/RegistrationInterface.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "services_registry_interfaces/srv/detail/registration_interface__rosidl_typesupport_introspection_c.h"
#include "services_registry_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "services_registry_interfaces/srv/detail/registration_interface__functions.h"
#include "services_registry_interfaces/srv/detail/registration_interface__struct.h"


// Include directives for member types
// Member `registration_data_json`
// Member `method`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  services_registry_interfaces__srv__RegistrationInterface_Request__init(message_memory);
}

void RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_fini_function(void * message_memory)
{
  services_registry_interfaces__srv__RegistrationInterface_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_message_member_array[3] = {
  {
    "registration_data_json",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_registry_interfaces__srv__RegistrationInterface_Request, registration_data_json),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "service_id_with_update",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_registry_interfaces__srv__RegistrationInterface_Request, service_id_with_update),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "method",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_registry_interfaces__srv__RegistrationInterface_Request, method),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_message_members = {
  "services_registry_interfaces__srv",  // message namespace
  "RegistrationInterface_Request",  // message name
  3,  // number of fields
  sizeof(services_registry_interfaces__srv__RegistrationInterface_Request),
  RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_message_member_array,  // message members
  RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_message_type_support_handle = {
  0,
  &RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_services_registry_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_registry_interfaces, srv, RegistrationInterface_Request)() {
  if (!RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_message_type_support_handle.typesupport_identifier) {
    RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &RegistrationInterface_Request__rosidl_typesupport_introspection_c__RegistrationInterface_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__rosidl_typesupport_introspection_c.h"
// already included above
// #include "services_registry_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__functions.h"
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  services_registry_interfaces__srv__RegistrationInterface_Response__init(message_memory);
}

void RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_fini_function(void * message_memory)
{
  services_registry_interfaces__srv__RegistrationInterface_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_message_member_array[1] = {
  {
    "value_returned",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(services_registry_interfaces__srv__RegistrationInterface_Response, value_returned),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_message_members = {
  "services_registry_interfaces__srv",  // message namespace
  "RegistrationInterface_Response",  // message name
  1,  // number of fields
  sizeof(services_registry_interfaces__srv__RegistrationInterface_Response),
  RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_message_member_array,  // message members
  RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_message_type_support_handle = {
  0,
  &RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_services_registry_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_registry_interfaces, srv, RegistrationInterface_Response)() {
  if (!RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_message_type_support_handle.typesupport_identifier) {
    RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &RegistrationInterface_Response__rosidl_typesupport_introspection_c__RegistrationInterface_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "services_registry_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers services_registry_interfaces__srv__detail__registration_interface__rosidl_typesupport_introspection_c__RegistrationInterface_service_members = {
  "services_registry_interfaces__srv",  // service namespace
  "RegistrationInterface",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // services_registry_interfaces__srv__detail__registration_interface__rosidl_typesupport_introspection_c__RegistrationInterface_Request_message_type_support_handle,
  NULL  // response message
  // services_registry_interfaces__srv__detail__registration_interface__rosidl_typesupport_introspection_c__RegistrationInterface_Response_message_type_support_handle
};

static rosidl_service_type_support_t services_registry_interfaces__srv__detail__registration_interface__rosidl_typesupport_introspection_c__RegistrationInterface_service_type_support_handle = {
  0,
  &services_registry_interfaces__srv__detail__registration_interface__rosidl_typesupport_introspection_c__RegistrationInterface_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_registry_interfaces, srv, RegistrationInterface_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_registry_interfaces, srv, RegistrationInterface_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_services_registry_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_registry_interfaces, srv, RegistrationInterface)() {
  if (!services_registry_interfaces__srv__detail__registration_interface__rosidl_typesupport_introspection_c__RegistrationInterface_service_type_support_handle.typesupport_identifier) {
    services_registry_interfaces__srv__detail__registration_interface__rosidl_typesupport_introspection_c__RegistrationInterface_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)services_registry_interfaces__srv__detail__registration_interface__rosidl_typesupport_introspection_c__RegistrationInterface_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_registry_interfaces, srv, RegistrationInterface_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, services_registry_interfaces, srv, RegistrationInterface_Response)()->data;
  }

  return &services_registry_interfaces__srv__detail__registration_interface__rosidl_typesupport_introspection_c__RegistrationInterface_service_type_support_handle;
}
