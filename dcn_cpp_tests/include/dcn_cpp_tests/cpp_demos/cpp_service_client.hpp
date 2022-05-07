#ifndef __CPP_SERVICE_CLIENT_H__
#define __CPP_SERVICE_CLIENT_H__

/**
  * Others
  */
#include <chrono>
#include <memory>
#include <stdexcept>

/**
  * ROS
  */
#include <rclcpp/rclcpp.hpp>

/**
  * ROS MSGS
  */
#include "std_srvs/srv/set_bool.hpp"

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


#endif // __CPP_SERVICE_CLIENT_H__