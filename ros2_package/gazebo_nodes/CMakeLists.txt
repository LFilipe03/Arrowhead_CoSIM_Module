cmake_minimum_required(VERSION 3.5)
project(gazebo_nodes)

cmake_policy(SET CMP0148 OLD)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()



find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)

find_package(gazebo_dev REQUIRED)
find_package(gazebo_msgs REQUIRED)
find_package(gazebo_ros REQUIRED)

find_package(prius_msgs REQUIRED)

find_package(gazebo 11 REQUIRED)
find_package(ignition-math6 REQUIRED)
find_package(prius_description)

find_package(tf2_ros REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

find_package(micro_msgs REQUIRED)
find_package(micro_its_msgs REQUIRED)

find_package(tf2_ros REQUIRED)
find_package(tf2_kdl REQUIRED)

find_package(slam_toolbox REQUIRED)

link_directories(${gazebo_dev_LIBRARY_DIRS})

# Add libraries
add_library(gazebo_models_node SHARED src/gazebo_models/gazebo_models.cpp)
add_library(global_tf_node SHARED src/transformations/global_tf/global_tf.cpp)
add_library(localization_pose_node SHARED src/transformations/localization_pose/localization_pose.cpp)
add_library(simulation_pose_node SHARED src/transformations/simulation_pose/simulation_pose.cpp)

# Create Cpp executable
add_executable(gazebo_models src/gazebo_models/gazebo_models_main.cpp)
add_executable(global_tf src/transformations/global_tf/global_tf_main.cpp)
add_executable(localization_pose src/transformations/localization_pose/localization_pose_main.cpp)
add_executable(simulation_pose src/transformations/simulation_pose/simulation_pose_main.cpp)

# Include Cpp "include" directory
include_directories(include)

add_executable(sensor_tf_publisher src/sensor_tf_publisher.cpp)

add_executable(testing_node src/testing.cpp)

add_executable(sensor_reliable src/sensor_reliable.cpp)

add_executable(sonar_reliable src/sonar_reliable.cpp)

add_executable(microros_id src/microros_id.cpp)

# Target dependencies
set(gazebo_models_dependencies rclcpp std_msgs gazebo_msgs micro_msgs)
ament_target_dependencies(gazebo_models_node ${gazebo_models_dependencies})
ament_target_dependencies(gazebo_models ${gazebo_models_dependencies})
set(global_tf_dependencies rclcpp gazebo_msgs geometry_msgs tf2_ros tf2_kdl)
ament_target_dependencies(global_tf_node ${global_tf_dependencies})
ament_target_dependencies(global_tf ${global_tf_dependencies})
set(localization_pose_dependencies rclcpp std_msgs geometry_msgs nav_msgs tf2_ros tf2_kdl)
ament_target_dependencies(localization_pose_node ${localization_pose_dependencies})
ament_target_dependencies(localization_pose ${localization_pose_dependencies})
set(simulation_pose_dependencies rclcpp std_msgs geometry_msgs nav_msgs gazebo_msgs micro_its_msgs)
ament_target_dependencies(simulation_pose_node ${simulation_pose_dependencies})
ament_target_dependencies(simulation_pose ${simulation_pose_dependencies})


ament_target_dependencies(sensor_tf_publisher rclcpp tf2_ros geometry_msgs gazebo_msgs)

ament_target_dependencies(testing_node rclcpp sensor_msgs)
ament_target_dependencies(sensor_reliable rclcpp sensor_msgs)
ament_target_dependencies(sonar_reliable rclcpp sensor_msgs)
ament_target_dependencies(microros_id rclcpp)

# Link libraries
target_link_libraries(gazebo_models gazebo_models_node)
target_link_libraries(global_tf global_tf_node)
target_link_libraries(localization_pose localization_pose_node)
target_link_libraries(simulation_pose simulation_pose_node)


add_library(PriusHybridPlugin SHARED 
  plugins/PriusHybridPlugin.cc
)
target_include_directories(PriusHybridPlugin PUBLIC include ${GAZEBO_INCLUDE_DIRS} ${SDFormat_INCLUDE_DIRS})
ament_target_dependencies(PriusHybridPlugin
  "gazebo_dev"
  "gazebo_ros"
  "rclcpp"
  "prius_msgs"
)
ament_export_libraries(PriusHybridPlugin)

ament_export_include_directories(include)
ament_export_dependencies(ament_cmake)
ament_export_dependencies(ament_cmake_python)
ament_export_dependencies(rclcpp)
ament_export_dependencies(rclpy)
ament_export_dependencies(gazebo_dev)
ament_export_dependencies(gazebo_msgs)
ament_export_dependencies(gazebo_ros)
ament_export_dependencies(prius_msgs)

if(NOT WIN32)
  if(NOT APPLE)
    set(
      AMENT_CMAKE_ENVIRONMENT_HOOKS_DESC_gazebo_plugins
      "prepend-non-duplicate;LD_LIBRARY_PATH;${GAZEBO_PLUGIN_PATH}")
  else()
    set(
      AMENT_CMAKE_ENVIRONMENT_HOOKS_DESC_gazebo_plugins
      "prepend-non-duplicate;DYLD_LIBRARY_PATH;${GAZEBO_PLUGIN_PATH}")
  endif()
endif()
ament_environment_hooks("${CMAKE_CURRENT_SOURCE_DIR}/env-hooks/gazebo_plugins.sh.in")


install(TARGETS
  sensor_tf_publisher
  testing_node 
  sensor_reliable
  sonar_reliable
  microros_id
  DESTINATION lib/${PROJECT_NAME}
)


# Install the python module for this package
ament_python_install_package(${PROJECT_NAME})

# Install Python executables
install(PROGRAMS
  scripts/prius_teleop_keyboard.py
  scripts/joystick_translator.py
  src/costmap_receiver.py
  src/cam_receiver.py
  src/ocmessage_time.py
  src/microrosmessage_time.py
  src/actor_position_time.py
  src/velocity_publisher.py
  DESTINATION lib/${PROJECT_NAME}
)

# Install Cpp executables
install(TARGETS
  gazebo_models
  global_tf
  localization_pose
  simulation_pose
  DESTINATION lib/${PROJECT_NAME}
)

install(TARGETS 
  gazebo_models_node
  global_tf_node
  localization_pose_node
  simulation_pose_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
)

install(TARGETS 
  PriusHybridPlugin
  sensor_tf_publisher
  testing_node
  sensor_reliable
  sonar_reliable
  microros_id
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)


if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  find_package(ament_cmake_gtest REQUIRED)
  ament_add_gtest(PriusHybridPluginTest plugins/PriusHybridPlugin.cc)  # Need to link .cpp file under test
  target_include_directories(PriusHybridPluginTest PUBLIC plugins/)  # Need to specify directories in order to #include from them in the test
  ament_target_dependencies(PriusHybridPluginTest gazebo_dev gazebo_ros rclcpp prius_msgs)  # Gtest requires rclcpp to instantiate the Node

endif()


ament_package()

install(
  DIRECTORY launch models rviz worlds maps src
  DESTINATION share/${PROJECT_NAME}
)

install(TARGETS
    PriusHybridPlugin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)
