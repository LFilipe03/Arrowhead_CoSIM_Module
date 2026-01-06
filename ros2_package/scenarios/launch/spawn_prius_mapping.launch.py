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
    
    
       # Nodes and other launch files
    omnet_transmitter_cmd = Node(
            package='omnet',
            executable='omnet_transmitter',
            name='omnet_transmitter',
            namespace='prius',
            arguments={'prius'},
            output='screen'
    )

    slam_toolbox_cmd = Node(
        package='slam_toolbox',
        executable='sync_slam_toolbox_node',
        name='slam_toolbox',
        namespace='prius',
        output='screen',
        parameters=[{
            'use_sim_time': use_sim_time,
            'resolution': 0.05,
            'map_file_name': 'map',
            'yaml_filename': os.path.join(main_pkg_dir, 'maps', 'small_road', 'map.yaml'),
            'frame_id': 'map',
            'odom_frame_id': 'odom',
            'base_frame_id': 'base_link',
            'scan_topic': 'scan'
        }]
    )

    rviz_launch_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(nav_launch_file_dir, 'rviz_launch.py')),
        launch_arguments={
            'namespace': 'prius',
            'rviz_config': rviz_config,
            'use_namespace': 'prius',
        }.items(),
    )

    # Configuration for Navigation
    nav2_pkg_dir = get_package_share_directory('nav2')
    """
    map_file = os.path.join(nav2_pkg_dir, 'maps', 'small_road', 'map.yaml'),
    params_file = os.path.join(nav2_pkg_dir, 'config', 'nav2_params', 'small_road','nav2_params_prius.yaml')
    nav_launch_file_dir = os.path.join(nav2_pkg_dir, 'launch')

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

    launch_description.add_action(first_prius_launch_cmd)
   
    #launch_description.add_action(navigation_prius_cmd)

    launch_description.add_action(omnet_transmitter_cmd)

    return launch_description