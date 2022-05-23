// Copyright (c) 2020 Daniel Cardenas
// Software License Agreement (BSD License)

#ifndef DCN_CPP_TESTS__CPP_DEMOS__CPP_ACTION_SERVER_HPP_
#define DCN_CPP_TESTS__CPP_DEMOS__CPP_ACTION_SERVER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include <dcn_msgs/action/fibonacci.hpp>

#include <chrono>
#include <functional>
#include <memory>
#include <string>

class MinimalActionServer : public rclcpp::Node
{
public:
  using Fibonacci = dcn_msgs::action::Fibonacci;
  using GoalHandleFibonacci = rclcpp_action::ServerGoalHandle<Fibonacci>;

public:
  MinimalActionServer();

private:
  void create_server();

  rclcpp_action::GoalResponse handle_goal(
    const rclcpp_action::GoalUUID & uuid, std::shared_ptr<const Fibonacci::Goal> goal);
  rclcpp_action::CancelResponse handle_cancel(
    const std::shared_ptr<GoalHandleFibonacci> goal_handle);
  void handle_accepted(const std::shared_ptr<GoalHandleFibonacci> goal_handle);
  void execute_action(const std::shared_ptr<GoalHandleFibonacci> goal_handle);

private:
  rclcpp_action::Server<Fibonacci>::SharedPtr action_server_;
  rclcpp::TimerBase::SharedPtr timer_;
};

#endif  // DCN_CPP_TESTS__CPP_DEMOS__CPP_ACTION_SERVER_HPP_
