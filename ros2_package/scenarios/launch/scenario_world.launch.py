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
    # Paths to folders and files
    launch_file_dir = os.path.join(main_pkg_dir, 'launch')
    omnet_launch_file_dir = os.path.join(omnet_pkg_dir, 'launch')

    use_sim_time = LaunchConfiguration('use_sim_time')


    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation (Gazebo) clock if true'
    )

    world_launch_arg = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'world_gazebo_start.launch.py')),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'namespace': 'world',
            'name': 'world',
            'world_name': 'highway',
        }.items(),
    )


    # Configuration for Navigation
    nav2_pkg_dir = get_package_share_directory('nav2')
    map_file = os.path.join(nav2_pkg_dir, 'maps', 'small_road', 'map.yaml'),
    params_file = os.path.join(nav2_pkg_dir, 'config', 'nav2_params', 'small_road','nav2_params_prius.yaml')
    nav_launch_file_dir = os.path.join(nav2_pkg_dir, 'launch')
    """
    navigation_prius_cmd = IncludeLaunchDescription(
            PythonLaunchDescriptionSource(os.path.join(nav_launch_file_dir, 'navigation_prius.launch.py')),
                launch_arguments={
                'map': map_file,
                'params_file': params_file,
                'namespace': 'prius'
            }.items(),
    )    
    """
    # Launch Description
    launch_description = LaunchDescription()
    launch_description.add_action(use_sim_time_arg)
    launch_description.add_action(world_launch_arg)


    return launch_description