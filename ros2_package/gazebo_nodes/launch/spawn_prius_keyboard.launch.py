"""Spawn prius launch file"""

"""

import os

from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument


def generate_launch_description():ls

    
    # Launch Argument Configurations
    name = LaunchConfiguration('name')
    namespace = LaunchConfiguration('namespace')
    x_pose = LaunchConfiguration('x_pose')
    y_pose = LaunchConfiguration('y_pose')
    z_pose = LaunchConfiguration('z_pose')
    r_orientation = LaunchConfiguration('r_orientation')
    p_orientation = LaunchConfiguration('p_orientation')
    y_orientation = LaunchConfiguration('y_orientation')

    # Launch Arguments
    name_arg = DeclareLaunchArgument(
        'name',
        default_value='',
        description='Gazebo robot object name'
    )
    namespace_arg = DeclareLaunchArgument(
        'namespace',
        default_value='',
        description='ROS2 robot namespace'
    )
    x_pose_arg = DeclareLaunchArgument(
        'x_position',
        default_value='0.0',
        description='Robot spawn x position'
    )
    y_pose_arg = DeclareLaunchArgument(
        'y_position',
        default_value='0.0',
        description='Robot spawn y position'
    )
    z_pose_arg = DeclareLaunchArgument(
        'z_position',
        default_value='0.0',
        description='Robot spawn z position'
    )
    r_orientation_arg = DeclareLaunchArgument(
        'r_orientation',
        default_value='0.0',
        description='Robot spawn r orientation angle'
    )
    p_orientation_arg = DeclareLaunchArgument(
        'p_orientation',
        default_value='0.0',
        description='Robot spawn p orientation angle'
    )
    y_orientation_arg = DeclareLaunchArgument(
        'y_orientation',
        default_value='0.0',
        description='Robot spawn y orientation angle'
    )
    
    urdf_file_name = "prius_keyboard.urdf"
    urdf_path = os.path.join(
        get_package_share_directory("prius_description"),
        "urdf", urdf_file_name
    )


    # Nodes and other launch files
    start_gazebo_ros_spawner_cmd = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        name='spawn_entity',
        namespace=namespace,
        output='screen',
        arguments=[
            '-entity', name,
            '-topic', 'robot_description',
            '-x', x_pose,
            '-y', y_pose,
            '-z', z_pose,
            '-R', r_orientation,
            '-P', p_orientation,
            '-Y', y_orientation,
            '-robot_namespace', namespace,
        ]
    )

    # Launch Description
    launch_description = LaunchDescription()

    launch_description.add_action(name_arg)
    launch_description.add_action(namespace_arg)
    launch_description.add_action(x_pose_arg)
    launch_description.add_action(y_pose_arg)
    launch_description.add_action(z_pose_arg)
    launch_description.add_action(r_orientation_arg)
    launch_description.add_action(p_orientation_arg)
    launch_description.add_action(y_orientation_arg)

    launch_description.add_action(start_gazebo_ros_spawner_cmd)

    return launch_description

"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, TextSubstitution
from launch_ros.actions import Node


def generate_launch_description():
    # Get the urdf file
    urdf_file_name = "prius_keyboard.urdf"
    urdf_path = os.path.join(
        get_package_share_directory("prius_description"),
        "urdf", urdf_file_name
    )

    poses = {
        "0": {"x": 0.0, "y": 7.1, "z": 0.0, "Z": 0.0},
        "1": {"x": 0.0, "y": 7.1, "z": 0.0, "Z": 0.0},
    }
    # Launch configuration variables specific to simulation
    x_pose = LaunchConfiguration('x_pose', default='0.0')
    y_pose = LaunchConfiguration('y_pose', default='0.0')
    pose = LaunchConfiguration("pose", default="0")
    
    # Declare the launch arguments
    declare_x_position_cmd = DeclareLaunchArgument(
        'x_pose', default_value='0.0',
        description='Specify namespace of the robot')

    declare_y_position_cmd = DeclareLaunchArgument(
        'y_pose', default_value='0.0',
        description='Specify namespace of the robot')

    declare_pose_cmd = DeclareLaunchArgument(
        "pose", default_value="0", description="Spawn Pose"
    )

    start_gazebo_ros_spawner_cmd = Node(
        package='gazebo_ros',
        executable='spawn_entity.py',
        arguments=[
            '-file', urdf_path,
            '-x', TextSubstitution(text=str(poses["1"]["x"])),
            '-y', TextSubstitution(text=str(poses["1"]["y"])),
            '-z', TextSubstitution(text=str(poses["1"]["z"])),
            # '-x', x_pose,
            # '-y', y_pose,
            # '-z', 0.5,
            "-entity", "prius_keyboard"
        ],
        output='screen',
    )

    ld = LaunchDescription()

    # Declare the launch options for file
    ld.add_action(declare_x_position_cmd)
    ld.add_action(declare_y_position_cmd)
    ld.add_action(declare_pose_cmd)
    # Add any conditioned actions
    ld.add_action(start_gazebo_ros_spawner_cmd)

    return ld
