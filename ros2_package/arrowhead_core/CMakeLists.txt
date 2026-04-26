cmake_minimum_required(VERSION 3.8)
project(arrowhead_core)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(arrowhead_msgs REQUIRED)

add_executable(arrowhead_node src/arrowhead_node.cpp)

ament_target_dependencies(arrowhead_node
  rclcpp
  std_msgs
  arrowhead_msgs
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

install(TARGETS
  arrowhead_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
