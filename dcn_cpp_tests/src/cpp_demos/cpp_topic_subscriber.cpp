#include <dcn_tests/cpp_demos/cpp_topic_subscriber.hpp>

using std::placeholders::_1;

MinimalSubscriber::MinimalSubscriber():
  Node("minimal_subscriber")
{
  /* Subscriber */
  subscription_ = this->create_subscription<std_msgs::msg::String>("topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
}

void MinimalSubscriber::topic_callback(const std_msgs::msg::String::SharedPtr msg) const
{
  RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
  return;
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
