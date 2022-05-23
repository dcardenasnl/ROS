// Copyright (c) 2020 Daniel Cardenas
// Software License Agreement (BSD License)

#include <dcn_cpp_tests/cpp_demos/cpp_service_client.hpp>
#include <memory>

using std::placeholders::_1;

using namespace std::chrono_literals;

MinimalSrvClient::MinimalSrvClient()
: Node("minimal_service_client")
{
  /* Srv Server */
  client_ = this->create_client<std_srvs::srv::SetBool>("bool_client");

  /* Timers */
  timer_ = this->create_wall_timer(2s, std::bind(&MinimalSrvClient::timer_callback, this));
}

void MinimalSrvClient::timer_callback()
{
  sendService();
}

bool MinimalSrvClient::sendService()
{
  std_srvs::srv::SetBool::Request::SharedPtr request_msgs(new std_srvs::srv::SetBool::Request);

  request_msgs->data = true;

  try {
    waitForService(2s);
    RCLCPP_INFO(this->get_logger(), "Send Request");
    auto result = client_->async_send_request(request_msgs);
    waitForResponce(result);
    RCLCPP_INFO_STREAM(this->get_logger(), "Result: " << result.get()->success);
  } catch (const std::exception & e) {
    RCLCPP_ERROR_STREAM(this->get_logger(), e.what());
  }

  return true;
}

void MinimalSrvClient::waitForService(std::chrono::duration<double> timeout)
{
  bool service_was_found = client_->wait_for_service(timeout);
  if (!service_was_found) {
    throw std::runtime_error("service not available");
  }
}

void MinimalSrvClient::waitForResponce(rclcpp::Client<std_srvs::srv::SetBool>::SharedFuture result)
{
  if (
    rclcpp::spin_until_future_complete(this->get_node_base_interface(), result) !=
    rclcpp::FutureReturnCode::SUCCESS)
  {
    throw std::runtime_error("service responce reception error");
  }
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);

  auto srv_client = std::make_shared<MinimalSrvClient>();

  srv_client->sendService();

  rclcpp::shutdown();
  return 0;
}
