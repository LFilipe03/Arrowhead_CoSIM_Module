import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration

def generate_launch_description():

    # Package Directories
    main_pkg_dir = get_package_share_directory('gazebo_nodes')
    omnet_pkg_dir = get_package_share_directory('omnet')	
    mapping_pkg_dir = get_package_share_directory('mapping')

    # Paths to folders and files
    launch_file_dir = os.path.join(main_pkg_dir, 'launch')
    omnet_launch_file_dir = os.path.join(omnet_pkg_dir, 'launch')

    use_sim_time = LaunchConfiguration('use_sim_time')


    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation (Gazebo) clock if true'
    )

        # Nodes and other launch files

    first_prius_launch_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'prius_mapping_start.launch.py')),
        launch_arguments={
            'name': 'prius',  # Change the name for the second Prius model
            'namespace': 'prius',  # Change the namespace for the second Prius model
            'x_pose': '0.0',  # Change the x position for the second Prius model
            'y_pose': '7.1',   # Change the y position for the second Prius model
            'z_pose': '0.2',   # Change the z position for the second Prius model
            'r_orientation': '0.0',  # Change the roll orientation for the second Prius model
            'p_orientation': '0.0',  # Change the pitch orientation for the second Prius model
            'y_orientation': '0.0',  # Change the yaw orientation for the second Prius model
        }.items(),
    )

    # Slam Node

    slam_node_cmd = Node(
        package='slam_toolbox',
        executable='sync_slam_toolbox_node',
        name='slam_toolbox',
        namespace='prius',
        output='screen',
        parameters=[{
            'use_sim_time': use_sim_time,
        }],
    )

    # Rviz Node

    rviz_node_cmd = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        namespace='prius',
        output='screen',
        arguments=['-d', os.path.join(mapping_pkg_dir, 'rviz', 'config_prius_mapping.rviz')]
    )


    
    # Launch Description
    launch_description = LaunchDescription()
    launch_description.add_action(use_sim_time_arg)

    launch_description.add_action(first_prius_launch_cmd)

    launch_description.add_action(slam_node_cmd)
    launch_description.add_action(rviz_node_cmd)

    return launch_description