import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument,IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration

def generate_launch_description():

    # Package Directories
    main_pkg_dir = get_package_share_directory('gazebo_nodes')
    omnet_pkg_dir = get_package_share_directory('omnet')	
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
    prius_launch_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'prius_start.launch.py')),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'namespace': 'prius',
            'world_name': 'small_city_2',
            'name': 'prius',
            'x_pose': '30.98', #30.98
            'y_pose': '-1.6',
            'z_pose': '0.06',
            'r_orientation': '0.0',
            'p_orientation': '0.0',
            'y_orientation': '0.004'
        }.items(),
    )

    # Nodes and other launch files
    omnet_transmitter_cmd = Node(
            package='omnet',
            executable='omnet_transmitter',
            name='omnet_transmitter',
            namespace='prius',
            arguments={'prius'},
            output='screen'
    )


    # Configuration for Navigation
    nav2_pkg_dir = get_package_share_directory('nav2')
    map_file = os.path.join(nav2_pkg_dir, 'maps', 'small_city', 'map.yaml'),
    params_file = os.path.join(nav2_pkg_dir, 'config', 'nav2_params', 'small_city','nav2_params_prius.yaml')
    nav_launch_file_dir = os.path.join(nav2_pkg_dir, 'launch')
    navigation_prius_cmd = IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(nav_launch_file_dir, 'navigation_prius.launch.py')),
                launch_arguments={
                'map': map_file,
                'params_file': params_file,
                'namespace': 'prius'
            }.items(),
    )    

    # Launch Description
    launch_description = LaunchDescription()
    launch_description.add_action(use_sim_time_arg)

    launch_description.add_action(prius_launch_cmd)
    launch_description.add_action(navigation_prius_cmd)

    launch_description.add_action(omnet_transmitter_cmd)

    return launch_description
