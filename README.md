# Arrowhead_CoSIM_Module# Arrowhead_Integration_Module

## Contents

    artery-ros2-micro - Contains the OMNeT++/Artery distribution based on https://github.com/HarunTeper/artery
    micro_sensors - micro-ROS Zephyr App for the sensors
    ros2_package - The Core of the framework, a ROS2 package based on AuNa 
    arrowhead - Contains the services necessary that are gonna be provided by Arrowhead


## Requirements

    Arrowhead 4.6.2
    MySql Database 5.6.0+ 
    Java Runtime Environment

    The ROS2 package requires ROS2 Galactic, Gazebo 11 and a few other ros2 packages and dependencies, that can be installed with the following:

        sudo apt-get -y install python3-pip python3-colcon-common-extensions ros-galactic-xacro ros-galactic-rmw-cyclonedds-cpp ros-galactic-gazebo-ros-pkgs ros-galactic-navigation2 ros-galactic-nav2-bringup ros-galactic-libg2o
        sudo apt-get -y install libspnav-dev libasio-dev libbluetooth-dev libcwiid-dev libgeographic-dev


## Running
### Running the road detour scenario:

    ros2 launch scenarios scenario_prius_road_detour.launch.py - (Launches the Prius and the Gazebo Environment)
    ros2 launch scenarios scenario_central_road_detour.launch.py - (Spawns the RSU)
    ros2 launch scenarios scenario_sensors_road_detour.launch.py - (Spawns the Road Sensors)

### Running the micro-ROS nodes
With the correct micro-ROS ROS2 Galactic distribution working and the micro-ROS agent, the Zephyr App can be initialized with the following:

    ros2 run micro_ros_setup configure_firmware.sh micro_sensors --transport udp --ip 127.0.0.1 --port 8888
    ros2 run micro_ros_setup build_firmware.sh
    export ID=1;ros2 run micro_ros_setup flash_firmware.sh (The second sensor needs to be initialized in another console with ID=2)

### Building and running the OMNeT++ simulation:
 
 Source the ROS2 package with: 

    source ros2_package/install/setup.bash
     
Inside the artery-ros2-micro:

    mkdir build
    cd build
    cmake ..
    cmake -j 24 --build .
    or
    cmake --build . -j 8
    
Running the simulation:

    cmake --build build --target run_ros2_road_detour

     
    