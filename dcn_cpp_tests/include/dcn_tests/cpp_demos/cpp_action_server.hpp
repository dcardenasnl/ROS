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

class MinimalActionServer : public rclcpp::Node
{
public:
  using Fibonacci = dcn_msgs::action::Fibonacci;
  using GoalHandleFibonacci = rclcpp_action::ServerGoalHandle<Fibonacci>;

public:
  MinimalActionServer();

private:
  void create_server();

  rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID& uuid, std::shared_ptr<const Fibonacci::Goal> goal);
  rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandleFibonacci> goal_handle);
  void handle_accepted(const std::shared_ptr<GoalHandleFibonacci> goal_handle);
  void execute_action(const std::shared_ptr<GoalHandleFibonacci> goal_handle);

private:
  rclcpp_action::Server<Fibonacci>::SharedPtr action_server_;
  rclcpp::TimerBase::SharedPtr timer_;
};

#endif // CPP_TALKER_H
