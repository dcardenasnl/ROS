from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import ExecuteProcess

def generate_launch_description():
    publisher_node = Node(package='dcn_cpp_tests', executable='cpp_topic_publisher', name='topic_pub', output='screen')
    sub_node = Node(package='dcn_cpp_tests', executable='cpp_topic_subscriber', name='topic_sub', output='screen')
    random_publish_process = ExecuteProcess(cmd=['ros2', 'topic', 'pub', '-r 1', '/topic', 'std_msgs/msg/String', '{data: RANDOM MSG}'])
    launch_node = [sub_node, publisher_node, random_publish_process]
    return LaunchDescription(launch_node)