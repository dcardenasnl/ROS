from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='dcn_cpp_tests',
            executable='cpp_topic_publisher',
            name='topic_publisher'
        )
    ])