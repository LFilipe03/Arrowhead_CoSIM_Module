// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from services_registry_interfaces:srv/RegistrationInterface.idl
// generated code does not contain a copyright notice
#include "services_registry_interfaces/srv/detail/registration_interface__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "services_registry_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "services_registry_interfaces/srv/detail/registration_interface__struct.h"
#include "services_registry_interfaces/srv/detail/registration_interface__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // method, registration_data_json
#include "rosidl_runtime_c/string_functions.h"  // method, registration_data_json

// forward declare type support functions


using _RegistrationInterface_Request__ros_msg_type = services_registry_interfaces__srv__RegistrationInterface_Request;

static bool _RegistrationInterface_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RegistrationInterface_Request__ros_msg_type * ros_message = static_cast<const _RegistrationInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: registration_data_json
  {
    const rosidl_runtime_c__String * str = &ros_message->registration_data_json;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: service_id_with_update
  {
    cdr << ros_message->service_id_with_update;
  }

  // Field name: method
  {
    const rosidl_runtime_c__String * str = &ros_message->method;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _RegistrationInterface_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RegistrationInterface_Request__ros_msg_type * ros_message = static_cast<_RegistrationInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: registration_data_json
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->registration_data_json.data) {
      rosidl_runtime_c__String__init(&ros_message->registration_data_json);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->registration_data_json,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'registration_data_json'\n");
      return false;
    }
  }

  // Field name: service_id_with_update
  {
    cdr >> ros_message->service_id_with_update;
  }

  // Field name: method
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->method.data) {
      rosidl_runtime_c__String__init(&ros_message->method);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->method,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'method'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_services_registry_interfaces
size_t get_serialized_size_services_registry_interfaces__srv__RegistrationInterface_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RegistrationInterface_Request__ros_msg_type * ros_message = static_cast<const _RegistrationInterface_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name registration_data_json
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->registration_data_json.size + 1);
  // field.name service_id_with_update
  {
    size_t item_size = sizeof(ros_message->service_id_with_update);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name method
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->method.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _RegistrationInterface_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_services_registry_interfaces__srv__RegistrationInterface_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_services_registry_interfaces
size_t max_serialized_size_services_registry_interfaces__srv__RegistrationInterface_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: registration_data_json
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: service_id_with_update
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: method
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _RegistrationInterface_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_services_registry_interfaces__srv__RegistrationInterface_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_RegistrationInterface_Request = {
  "services_registry_interfaces::srv",
  "RegistrationInterface_Request",
  _RegistrationInterface_Request__cdr_serialize,
  _RegistrationInterface_Request__cdr_deserialize,
  _RegistrationInterface_Request__get_serialized_size,
  _RegistrationInterface_Request__max_serialized_size
};

static rosidl_message_type_support_t _RegistrationInterface_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RegistrationInterface_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, services_registry_interfaces, srv, RegistrationInterface_Request)() {
  return &_RegistrationInterface_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "services_registry_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__struct.h"
// already included above
// #include "services_registry_interfaces/srv/detail/registration_interface__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _RegistrationInterface_Response__ros_msg_type = services_registry_interfaces__srv__RegistrationInterface_Response;

static bool _RegistrationInterface_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RegistrationInterface_Response__ros_msg_type * ros_message = static_cast<const _RegistrationInterface_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: value_returned
  {
    cdr << ros_message->value_returned;
  }

  return true;
}

static bool _RegistrationInterface_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RegistrationInterface_Response__ros_msg_type * ros_message = static_cast<_RegistrationInterface_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: value_returned
  {
    cdr >> ros_message->value_returned;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_services_registry_interfaces
size_t get_serialized_size_services_registry_interfaces__srv__RegistrationInterface_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RegistrationInterface_Response__ros_msg_type * ros_message = static_cast<const _RegistrationInterface_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name value_returned
  {
    size_t item_size = sizeof(ros_message->value_returned);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RegistrationInterface_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_services_registry_interfaces__srv__RegistrationInterface_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_services_registry_interfaces
size_t max_serialized_size_services_registry_interfaces__srv__RegistrationInterface_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: value_returned
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _RegistrationInterface_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_services_registry_interfaces__srv__RegistrationInterface_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_RegistrationInterface_Response = {
  "services_registry_interfaces::srv",
  "RegistrationInterface_Response",
  _RegistrationInterface_Response__cdr_serialize,
  _RegistrationInterface_Response__cdr_deserialize,
  _RegistrationInterface_Response__get_serialized_size,
  _RegistrationInterface_Response__max_serialized_size
};

static rosidl_message_type_support_t _RegistrationInterface_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RegistrationInterface_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, services_registry_interfaces, srv, RegistrationInterface_Response)() {
  return &_RegistrationInterface_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "services_registry_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "services_registry_interfaces/srv/registration_interface.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t RegistrationInterface__callbacks = {
  "services_registry_interfaces::srv",
  "RegistrationInterface",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, services_registry_interfaces, srv, RegistrationInterface_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, services_registry_interfaces, srv, RegistrationInterface_Response)(),
};

static rosidl_service_type_support_t RegistrationInterface__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &RegistrationInterface__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, services_registry_interfaces, srv, RegistrationInterface)() {
  return &RegistrationInterface__handle;
}

#if defined(__cplusplus)
}
#endif
