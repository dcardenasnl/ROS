#ifndef CPP_TALKER_H
#define CPP_TALKER_H

/**
  * Others
  */
#include <chrono>
#include <functional>
#include <memory>
#include <string>

/**
  * ROS
  */
#include <rclcpp/rclcpp.hpp>

/**
  * ROS MSGS
  */
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher();

private:
  void timer_callback();

private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
  double publish_rate_;
};

#endif  // CPP_TALKER_H
