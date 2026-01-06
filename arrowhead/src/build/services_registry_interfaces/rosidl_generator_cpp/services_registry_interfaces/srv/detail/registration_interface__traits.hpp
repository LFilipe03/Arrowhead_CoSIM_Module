// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from services_registry_interfaces:srv/RegistrationInterface.idl
// generated code does not contain a copyright notice

#ifndef SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__TRAITS_HPP_
#define SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__TRAITS_HPP_

#include "services_registry_interfaces/srv/detail/registration_interface__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace rosidl_generator_traits
{

inline void to_yaml(
  const services_registry_interfaces::srv::RegistrationInterface_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: registration_data_json
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "registration_data_json: ";
    value_to_yaml(msg.registration_data_json, out);
    out << "\n";
  }

  // member: service_id_with_update
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "service_id_with_update: ";
    value_to_yaml(msg.service_id_with_update, out);
    out << "\n";
  }

  // member: method
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "method: ";
    value_to_yaml(msg.method, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const services_registry_interfaces::srv::RegistrationInterface_Request & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<services_registry_interfaces::srv::RegistrationInterface_Request>()
{
  return "services_registry_interfaces::srv::RegistrationInterface_Request";
}

template<>
inline const char * name<services_registry_interfaces::srv::RegistrationInterface_Request>()
{
  return "services_registry_interfaces/srv/RegistrationInterface_Request";
}

template<>
struct has_fixed_size<services_registry_interfaces::srv::RegistrationInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<services_registry_interfaces::srv::RegistrationInterface_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<services_registry_interfaces::srv::RegistrationInterface_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

inline void to_yaml(
  const services_registry_interfaces::srv::RegistrationInterface_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: value_returned
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "value_returned: ";
    value_to_yaml(msg.value_returned, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const services_registry_interfaces::srv::RegistrationInterface_Response & msg)
{
  std::ostringstream out;
  to_yaml(msg, out);
  return out.str();
}

template<>
inline const char * data_type<services_registry_interfaces::srv::RegistrationInterface_Response>()
{
  return "services_registry_interfaces::srv::RegistrationInterface_Response";
}

template<>
inline const char * name<services_registry_interfaces::srv::RegistrationInterface_Response>()
{
  return "services_registry_interfaces/srv/RegistrationInterface_Response";
}

template<>
struct has_fixed_size<services_registry_interfaces::srv::RegistrationInterface_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<services_registry_interfaces::srv::RegistrationInterface_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<services_registry_interfaces::srv::RegistrationInterface_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<services_registry_interfaces::srv::RegistrationInterface>()
{
  return "services_registry_interfaces::srv::RegistrationInterface";
}

template<>
inline const char * name<services_registry_interfaces::srv::RegistrationInterface>()
{
  return "services_registry_interfaces/srv/RegistrationInterface";
}

template<>
struct has_fixed_size<services_registry_interfaces::srv::RegistrationInterface>
  : std::integral_constant<
    bool,
    has_fixed_size<services_registry_interfaces::srv::RegistrationInterface_Request>::value &&
    has_fixed_size<services_registry_interfaces::srv::RegistrationInterface_Response>::value
  >
{
};

template<>
struct has_bounded_size<services_registry_interfaces::srv::RegistrationInterface>
  : std::integral_constant<
    bool,
    has_bounded_size<services_registry_interfaces::srv::RegistrationInterface_Request>::value &&
    has_bounded_size<services_registry_interfaces::srv::RegistrationInterface_Response>::value
  >
{
};

template<>
struct is_service<services_registry_interfaces::srv::RegistrationInterface>
  : std::true_type
{
};

template<>
struct is_service_request<services_registry_interfaces::srv::RegistrationInterface_Request>
  : std::true_type
{
};

template<>
struct is_service_response<services_registry_interfaces::srv::RegistrationInterface_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__TRAITS_HPP_
