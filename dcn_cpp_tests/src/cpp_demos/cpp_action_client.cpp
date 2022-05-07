#include <dcn_cpp_tests/cpp_demos/cpp_action_client.hpp>

using std::placeholders::_1;

using namespace std::chrono_literals;

/* This example creates a subclass of Node and uses std::bind() to register a
* member function as a callback from the timer. */

MinimalActionClient::MinimalActionClient():
  Node("minimal_action_client"),
  is_goal_done_(false)
{
  this->client_ptr_ = rclcpp_action::create_client<Fibonacci>(
    this->get_node_base_interface(), this->get_node_graph_interface(),
    this->get_node_logging_interface(), this->get_node_waitables_interface(),
    "fibonacci");

  RCLCPP_INFO(this->get_logger(), "Client created");

  send_goal();

  return;
}

bool MinimalActionClient::isGoalDone()
{
  return is_goal_done_;
}

void MinimalActionClient::send_goal()
{
  using namespace std::placeholders;

  RCLCPP_INFO(this->get_logger(), "Waiting for server");

  if (!this->client_ptr_->wait_for_action_server(2s)) {
    RCLCPP_ERROR(this->get_logger(), "Action server not available after waiting");
    is_goal_done_ = true;
    return;
  }

  auto goal_msg = Fibonacci::Goal();
  goal_msg.order = 10;

  RCLCPP_INFO(this->get_logger(), "Sending goal");

  auto send_goal_options = rclcpp_action::Client<Fibonacci>::SendGoalOptions();
  send_goal_options.goal_response_callback = 
    std::bind(&MinimalActionClient::goal_response_callback, this, _1);
  send_goal_options.feedback_callback =
    std::bind(&MinimalActionClient::feedback_callback, this, _1, _2);
  send_goal_options.result_callback =
   std::bind(&MinimalActionClient::result_callback, this, _1);
  this->client_ptr_->async_send_goal(goal_msg, send_goal_options);
}

void MinimalActionClient::goal_response_callback(std::shared_future<GoalHandleFibonacci::SharedPtr> future)
{
  RCLCPP_INFO(this->get_logger(), "goal_response_callback");
  auto goal_handle = future.get();
  if (!goal_handle) {
    RCLCPP_ERROR(this->get_logger(), "Goal was rejected by server");
  } else {
    RCLCPP_INFO(this->get_logger(), "Goal accepted by server, waiting for result");
  }
}

void MinimalActionClient::feedback_callback(
  GoalHandleFibonacci::SharedPtr,
  const std::shared_ptr<const dcn_msgs::action::Fibonacci::Feedback> feedback)
{
  RCLCPP_INFO(this->get_logger(), "feedback_callback");
  std::stringstream ss;
  ss << "Next number in sequence received: ";
  for (auto number : feedback->partial_sequence) {
    ss << number << " ";
  }
  RCLCPP_INFO(this->get_logger(), ss.str().c_str());
}

void MinimalActionClient::result_callback(const GoalHandleFibonacci::WrappedResult &result)
{
  switch (result.code) {
    case rclcpp_action::ResultCode::SUCCEEDED:
      break;
    case rclcpp_action::ResultCode::ABORTED:
      RCLCPP_ERROR(this->get_logger(), "Goal was aborted");
      return;
    case rclcpp_action::ResultCode::CANCELED:
      RCLCPP_ERROR(this->get_logger(), "Goal was canceled");
      return;
    default:
      RCLCPP_ERROR(this->get_logger(), "Unknown result code");
      return;
  }
  std::stringstream ss;
  ss << "Result received: ";
  for (auto number : result.result->sequence)
  {
    ss << number << " ";
  }
  RCLCPP_INFO(this->get_logger(), ss.str().c_str());
  is_goal_done_ = true;
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto action_client_ptr = std::make_shared<MinimalActionClient>();

  while (!action_client_ptr->isGoalDone())
  {
    rclcpp::spin_some(action_client_ptr);
  }

  rclcpp::shutdown();
  return 0;
}
