cmake_minimum_required(VERSION 3.8)
project(cpp_pubsub)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(services_registry_interfaces REQUIRED)
find_package(GTest REQUIRED)

include_directories(include/cpp_pubsub)

set(CURL_INCLUDE_DIR "/usr/include/x86_64-linux-gnu")
set(CURL_LIBRARY "/usr/lib/x86_64-linux-gnu/libcurl.so")
include_directories(${CURL_INCLUDE_DIR})

add_executable(police src/PoliceRun.cpp src/PoliceService.cpp src/RegistrationRequester.cpp)
target_link_libraries(police ${CURL_LIBRARY})
ament_target_dependencies(police rclcpp std_msgs services_registry_interfaces)

add_executable(traffic src/TrafficRun.cpp src/TrafficService.cpp src/RegistrationRequester.cpp)
target_link_libraries(traffic ${CURL_LIBRARY})
ament_target_dependencies(traffic rclcpp std_msgs services_registry_interfaces)


# Adicione o Google Test
enable_testing()
include_directories(${GTEST_INCLUDE_DIRS})

# Adicione o executável de teste
add_executable(test_police test/PoliceTest.cpp src/PoliceService.cpp src/RegistrationRequester.cpp)
ament_target_dependencies(test_police rclcpp std_msgs services_registry_interfaces GTest)

target_link_libraries(test_police ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} pthread)

# Adicione o teste ao CMake
add_test(NAME PoliceTest COMMAND test_police)

install(TARGETS
        police
        traffic
        test_police
        DESTINATION lib/${PROJECT_NAME})

ament_package()