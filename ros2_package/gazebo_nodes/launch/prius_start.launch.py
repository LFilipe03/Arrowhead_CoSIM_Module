"""Spawn in small road detour scenario world launch file"""

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

    # Package Directories
    pkg_dir = get_package_share_directory('gazebo_nodes')

    # Paths to folders and files
    launch_file_dir = os.path.join(pkg_dir, 'launch')

    # Launch Argument Configurations
    name = LaunchConfiguration('name')
    namespace = LaunchConfiguration('namespace')
    use_sim_time = LaunchConfiguration('use_sim_time')


    x_pose = LaunchConfiguration('x_pose')
    y_pose = LaunchConfiguration('y_pose')
    z_pose = LaunchConfiguration('z_pose')

    r_orientation = LaunchConfiguration('r_orientation')
    p_orientation = LaunchConfiguration('p_orientation')
    y_orientation = LaunchConfiguration('y_orientation')

    x_pose_arg = DeclareLaunchArgument(
        'x_pose',
        default_value='0.0',
        description='Robot spawn x position'
    )
    y_pose_arg = DeclareLaunchArgument(
        'y_pose',
        default_value='0.0',
        description='Robot spawn y position'
    )
    z_pose_arg = DeclareLaunchArgument(
        'z_pose',
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


    # Launch Argument Configurations
    world_name = LaunchConfiguration('world_name', default='')

    # Launch Arguments
    world_name_arg = DeclareLaunchArgument(
        'world_name',
        default_value='',
        description='Gazebo world file name'
    )

    # Launch Arguments
    name_arg = DeclareLaunchArgument(
        'name',
        default_value='prius',
        description='Robot name in Gazebo'
    )
    namespace_arg = DeclareLaunchArgument(
        'namespace',
        default_value='',
        description='Robot namespace for ROS nodes and topics'
    )
    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation (Gazebo) clock if true'
    )

    world_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'gazebo_world.launch.py')),
        launch_arguments={
            'world_name': world_name
        }.items(),
    )

    # Nodes and other launch files
    robot_state_publisher_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'prius_state.launch.py')),
        launch_arguments={'use_sim_time': use_sim_time, 'namespace': namespace}.items()
    )
    spawn_prius_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'spawn_prius.launch.py')),
        launch_arguments={'x_pose': x_pose, 'y_pose': y_pose, 'z_pose': z_pose, 'r_orientation': r_orientation, 'p_orientation': p_orientation, 'y_orientation': y_orientation,'namespace': namespace, 'name': name}.items()
    )
    
    localization_pose_cmd = Node(
        package='gazebo_nodes',
        executable='localization_pose',
        name='localization_pose',
        namespace=namespace,
        arguments={namespace},
        output='screen'
    )
    simulation_pose_cmd = Node(
        package='gazebo_nodes',
        executable='simulation_pose',
        name='simulation_pose',
        namespace=namespace,
        arguments={namespace},
        output='screen'
    )

    cam_receiver_cmd = Node(
        package='gazebo_nodes',
        executable='cam_receiver.py',
        name='cam_receiver',
        output='screen',
        parameters=[{'use_sim_time':use_sim_time}]
    )

    costmap_receiver_cmd = Node(
        package='gazebo_nodes',
        executable='costmap_receiver.py',
        name='costmap_receiver',
        output='screen'
    )

    global_tf_cmd = Node(
        package='gazebo_nodes',
        executable='global_tf',
        name='global_tf',
        output='screen',
    )

    # Launch Description
    launch_description = LaunchDescription()

    launch_description.add_action(world_name_arg)

    launch_description.add_action(world_cmd)
    launch_description.add_action(name_arg)
    launch_description.add_action(namespace_arg)
    launch_description.add_action(use_sim_time_arg)

    launch_description.add_action(x_pose_arg)
    launch_description.add_action(y_pose_arg)
    launch_description.add_action(z_pose_arg)
    launch_description.add_action(r_orientation_arg)
    launch_description.add_action(p_orientation_arg)
    launch_description.add_action(y_orientation_arg)

    launch_description.add_action(robot_state_publisher_cmd)
    launch_description.add_action(spawn_prius_cmd)
    launch_description.add_action(localization_pose_cmd)
    launch_description.add_action(simulation_pose_cmd)
    launch_description.add_action(cam_receiver_cmd)
    #launch_description.add_action(costmap_receiver_cmd)
    launch_description.add_action(global_tf_cmd)

    return launch_description
