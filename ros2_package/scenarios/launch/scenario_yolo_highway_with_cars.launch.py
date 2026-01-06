import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, TimerAction, ExecuteProcess
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from gazebo_nodes.random_vehicle_spawner import generate_random_vehicle_position


def generate_launch_description():
    # Package Directories
    main_pkg_dir = get_package_share_directory('gazebo_nodes')
    launch_file_dir = os.path.join(main_pkg_dir, 'launch')

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


    num_iterations = 50
    spawn_interval = 20.0  # seconds
    delete_interval = 20.0  # seconds after spawn

    spawn_actions = []
    delete_actions = []
    
    for i in range(num_iterations):

        vehicle_array = generate_random_vehicle_position()

        for j in range(len(vehicle_array)):
            spawn_action = TimerAction(
                period=(i * spawn_interval) + 1,
                actions=[
                    IncludeLaunchDescription(
                        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'spawn_prius_lite.launch.py')),
                        launch_arguments={
                            'name': "prius_lite" + str(j),
                            'namespace': 'prius_lite',
                            'x_pose': str(vehicle_array[j][0]),
                            'y_pose': str(vehicle_array[j][1]),
                            'z_pose': '0.1',
                            'r_orientation': '0.0',
                            'p_orientation': '0.0',
                            'y_orientation': '0.0',
                        }.items(),
                    )
                ]
            )

            delete_action = TimerAction(
                period=(i * spawn_interval) + delete_interval,
                actions=[
                    ExecuteProcess(
                        cmd=['ros2', 'service', 'call', '/delete_entity', 'gazebo_msgs/srv/DeleteEntity', f"{{name: 'prius_lite{j}'}}"],
                        output='screen'
                    ),
                ]
            )

            spawn_actions.append(spawn_action)
            delete_actions.append(delete_action)

    
    print("[LOGGER]: Finished Generating "+ str(num_iterations) +" Random Vehicle Positions")
      

    prius_cmd_vel_publisher_node = Node(
        package='gazebo_nodes',
        executable='velocity_publisher.py',
        name='velocity_publisher',
        output='screen',
    )




    launch_description = LaunchDescription()
    launch_description.add_action(use_sim_time_arg)
    launch_description.add_action(world_launch_arg)
    launch_description.add_action(prius_cmd_vel_publisher_node)
    
    for action in spawn_actions + delete_actions:
        launch_description.add_action(action)

    return launch_description



