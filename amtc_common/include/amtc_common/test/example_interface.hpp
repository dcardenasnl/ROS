#ifndef __EXAMPLE_NODE_H__
#define __EXAMPLE_NODE_H__

/* Put rclcpp and external libs first */
#include <rclcpp/rclcpp.hpp>

/* Put msg seconds */
#include "std_msgs/msg/string.hpp"

/* Put local modules lasts */
#include <amtc_common/communications.hpp>

class ExampleNode
{
  /* Start class with public methods */
public:
  ExampleNode(amtc::Communications * comms_ptr);
  ~ExampleNode();

  /* Declarate callback as first method */
  void exampleStringCallback(const std_msgs::msg::String::SharedPtr msg);

  /* Avoid using public attibutes */

  /* Set private method after public */
private:
  amtc::Communications * comms_ptr_;
};

#endif