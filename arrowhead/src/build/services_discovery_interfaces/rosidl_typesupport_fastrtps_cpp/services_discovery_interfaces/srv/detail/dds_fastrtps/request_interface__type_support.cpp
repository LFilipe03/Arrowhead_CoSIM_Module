// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from services_discovery_interfaces:srv/RequestInterface.idl
// generated code does not contain a copyright notice
#include "services_discovery_interfaces/srv/detail/request_interface__rosidl_typesupport_fastrtps_cpp.hpp"
#include "services_discovery_interfaces/srv/detail/request_interface__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace services_discovery_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_services_discovery_interfaces
cdr_serialize(
  const services_discovery_interfaces::srv::RequestInterface_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: services_to_look_for
  {
    cdr << ros_message.services_to_look_for;
  }
  // Member: json_base_configuration
  cdr << ros_message.json_base_configuration;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_services_discovery_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  services_discovery_interfaces::srv::RequestInterface_Request & ros_message)
{
  // Member: services_to_look_for
  {
    cdr >> ros_message.services_to_look_for;
  }

  // Member: json_base_configuration
  cdr >> ros_message.json_base_configuration;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_services_discovery_interfaces
get_serialized_size(
  const services_discovery_interfaces::srv::RequestInterface_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: services_to_look_for
  {
    size_t array_size = ros_message.services_to_look_for.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.services_to_look_for[index].size() + 1);
    }
  }
  // Member: json_base_configuration
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.json_base_configuration.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_services_discovery_interfaces
max_serialized_size_RequestInterface_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: services_to_look_for
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

  // Member: json_base_configuration
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

static bool _RequestInterface_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const services_discovery_interfaces::srv::RequestInterface_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RequestInterface_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<services_discovery_interfaces::srv::RequestInterface_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RequestInterface_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const services_discovery_interfaces::srv::RequestInterface_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RequestInterface_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_RequestInterface_Request(full_bounded, 0);
}

static message_type_support_callbacks_t _RequestInterface_Request__callbacks = {
  "services_discovery_interfaces::srv",
  "RequestInterface_Request",
  _RequestInterface_Request__cdr_serialize,
  _RequestInterface_Request__cdr_deserialize,
  _RequestInterface_Request__get_serialized_size,
  _RequestInterface_Request__max_serialized_size
};

static rosidl_message_type_support_t _RequestInterface_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RequestInterface_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace services_discovery_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_services_discovery_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<services_discovery_interfaces::srv::RequestInterface_Request>()
{
  return &services_discovery_interfaces::srv::typesupport_fastrtps_cpp::_RequestInterface_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, services_discovery_interfaces, srv, RequestInterface_Request)() {
  return &services_discovery_interfaces::srv::typesupport_fastrtps_cpp::_RequestInterface_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace services_discovery_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_services_discovery_interfaces
cdr_serialize(
  const services_discovery_interfaces::srv::RequestInterface_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: services_found
  {
    cdr << ros_message.services_found;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_services_discovery_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  services_discovery_interfaces::srv::RequestInterface_Response & ros_message)
{
  // Member: services_found
  {
    cdr >> ros_message.services_found;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_services_discovery_interfaces
get_serialized_size(
  const services_discovery_interfaces::srv::RequestInterface_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: services_found
  {
    size_t array_size = ros_message.services_found.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.services_found[index].size() + 1);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_services_discovery_interfaces
max_serialized_size_RequestInterface_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: services_found
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

static bool _RequestInterface_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const services_discovery_interfaces::srv::RequestInterface_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RequestInterface_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<services_discovery_interfaces::srv::RequestInterface_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RequestInterface_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const services_discovery_interfaces::srv::RequestInterface_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RequestInterface_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_RequestInterface_Response(full_bounded, 0);
}

static message_type_support_callbacks_t _RequestInterface_Response__callbacks = {
  "services_discovery_interfaces::srv",
  "RequestInterface_Response",
  _RequestInterface_Response__cdr_serialize,
  _RequestInterface_Response__cdr_deserialize,
  _RequestInterface_Response__get_serialized_size,
  _RequestInterface_Response__max_serialized_size
};

static rosidl_message_type_support_t _RequestInterface_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RequestInterface_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace services_discovery_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_services_discovery_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<services_discovery_interfaces::srv::RequestInterface_Response>()
{
  return &services_discovery_interfaces::srv::typesupport_fastrtps_cpp::_RequestInterface_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, services_discovery_interfaces, srv, RequestInterface_Response)() {
  return &services_discovery_interfaces::srv::typesupport_fastrtps_cpp::_RequestInterface_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace services_discovery_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _RequestInterface__callbacks = {
  "services_discovery_interfaces::srv",
  "RequestInterface",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, services_discovery_interfaces, srv, RequestInterface_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, services_discovery_interfaces, srv, RequestInterface_Response)(),
};

static rosidl_service_type_support_t _RequestInterface__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RequestInterface__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace services_discovery_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_services_discovery_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<services_discovery_interfaces::srv::RequestInterface>()
{
  return &services_discovery_interfaces::srv::typesupport_fastrtps_cpp::_RequestInterface__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, services_discovery_interfaces, srv, RequestInterface)() {
  return &services_discovery_interfaces::srv::typesupport_fastrtps_cpp::_RequestInterface__handle;
}

#ifdef __cplusplus
}
#endif
