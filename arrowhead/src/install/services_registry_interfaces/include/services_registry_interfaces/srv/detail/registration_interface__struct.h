// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from services_registry_interfaces:srv/RegistrationInterface.idl
// generated code does not contain a copyright notice

#ifndef SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__STRUCT_H_
#define SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'registration_data_json'
// Member 'method'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/RegistrationInterface in the package services_registry_interfaces.
typedef struct services_registry_interfaces__srv__RegistrationInterface_Request
{
  rosidl_runtime_c__String registration_data_json;
  int32_t service_id_with_update;
  rosidl_runtime_c__String method;
} services_registry_interfaces__srv__RegistrationInterface_Request;

// Struct for a sequence of services_registry_interfaces__srv__RegistrationInterface_Request.
typedef struct services_registry_interfaces__srv__RegistrationInterface_Request__Sequence
{
  services_registry_interfaces__srv__RegistrationInterface_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} services_registry_interfaces__srv__RegistrationInterface_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/RegistrationInterface in the package services_registry_interfaces.
typedef struct services_registry_interfaces__srv__RegistrationInterface_Response
{
  int32_t value_returned;
} services_registry_interfaces__srv__RegistrationInterface_Response;

// Struct for a sequence of services_registry_interfaces__srv__RegistrationInterface_Response.
typedef struct services_registry_interfaces__srv__RegistrationInterface_Response__Sequence
{
  services_registry_interfaces__srv__RegistrationInterface_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} services_registry_interfaces__srv__RegistrationInterface_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__STRUCT_H_
