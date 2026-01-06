// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from services_discovery_interfaces:srv/RequestInterface.idl
// generated code does not contain a copyright notice

#ifndef SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__STRUCT_HPP_
#define SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__services_discovery_interfaces__srv__RequestInterface_Request __attribute__((deprecated))
#else
# define DEPRECATED__services_discovery_interfaces__srv__RequestInterface_Request __declspec(deprecated)
#endif

namespace services_discovery_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RequestInterface_Request_
{
  using Type = RequestInterface_Request_<ContainerAllocator>;

  explicit RequestInterface_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->json_base_configuration = "";
    }
  }

  explicit RequestInterface_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : json_base_configuration(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->json_base_configuration = "";
    }
  }

  // field types and members
  using _services_to_look_for_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _services_to_look_for_type services_to_look_for;
  using _json_base_configuration_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _json_base_configuration_type json_base_configuration;

  // setters for named parameter idiom
  Type & set__services_to_look_for(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->services_to_look_for = _arg;
    return *this;
  }
  Type & set__json_base_configuration(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->json_base_configuration = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__services_discovery_interfaces__srv__RequestInterface_Request
    std::shared_ptr<services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__services_discovery_interfaces__srv__RequestInterface_Request
    std::shared_ptr<services_discovery_interfaces::srv::RequestInterface_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RequestInterface_Request_ & other) const
  {
    if (this->services_to_look_for != other.services_to_look_for) {
      return false;
    }
    if (this->json_base_configuration != other.json_base_configuration) {
      return false;
    }
    return true;
  }
  bool operator!=(const RequestInterface_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RequestInterface_Request_

// alias to use template instance with default allocator
using RequestInterface_Request =
  services_discovery_interfaces::srv::RequestInterface_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace services_discovery_interfaces


#ifndef _WIN32
# define DEPRECATED__services_discovery_interfaces__srv__RequestInterface_Response __attribute__((deprecated))
#else
# define DEPRECATED__services_discovery_interfaces__srv__RequestInterface_Response __declspec(deprecated)
#endif

namespace services_discovery_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct RequestInterface_Response_
{
  using Type = RequestInterface_Response_<ContainerAllocator>;

  explicit RequestInterface_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit RequestInterface_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _services_found_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _services_found_type services_found;

  // setters for named parameter idiom
  Type & set__services_found(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->services_found = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__services_discovery_interfaces__srv__RequestInterface_Response
    std::shared_ptr<services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__services_discovery_interfaces__srv__RequestInterface_Response
    std::shared_ptr<services_discovery_interfaces::srv::RequestInterface_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const RequestInterface_Response_ & other) const
  {
    if (this->services_found != other.services_found) {
      return false;
    }
    return true;
  }
  bool operator!=(const RequestInterface_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct RequestInterface_Response_

// alias to use template instance with default allocator
using RequestInterface_Response =
  services_discovery_interfaces::srv::RequestInterface_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace services_discovery_interfaces

namespace services_discovery_interfaces
{

namespace srv
{

struct RequestInterface
{
  using Request = services_discovery_interfaces::srv::RequestInterface_Request;
  using Response = services_discovery_interfaces::srv::RequestInterface_Response;
};

}  // namespace srv

}  // namespace services_discovery_interfaces

#endif  // SERVICES_DISCOVERY_INTERFACES__SRV__DETAIL__REQUEST_INTERFACE__STRUCT_HPP_
