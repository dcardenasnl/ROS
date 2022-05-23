// Copyright (c) 2020 Daniel Cardenas
// Software License Agreement (BSD License)

#ifndef DCN_CPP_TESTS__CPP_DEMOS__CPP_TOPIC_SUBSCRIBER_HPP_
#define DCN_CPP_TESTS__CPP_DEMOS__CPP_TOPIC_SUBSCRIBER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <memory>

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

#endif  // DCN_CPP_TESTS__CPP_DEMOS__CPP_TOPIC_SUBSCRIBER_HPP_
