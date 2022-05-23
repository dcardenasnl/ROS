// Copyright (c) 2020 Daniel Cardenas
// Software License Agreement (BSD License)

#ifndef DCN_CPP_TESTS__CPP_DEMOS__CPP_TOPIC_PUBLISHER_HPP_
#define DCN_CPP_TESTS__CPP_DEMOS__CPP_TOPIC_PUBLISHER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <chrono>
#include <functional>
#include <memory>
#include <string>

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

#endif  // DCN_CPP_TESTS__CPP_DEMOS__CPP_TOPIC_PUBLISHER_HPP_
