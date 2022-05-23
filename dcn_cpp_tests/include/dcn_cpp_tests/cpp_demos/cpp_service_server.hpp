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

#include "rclcpp_components/register_node_macro.hpp"

/**
  * ROS MSGS
  */
#include "std_srvs/srv/set_bool.hpp"

using namespace std::chrono_literals;

class MinimalSrvServer : public rclcpp::Node
{
public:
  MinimalSrvServer();

private:
  void set_bool_srv(
    const std_srvs::srv::SetBool::Request::SharedPtr req,
    std_srvs::srv::SetBool::Response::SharedPtr resp);

private:
  rclcpp::Service<std_srvs::srv::SetBool>::SharedPtr srv_;
};

#endif  // CPP_TALKER_H
