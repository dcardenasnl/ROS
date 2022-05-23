#include <amtc_common/test/example_interface.hpp>

ExampleNode::ExampleNode(amtc::Communications * comms_ptr) : comms_ptr_(comms_ptr)
{
  /* Subscriber */
  // comms_ptr_->addSubscriber<std_msgs::msg::String>("topic", &ExampleNode::exampleStringCallback, this, "string_cb", 10);
}

ExampleNode::~ExampleNode() {}

/* ---------- Use this lines facilitate finding methos in large implementations -------------*/
/* ---------- Callbacks -------------*/

void ExampleNode::exampleStringCallback(const std_msgs::msg::String::SharedPtr msg)
{
  RCLCPP_INFO(comms_ptr_->getNodePtr()->get_logger(), "I heard: '%s'", msg->data.c_str());
  return;
}