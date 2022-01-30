#ifndef COMMUNICATIONS_H_
#define COMMUNICATIONS_H_

#include <rclcpp/rclcpp.hpp>
#include <mutex>

#include <amtc_common/definitions.hpp>

#include <std_msgs/msg/string.hpp>

namespace amtc
{
using Subscriber = rclcpp::SubscriptionBase::SharedPtr;

class SubInterface
{
public:
  SubInterface(std::string node_name);
  ~SubInterface();

private:
};

}  // namespace amtc

#endif