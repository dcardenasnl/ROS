// Copyright (c) 2020 Daniel Cardenas
// Software License Agreement (BSD License)

#ifndef DCN_CPP_TESTS__CPP_DEMOS__CPP_SERVICE_CLIENT_HPP_
#define DCN_CPP_TESTS__CPP_DEMOS__CPP_SERVICE_CLIENT_HPP_

#include <rclcpp/rclcpp.hpp>
#include <std_srvs/srv/set_bool.hpp>

#include <chrono>
#include <memory>
#include <stdexcept>

class MinimalSrvClient : public rclcpp::Node
{
public:
  MinimalSrvClient();
  bool sendService();

private:
  void timer_callback();

  /* Utils */
  void waitForService(std::chrono::duration<double> timeout);
  void waitForResponce(rclcpp::Client<std_srvs::srv::SetBool>::SharedFuture result);

private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Client<std_srvs::srv::SetBool>::SharedPtr client_;
};

#endif  // DCN_CPP_TESTS__CPP_DEMOS__CPP_SERVICE_CLIENT_HPP_
