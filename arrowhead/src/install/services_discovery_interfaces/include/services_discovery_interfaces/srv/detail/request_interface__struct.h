// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from services_discovery_interfaces:srv/RequestInterface.idl
// generated code does not contain a copyright notice

#ifndef SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__STRUCT_H_
#define SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'services_to_look_for'
// Member 'json_base_configuration'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/RequestInterface in the package services_discovery_interfaces.
typedef struct services_discovery_interfaces__srv__RequestInterface_Request
{
  rosidl_runtime_c__String__Sequence services_to_look_for;
  rosidl_runtime_c__String json_base_configuration;
} services_discovery_interfaces__srv__RequestInterface_Request;

// Struct for a sequence of services_discovery_interfaces__srv__RequestInterface_Request.
typedef struct services_discovery_interfaces__srv__RequestInterface_Request__Sequence
{
  services_discovery_interfaces__srv__RequestInterface_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} services_discovery_interfaces__srv__RequestInterface_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'services_found'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/RequestInterface in the package services_discovery_interfaces.
typedef struct services_discovery_interfaces__srv__RequestInterface_Response
{
  rosidl_runtime_c__String__Sequence services_found;
} services_discovery_interfaces__srv__RequestInterface_Response;

// Struct for a sequence of services_discovery_interfaces__srv__RequestInterface_Response.
typedef struct services_discovery_interfaces__srv__RequestInterface_Response__Sequence
{
  services_discovery_interfaces__srv__RequestInterface_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} services_discovery_interfaces__srv__RequestInterface_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__STRUCT_H_
