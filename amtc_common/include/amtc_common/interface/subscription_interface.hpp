#ifndef SUB_INTERFACE_H_
#define SUB_INTERFACE_H_

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
  SubInterface();
  ~SubInterface();

private:
};

}  // namespace amtc

#endif