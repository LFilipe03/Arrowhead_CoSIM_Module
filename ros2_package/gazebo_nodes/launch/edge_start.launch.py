"""Start EDGE launch file"""

import os 
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch import LaunchDescription
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
import launch
import launch_ros

from nav2_common.launch import ReplaceString

def generate_launch_description():
    """Return launch description"""

    # Package Directories
    pkg_dir = get_package_share_directory('gazebo_nodes')

    # Paths to folders and files
    launch_file_dir = os.path.join(pkg_dir, 'launch')

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

    # Launch Arguments
    name_arg = DeclareLaunchArgument(
        'name',
        default_value='Edge',
        description='Robot name in Gazebo'
    )

    namespace_arg = DeclareLaunchArgument(
        'namespace',
        default_value='edge',
        description='Robot namespace for ROS nodes and topics'
    )

    use_sim_time_arg = DeclareLaunchArgument(
        'use_sim_time',
        default_value='true',
        description='Use simulation (Gazebo) clock if true'
    )

    # Nodes and other launch files

    robot_state_publisher_node = IncludeLaunchDescription( # Cals the edge_state_launch.py file
        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'edge_state.launch.py')),
        launch_arguments={'use_sim_time': use_sim_time,'naamespace': namespace}.items()
    )

    spawn_entity = IncludeLaunchDescription( # TO BE ADDED
        PythonLaunchDescriptionSource(os.path.join(launch_file_dir, 'spawn_edge.launch.py')),
        launch_arguments={'x_pose': x_pose, 'y_pose': y_pose, 'z_pose': z_pose, 'r_orientation': r_orientation, 'p_orientation': p_orientation, 'y_orientation': y_orientation, 'namespace': namespace, 'name': name}.items()
    )

    remappings = [
        ('/tf', 'tf'),
        ('/tf_static', 'tf_static')
    ]

    
    # Launch rviz
    default_rviz_config_path = os.path.join(pkg_dir, 'rviz/urdf_config.rviz')

    rviz_config_arg = DeclareLaunchArgument(
        name='rviz_config',
        default_value=default_rviz_config_path,
        description='Path to rviz config file'
    )

    rviz_config_file = LaunchConfiguration('rviz_config')

    namespaced_rviz_config_file = ReplaceString(
    source_file=rviz_config_file,
    replacements={'<robot_namespace>': ('/', namespace)})
    


    # Launch RVIZ should be added here

    edge_tf_cmd = Node(
        package='gazebo_nodes',
        executable='sensor_tf_publisher',
        name='edge_tf_publisher',
        output='screen',
        namespace='',
        parameters=[{'use_sim_time': use_sim_time}],
    )

    rviz_cmd = Node(
        package='rviz2',
        executable='rviz2',
        name='rviz2',
        output='screen',
        arguments=['-d', namespaced_rviz_config_file],
        namespace=namespace,
        #remappings=[('/tf', 'tf'),('/tf_static','tf_static')]
    )
 

    # Launch Description

    launch_description = LaunchDescription()
    launch_description.add_action(name_arg)
    launch_description.add_action(namespace_arg)
    launch_description.add_action(use_sim_time_arg)

    launch_description.add_action(x_pose_arg)
    launch_description.add_action(y_pose_arg)
    launch_description.add_action(z_pose_arg)
    launch_description.add_action(r_orientation_arg)
    launch_description.add_action(p_orientation_arg)
    launch_description.add_action(y_orientation_arg)

    launch_description.add_action(robot_state_publisher_node)
    launch_description.add_action(spawn_entity)
    launch_description.add_action(edge_tf_cmd)
    launch_description.add_action(rviz_config_arg)



    return launch_description