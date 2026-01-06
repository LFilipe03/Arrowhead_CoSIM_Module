#!/usr/bin/env python3

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.conditions import IfCondition

def generate_launch_description():

    # Package Directories
    pkg_dir = get_package_share_directory('gazebo_nodes')

    # Paths to folders and files
    scripts_file_dir = os.path.join(pkg_dir, 'launch')

    # Define launch arguments
    move_forward_arg = LaunchConfiguration('move_forward_arg', default='true')

    return LaunchDescription([
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([os.path.join(scripts_file_dir, 'prius_move_forward.py')]),
            launch_arguments={'arg_name': move_forward_arg}.items()
        )
    ])