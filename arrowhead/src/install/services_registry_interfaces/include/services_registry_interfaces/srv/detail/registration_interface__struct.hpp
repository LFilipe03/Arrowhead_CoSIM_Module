// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from services_registry_interfaces:srv/RegistrationInterface.idl
// generated code does not contain a copyright notice

#ifndef SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__STRUCT_HPP_
#define SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__services_registry_interfaces__srv__RegistrationInterface_Request __attribute__((deprecated))
#else
# define DEPRECATED__services_registry_interfaces__srv__RegistrationInterface_Request __declspec(deprecated)
#endif

namespace services_registry_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RegistrationInterface_Request_
{
  using Type = RegistrationInterface_Request_<ContainerAllocator>;

  explicit RegistrationInterface_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->registration_data_json = "";
      this->service_id_with_update = 0l;
      this->method = "";
    }
  }

  explicit RegistrationInterface_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : registration_data_json(_alloc),
    method(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->registration_data_json = "";
      this->service_id_with_update = 0l;
      this->method = "";
    }
  }

  // field types and members
  using _registration_data_json_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _registration_data_json_type registration_data_json;
  using _service_id_with_update_type =
    int32_t;
  _service_id_with_update_type service_id_with_update;
  using _method_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _method_type method;

  // setters for named parameter idiom
  Type & set__registration_data_json(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->registration_data_json = _arg;
    return *this;
  }
  Type & set__service_id_with_update(
    const int32_t & _arg)
  {
    this->service_id_with_update = _arg;
    return *this;
  }
  Type & set__method(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->method = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__services_registry_interfaces__srv__RegistrationInterface_Request
    std::shared_ptr<services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__services_registry_interfaces__srv__RegistrationInterface_Request
    std::shared_ptr<services_registry_interfaces::srv::RegistrationInterface_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RegistrationInterface_Request_ & other) const
  {
    if (this->registration_data_json != other.registration_data_json) {
      return false;
    }
    if (this->service_id_with_update != other.service_id_with_update) {
      return false;
    }
    if (this->method != other.method) {
      return false;
    }
    return true;
  }
  bool operator!=(const RegistrationInterface_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RegistrationInterface_Request_

// alias to use template instance with default allocator
using RegistrationInterface_Request =
  services_registry_interfaces::srv::RegistrationInterface_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace services_registry_interfaces


#ifndef _WIN32
# define DEPRECATED__services_registry_interfaces__srv__RegistrationInterface_Response __attribute__((deprecated))
#else
# define DEPRECATED__services_registry_interfaces__srv__RegistrationInterface_Response __declspec(deprecated)
#endif

namespace services_registry_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RegistrationInterface_Response_
{
  using Type = RegistrationInterface_Response_<ContainerAllocator>;

  explicit RegistrationInterface_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value_returned = 0l;
    }
  }

  explicit RegistrationInterface_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->value_returned = 0l;
    }
  }

  // field types and members
  using _value_returned_type =
    int32_t;
  _value_returned_type value_returned;

  // setters for named parameter idiom
  Type & set__value_returned(
    const int32_t & _arg)
  {
    this->value_returned = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__services_registry_interfaces__srv__RegistrationInterface_Response
    std::shared_ptr<services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__services_registry_interfaces__srv__RegistrationInterface_Response
    std::shared_ptr<services_registry_interfaces::srv::RegistrationInterface_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RegistrationInterface_Response_ & other) const
  {
    if (this->value_returned != other.value_returned) {
      return false;
    }
    return true;
  }
  bool operator!=(const RegistrationInterface_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RegistrationInterface_Response_

// alias to use template instance with default allocator
using RegistrationInterface_Response =
  services_registry_interfaces::srv::RegistrationInterface_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace services_registry_interfaces

namespace services_registry_interfaces
{

namespace srv
{

struct RegistrationInterface
{
  using Request = services_registry_interfaces::srv::RegistrationInterface_Request;
  using Response = services_registry_interfaces::srv::RegistrationInterface_Response;
};

}  // namespace srv

}  // namespace services_registry_interfaces

#endif  // SERVICES_REGISTRY_INTERFACES__SRV__DETAIL__REGISTRATION_INTERFACE__STRUCT_HPP_
