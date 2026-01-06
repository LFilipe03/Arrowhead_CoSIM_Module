// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from services_discovery_interfaces:srv/RequestInterface.idl
// generated code does not contain a copyright notice
#include "services_discovery_interfaces/srv/detail/request_interface__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "services_discovery_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "services_discovery_interfaces/srv/detail/request_interface__struct.h"
#include "services_discovery_interfaces/srv/detail/request_interface__functions.h"
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

#include "rosidl_runtime_c/string.h"  // json_base_configuration, services_to_look_for
#include "rosidl_runtime_c/string_functions.h"  // json_base_configuration, services_to_look_for

// forward declare type support functions


using _RequestInterface_Request__ros_msg_type = services_discovery_interfaces__srv__RequestInterface_Request;

static bool _RequestInterface_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RequestInterface_Request__ros_msg_type * ros_message = static_cast<const _RequestInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: services_to_look_for
  {
    size_t size = ros_message->services_to_look_for.size;
    auto array_ptr = ros_message->services_to_look_for.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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
  }

  // Field name: json_base_configuration
  {
    const rosidl_runtime_c__String * str = &ros_message->json_base_configuration;
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

static bool _RequestInterface_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RequestInterface_Request__ros_msg_type * ros_message = static_cast<_RequestInterface_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: services_to_look_for
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->services_to_look_for.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->services_to_look_for);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->services_to_look_for, size)) {
      fprintf(stderr, "failed to create array for field 'services_to_look_for'");
      return false;
    }
    auto array_ptr = ros_message->services_to_look_for.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'services_to_look_for'\n");
        return false;
      }
    }
  }

  // Field name: json_base_configuration
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->json_base_configuration.data) {
      rosidl_runtime_c__String__init(&ros_message->json_base_configuration);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->json_base_configuration,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'json_base_configuration'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_services_discovery_interfaces
size_t get_serialized_size_services_discovery_interfaces__srv__RequestInterface_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RequestInterface_Request__ros_msg_type * ros_message = static_cast<const _RequestInterface_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name services_to_look_for
  {
    size_t array_size = ros_message->services_to_look_for.size;
    auto array_ptr = ros_message->services_to_look_for.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name json_base_configuration
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->json_base_configuration.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _RequestInterface_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_services_discovery_interfaces__srv__RequestInterface_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_services_discovery_interfaces
size_t max_serialized_size_services_discovery_interfaces__srv__RequestInterface_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: services_to_look_for
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: json_base_configuration
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

static size_t _RequestInterface_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_services_discovery_interfaces__srv__RequestInterface_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_RequestInterface_Request = {
  "services_discovery_interfaces::srv",
  "RequestInterface_Request",
  _RequestInterface_Request__cdr_serialize,
  _RequestInterface_Request__cdr_deserialize,
  _RequestInterface_Request__get_serialized_size,
  _RequestInterface_Request__max_serialized_size
};

static rosidl_message_type_support_t _RequestInterface_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RequestInterface_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, services_discovery_interfaces, srv, RequestInterface_Request)() {
  return &_RequestInterface_Request__type_support;
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
// #include "services_discovery_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "services_discovery_interfaces/srv/detail/request_interface__struct.h"
// already included above
// #include "services_discovery_interfaces/srv/detail/request_interface__functions.h"
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

// already included above
// #include "rosidl_runtime_c/string.h"  // services_found
// already included above
// #include "rosidl_runtime_c/string_functions.h"  // services_found

// forward declare type support functions


using _RequestInterface_Response__ros_msg_type = services_discovery_interfaces__srv__RequestInterface_Response;

static bool _RequestInterface_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _RequestInterface_Response__ros_msg_type * ros_message = static_cast<const _RequestInterface_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: services_found
  {
    size_t size = ros_message->services_found.size;
    auto array_ptr = ros_message->services_found.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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
  }

  return true;
}

static bool _RequestInterface_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _RequestInterface_Response__ros_msg_type * ros_message = static_cast<_RequestInterface_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: services_found
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->services_found.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->services_found);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->services_found, size)) {
      fprintf(stderr, "failed to create array for field 'services_found'");
      return false;
    }
    auto array_ptr = ros_message->services_found.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'services_found'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_services_discovery_interfaces
size_t get_serialized_size_services_discovery_interfaces__srv__RequestInterface_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _RequestInterface_Response__ros_msg_type * ros_message = static_cast<const _RequestInterface_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name services_found
  {
    size_t array_size = ros_message->services_found.size;
    auto array_ptr = ros_message->services_found.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _RequestInterface_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_services_discovery_interfaces__srv__RequestInterface_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_services_discovery_interfaces
size_t max_serialized_size_services_discovery_interfaces__srv__RequestInterface_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: services_found
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _RequestInterface_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_services_discovery_interfaces__srv__RequestInterface_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_RequestInterface_Response = {
  "services_discovery_interfaces::srv",
  "RequestInterface_Response",
  _RequestInterface_Response__cdr_serialize,
  _RequestInterface_Response__cdr_deserialize,
  _RequestInterface_Response__get_serialized_size,
  _RequestInterface_Response__max_serialized_size
};

static rosidl_message_type_support_t _RequestInterface_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_RequestInterface_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, services_discovery_interfaces, srv, RequestInterface_Response)() {
  return &_RequestInterface_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "services_discovery_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "services_discovery_interfaces/srv/request_interface.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t RequestInterface__callbacks = {
  "services_discovery_interfaces::srv",
  "RequestInterface",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, services_discovery_interfaces, srv, RequestInterface_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, services_discovery_interfaces, srv, RequestInterface_Response)(),
};

static rosidl_service_type_support_t RequestInterface__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &RequestInterface__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, services_discovery_interfaces, srv, RequestInterface)() {
  return &RequestInterface__handle;
}

#if defined(__cplusplus)
}
#endif
