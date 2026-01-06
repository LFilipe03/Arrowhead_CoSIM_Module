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
    sensor1_launch_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'camera_start.launch.py')),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'namespace': 'camera',
            'name': 'camera',
            'x_pose': '153.25',
            'y_pose': '5.2',
            'z_pose': '6.0',
            'r_orientation': '-0.11',
            'p_orientation': '0.19',
            'y_orientation': '3.14'
        }.items(),
    )



    # Launch Description
    launch_description = LaunchDescription()
    launch_description.add_action(use_sim_time_arg)

    launch_description.add_action(sensor1_launch_cmd)
    #launch_description.add_action(sensor2_launch_cmd)

    return launch_description
