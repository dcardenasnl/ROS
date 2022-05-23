// Copyright (c) 2020 Daniel Cardenas
// Software License Agreement (BSD License)

#ifndef DCN_CPP_TESTS__CPP_DEMOS__CPP_ACTION_CLIENT_HPP_
#define DCN_CPP_TESTS__CPP_DEMOS__CPP_ACTION_CLIENT_HPP_

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>

#include <dcn_msgs/action/fibonacci.hpp>

#include <chrono>
#include <functional>
#include <memory>
#include <string>

class MinimalActionClient : public rclcpp::Node
{
public:
  using Fibonacci = dcn_msgs::action::Fibonacci;
  using GoalHandleFibonacci = rclcpp_action::ClientGoalHandle<Fibonacci>;

public:
  MinimalActionClient();
  bool isGoalDone();

private:
  void send_goal();
  void goal_response_callback(std::shared_future<GoalHandleFibonacci::SharedPtr> future);
  void feedback_callback(
    GoalHandleFibonacci::SharedPtr, const std::shared_ptr<const Fibonacci::Feedback> feedback);
  void result_callback(const GoalHandleFibonacci::WrappedResult & result);

private:
  rclcpp_action::Client<Fibonacci>::SharedPtr client_ptr_;
  bool is_goal_done_;
};

#endif  // DCN_CPP_TESTS__CPP_DEMOS__CPP_ACTION_CLIENT_HPP_
