import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    # Config
    config = os.path.join(
        get_package_share_directory('dcn_cpp_tests'),
        'config',
        'params.yaml'
        )

    # Nodes
    publisher_node = Node(
        package='dcn_cpp_tests',
        executable='cpp_topic_publisher',
        name='topic_pub',
        output='screen',
        emulate_tty = True,
        parameters = [config]
        )
    sub_node = Node(
        package='dcn_cpp_tests',
        executable='cpp_topic_subscriber',
        name='topic_sub',
        emulate_tty = True,
        output='screen'
        )
    random_publish_process = ExecuteProcess(
        cmd=[
            'ros2','topic', 'pub', '-r 0.01','/topic',
            'std_msgs/msg/String', '{data: RANDOM MSG}']
        )
    
    # Launch set-up
    launch_node = [
        sub_node,
        publisher_node,
        random_publish_process
        ]

    return LaunchDescription(launch_node)