from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    publisher_node = Node(package='dcn_cpp_tests', executable='cpp_topic_publisher', name='topic_pub')
    sub_node = Node(package='dcn_cpp_tests', executable='cpp_topic_subscriber', name='topic_sub')
    launch_node = [publisher_node, sub_node]
    return LaunchDescription(launch_node)