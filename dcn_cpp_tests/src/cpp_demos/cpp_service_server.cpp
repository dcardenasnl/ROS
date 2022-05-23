// Copyright (c) 2020 Daniel Cardenas
// Software License Agreement (BSD License)

#include <dcn_cpp_tests/cpp_demos/cpp_service_server.hpp>
#include <memory>

using std::placeholders::_1;
using std::placeholders::_2;

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

MinimalSrvServer::MinimalSrvServer()
: Node("minimal_service_server")
{
  srv_ = this->create_service<std_srvs::srv::SetBool>(
    "bool_client", std::bind(&MinimalSrvServer::set_bool_srv, this, _1, _2));
  RCLCPP_INFO(this->get_logger(), "Service Created");
}

void MinimalSrvServer::set_bool_srv(
  const std_srvs::srv::SetBool::Request::SharedPtr req,
  std_srvs::srv::SetBool::Response::SharedPtr resp)
{
  resp->success = req->data;
  RCLCPP_INFO(this->get_logger(), "Inside Service with req = %d", req->data);
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSrvServer>());
  rclcpp::shutdown();
  return 0;
}
