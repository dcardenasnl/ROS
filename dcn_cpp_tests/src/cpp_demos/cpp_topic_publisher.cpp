#include <dcn_cpp_tests/cpp_demos/cpp_topic_publisher.hpp>

using namespace std::chrono_literals;

MinimalPublisher::MinimalPublisher():
  Node("minimal_publisher"),
  count_(0)
{
  /* Publishers */
  publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);

  /* Timers */
  std::chrono::milliseconds period(500ms);
  timer_ = this->create_wall_timer(period, std::bind(&MinimalPublisher::timer_callback, this));
}

void MinimalPublisher::timer_callback()
{
  std_msgs::msg::String message;
  message.data = "Hello, world! " + std::to_string(count_++);
  RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
  publisher_->publish(message);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
