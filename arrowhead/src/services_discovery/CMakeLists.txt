cmake_minimum_required(VERSION 3.8)
project(services_discovery)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(services_discovery_interfaces REQUIRED)

include_directories(include/services_discovery)

set(CURL_INCLUDE_DIR "/usr/include/x86_64-linux-gnu")
set(CURL_LIBRARY "/usr/lib/x86_64-linux-gnu/libcurl.so")
include_directories(${CURL_INCLUDE_DIR})

add_executable(server src/DiscoveryRequestReceiver.cpp src/ServiceDiscover.cpp)
target_link_libraries(server ${CURL_LIBRARY})
ament_target_dependencies(server
rclcpp services_discovery_interfaces)

install(TARGETS
  server
  DESTINATION lib/${PROJECT_NAME})

ament_package()
