#ifndef CPP_LISTNER_HPP
#define CPP_LISTNER_HPP

/**
  * Others
  */
#include <memory>
/**
  * ROS
  */
#include <rclcpp/rclcpp.hpp>

/**
  * ROS MSGS
  */
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber();

private:
  void timer_callback();
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const;

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

#endif  // CPP_LISTNER_HPP
