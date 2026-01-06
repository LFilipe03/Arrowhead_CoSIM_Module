// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from services_discovery_interfaces:srv/RequestInterface.idl
// generated code does not contain a copyright notice

#ifndef SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__TRAITS_HPP_
#define SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__TRAITS_HPP_

#include "services_discovery_interfaces/srv/detail/request_interface__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const services_discovery_interfaces::srv::RequestInterface_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: services_to_look_for
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.services_to_look_for.size() == 0) {
      out << "services_to_look_for: []\n";
    } else {
      out << "services_to_look_for:\n";
      for (auto item : msg.services_to_look_for) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: json_base_configuration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "json_base_configuration: ";
    value_to_yaml(msg.json_base_configuration, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const services_discovery_interfaces::srv::RequestInterface_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<services_discovery_interfaces::srv::RequestInterface_Request>()
{
  return "services_discovery_interfaces::srv::RequestInterface_Request";
}

template<>
inline const char * name<services_discovery_interfaces::srv::RequestInterface_Request>()
{
  return "services_discovery_interfaces/srv/RequestInterface_Request";
}

template<>
struct has_fixed_size<services_discovery_interfaces::srv::RequestInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<services_discovery_interfaces::srv::RequestInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<services_discovery_interfaces::srv::RequestInterface_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const services_discovery_interfaces::srv::RequestInterface_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: services_found
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.services_found.size() == 0) {
      out << "services_found: []\n";
    } else {
      out << "services_found:\n";
      for (auto item : msg.services_found) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const services_discovery_interfaces::srv::RequestInterface_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<services_discovery_interfaces::srv::RequestInterface_Response>()
{
  return "services_discovery_interfaces::srv::RequestInterface_Response";
}

template<>
inline const char * name<services_discovery_interfaces::srv::RequestInterface_Response>()
{
  return "services_discovery_interfaces/srv/RequestInterface_Response";
}

template<>
struct has_fixed_size<services_discovery_interfaces::srv::RequestInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<services_discovery_interfaces::srv::RequestInterface_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<services_discovery_interfaces::srv::RequestInterface_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<services_discovery_interfaces::srv::RequestInterface>()
{
  return "services_discovery_interfaces::srv::RequestInterface";
}

template<>
inline const char * name<services_discovery_interfaces::srv::RequestInterface>()
{
  return "services_discovery_interfaces/srv/RequestInterface";
}

template<>
struct has_fixed_size<services_discovery_interfaces::srv::RequestInterface>
  : std::integral_constant<
    bool,
    has_fixed_size<services_discovery_interfaces::srv::RequestInterface_Request>::value &&
    has_fixed_size<services_discovery_interfaces::srv::RequestInterface_Response>::value
  >
{
};

template<>
struct has_bounded_size<services_discovery_interfaces::srv::RequestInterface>
  : std::integral_constant<
    bool,
    has_bounded_size<services_discovery_interfaces::srv::RequestInterface_Request>::value &&
    has_bounded_size<services_discovery_interfaces::srv::RequestInterface_Response>::value
  >
{
};

template<>
struct is_service<services_discovery_interfaces::srv::RequestInterface>
  : std::true_type
{
};

template<>
struct is_service_request<services_discovery_interfaces::srv::RequestInterface_Request>
  : std::true_type
{
};

template<>
struct is_service_response<services_discovery_interfaces::srv::RequestInterface_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__TRAITS_HPP_
