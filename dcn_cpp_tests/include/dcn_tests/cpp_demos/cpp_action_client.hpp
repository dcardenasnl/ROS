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
#include "rclcpp_action/rclcpp_action.hpp"

/**
  * ROS MSGS
  */
#include <dcn_msgs/action/fibonacci.hpp>

using namespace std::chrono_literals;

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
  void feedback_callback(GoalHandleFibonacci::SharedPtr, const std::shared_ptr<const Fibonacci::Feedback> feedback);
  void result_callback(const GoalHandleFibonacci::WrappedResult & result);

private:
  rclcpp_action::Client<Fibonacci>::SharedPtr client_ptr_;
  bool is_goal_done_;
};

#endif // CPP_TALKER_H
