// Copyright (c) 2020 Daniel Cardenas
// Software License Agreement (BSD License)

#ifndef DCN_CPP_TESTS__CPP_DEMOS__CPP_SERVICE_SERVER_HPP_
#define DCN_CPP_TESTS__CPP_DEMOS__CPP_SERVICE_SERVER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_components/register_node_macro.hpp>
#include <std_srvs/srv/set_bool.hpp>

#include <chrono>
#include <functional>
#include <memory>
#include <string>

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

#endif  // DCN_CPP_TESTS__CPP_DEMOS__CPP_SERVICE_SERVER_HPP_
