import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument,IncludeLaunchDescription, OpaqueFunction
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch.launch_context import LaunchContext

def include_launch_description(context: LaunchContext):

    main_pkg_dir = get_package_share_directory('gazebo_nodes')
    omnet_pkg_dir = get_package_share_directory('omnet')	
    # Paths to folders and files
    launch_file_dir = os.path.join(main_pkg_dir, 'launch')

    use_sim_time = LaunchConfiguration('use_sim_time')

    nav2_pkg_dir = get_package_share_directory('nav2')
    map_file = os.path.join(nav2_pkg_dir, 'maps', 'small_road', 'map.yaml'),
    params_file = os.path.join(nav2_pkg_dir, 'config', 'nav2_params', 'small_road','nav2_params_central.yaml')
    nav_launch_file_dir = os.path.join(nav2_pkg_dir, 'launch')

    launch_descriptions = []
    for index in range(5):
        launch_descriptions.append(
            IncludeLaunchDescription(
                PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'central_start.launch.py')),
                launch_arguments={
                    'use_sim_time': use_sim_time,
                    'namespace': f'central{index}',
                    'name': f'central{index}',
                    'x_pose': str(90 + index),
                    'y_pose': '-3.12',
                    'z_pose': '0.55',
                    'r_orientation': '0.0',
                    'p_orientation': '0.0',
                    'y_orientation': '0.0'
                }.items(),
            )
        )
        launch_descriptions.append(
            Node(
                package='omnet',
                executable='omnet_transmitter',
                name='omnet_transmitter',
                namespace=f'central{index}',
                arguments={f'central{index}'},
                output='screen'
            )
        )
    return launch_descriptions

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

    

    # Launch Description
    launch_description = LaunchDescription()
    launch_description.add_action(use_sim_time_arg)

    launch_description.add_action(OpaqueFunction(function=include_launch_description))


    return launch_description
