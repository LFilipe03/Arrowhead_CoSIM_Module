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
        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'spawn_prius_lite.launch.py')),
        launch_arguments={
            'name': 'prius_lite2',  # Change the name for the second Prius model
            'namespace': 'prius_lite',  # Change the namespace for the second Prius model
            'x_pose': '0.0',  # Change the x position for the second Prius model
            'y_pose': '7.1',   # Change the y position for the second Prius model
            'z_pose': '0.1',   # Change the z position for the second Prius model
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


    # Configuration for Navigation
    nav2_pkg_dir = get_package_share_directory('nav2')
    map_file = os.path.join(nav2_pkg_dir, 'maps', 'small_road', 'map.yaml'),
    params_file = os.path.join(nav2_pkg_dir, 'config', 'nav2_params', 'small_road','nav2_params_prius.yaml')
    nav_launch_file_dir = os.path.join(nav2_pkg_dir, 'launch')

    # Launch Description
    launch_description = LaunchDescription()
    launch_description.add_action(use_sim_time_arg)

    launch_description.add_action(first_prius_launch_cmd)
   
    #launch_description.add_action(navigation_prius_cmd)

    launch_description.add_action(omnet_transmitter_cmd)

    return launch_description