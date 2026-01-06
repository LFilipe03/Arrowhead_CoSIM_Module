import os
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource


def generate_launch_description():
    """Return launch description"""
    
    testing_cmd = Node(
            package="gazebo_nodes",
            executable="actor_position_time.py",
            name="actor_position_time",
            output="screen",
            parameters=[{'use_sim_time': True}]
    )

    #testing_cmd = Node(
    #        package="gazebo_nodes",
    #        executable="testing_node",
    #        name="testing_node",
    #        output="screen"
    #)
	
    #microrosid_cmd = Node(
    #        package="gazebo_nodes",
    #        executable="microros_id",
    #        name="microros_id",
    #        output="screen"
    #)
	
    # Launch Description
    launch_description = LaunchDescription()

    launch_description.add_action(testing_cmd)
    #launch_description.add_action(microrosid_cmd)

    return launch_description
