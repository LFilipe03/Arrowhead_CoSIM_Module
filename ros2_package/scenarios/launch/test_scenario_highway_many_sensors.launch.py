import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from time import sleep

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

    X = 85.0
    relative_X = -2.0

    # Spawn many sensors (25)
    """
    sensor_launch_cmd = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'sonar_sensor_start2.launch.py')),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'namespace': 'sonar_sensor1',
            'name': 'sonar_sensor1',
            'x_pose': '85.0',
            'y_pose': '9.0',
            'z_pose': '0.50',
            'r_orientation': '0.0',
            'p_orientation': '0.0',
            'y_orientation': '4.735',
            'relative_x_pose': '-2.0',
            'relative_y_pose': '-3.0',
            'relative_z_pose': '-0.5',
            'relative_r_orientation': '-1.548',
            'relative_p_orientation': '0.0',
            'relative_y_orientation': '0.0',
        }.items(),
    )
"""
    for i in range(1, 26):
        sensor_launch_cmd = IncludeLaunchDescription(  
            PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'sonar_sensor_start2.launch.py')),
            launch_arguments={
                'use_sim_time': use_sim_time,
                'namespace': 'sonar_sensor' + str(i),
                'name': 'sonar_sensor' + str(i),
                'x_pose': str(X),
                'y_pose': '9.0',
                'z_pose': '0.50',
                'r_orientation': '0.0',
                'p_orientation': '0.0',
                'y_orientation': '4.735',
                'relative_x_pose': str(relative_X),
                'relative_y_pose': '-3.0',
                'relative_z_pose': '-0.5',
                'relative_r_orientation': '-1.548',
                'relative_p_orientation': '0.0',
                'relative_y_orientation': '0.0',
            }.items(),
        )
        
        launch_description.add_action(sensor_launch_cmd)
        X += 10.0
        relative_X += 10.0
        sleep(0.25)


    return launch_description