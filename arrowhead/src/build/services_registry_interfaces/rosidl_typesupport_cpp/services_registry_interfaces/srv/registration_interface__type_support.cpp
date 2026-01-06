// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from services_registry_interfaces:srv/RegistrationInterface.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "services_registry_interfaces/srv/detail/registration_interface__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace services_registry_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _RegistrationInterface_Request_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RegistrationInterface_Request_type_support_ids_t;

static const _RegistrationInterface_Request_type_support_ids_t _RegistrationInterface_Request_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _RegistrationInterface_Request_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RegistrationInterface_Request_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RegistrationInterface_Request_type_support_symbol_names_t _RegistrationInterface_Request_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, services_registry_interfaces, srv, RegistrationInterface_Request)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, services_registry_interfaces, srv, RegistrationInterface_Request)),
  }
};

typedef struct _RegistrationInterface_Request_type_support_data_t
{
  void * data[2];
} _RegistrationInterface_Request_type_support_data_t;

static _RegistrationInterface_Request_type_support_data_t _RegistrationInterface_Request_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RegistrationInterface_Request_message_typesupport_map = {
  2,
  "services_registry_interfaces",
  &_RegistrationInterface_Request_message_typesupport_ids.typesupport_identifier[0],
  &_RegistrationInterface_Request_message_typesupport_symbol_names.symbol_name[0],
  &_RegistrationInterface_Request_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t RegistrationInterface_Request_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RegistrationInterface_Request_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace services_registry_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<services_registry_interfaces::srv::RegistrationInterface_Request>()
{
  return &::services_registry_interfaces::srv::rosidl_typesupport_cpp::RegistrationInterface_Request_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, services_registry_interfaces, srv, RegistrationInterface_Request)() {
  return get_message_type_support_handle<services_registry_interfaces::srv::RegistrationInterface_Request>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace services_registry_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _RegistrationInterface_Response_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RegistrationInterface_Response_type_support_ids_t;

static const _RegistrationInterface_Response_type_support_ids_t _RegistrationInterface_Response_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _RegistrationInterface_Response_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RegistrationInterface_Response_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RegistrationInterface_Response_type_support_symbol_names_t _RegistrationInterface_Response_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, services_registry_interfaces, srv, RegistrationInterface_Response)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, services_registry_interfaces, srv, RegistrationInterface_Response)),
  }
};

typedef struct _RegistrationInterface_Response_type_support_data_t
{
  void * data[2];
} _RegistrationInterface_Response_type_support_data_t;

static _RegistrationInterface_Response_type_support_data_t _RegistrationInterface_Response_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RegistrationInterface_Response_message_typesupport_map = {
  2,
  "services_registry_interfaces",
  &_RegistrationInterface_Response_message_typesupport_ids.typesupport_identifier[0],
  &_RegistrationInterface_Response_message_typesupport_symbol_names.symbol_name[0],
  &_RegistrationInterface_Response_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t RegistrationInterface_Response_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RegistrationInterface_Response_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace services_registry_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<services_registry_interfaces::srv::RegistrationInterface_Response>()
{
  return &::services_registry_interfaces::srv::rosidl_typesupport_cpp::RegistrationInterface_Response_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, services_registry_interfaces, srv, RegistrationInterface_Response)() {
  return get_message_type_support_handle<services_registry_interfaces::srv::RegistrationInterface_Response>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp

// already included above
// #include "cstddef"
#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__struct.hpp"
// already included above
// #include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/service_type_support_dispatch.hpp"
// already included above
// #include "rosidl_typesupport_cpp/visibility_control.h"
// already included above
// #include "rosidl_typesupport_interface/macros.h"

namespace services_registry_interfaces
{

namespace srv
{

namespace rosidl_typesupport_cpp
{

typedef struct _RegistrationInterface_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _RegistrationInterface_type_support_ids_t;

static const _RegistrationInterface_type_support_ids_t _RegistrationInterface_service_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _RegistrationInterface_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _RegistrationInterface_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _RegistrationInterface_type_support_symbol_names_t _RegistrationInterface_service_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, services_registry_interfaces, srv, RegistrationInterface)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, services_registry_interfaces, srv, RegistrationInterface)),
  }
};

typedef struct _RegistrationInterface_type_support_data_t
{
  void * data[2];
} _RegistrationInterface_type_support_data_t;

static _RegistrationInterface_type_support_data_t _RegistrationInterface_service_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _RegistrationInterface_service_typesupport_map = {
  2,
  "services_registry_interfaces",
  &_RegistrationInterface_service_typesupport_ids.typesupport_identifier[0],
  &_RegistrationInterface_service_typesupport_symbol_names.symbol_name[0],
  &_RegistrationInterface_service_typesupport_data.data[0],
};

static const rosidl_service_type_support_t RegistrationInterface_service_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_RegistrationInterface_service_typesupport_map),
  ::rosidl_typesupport_cpp::get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace srv

}  // namespace services_registry_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<services_registry_interfaces::srv::RegistrationInterface>()
{
  return &::services_registry_interfaces::srv::rosidl_typesupport_cpp::RegistrationInterface_service_type_support_handle;
}

}  // namespace rosidl_typesupport_cpp
