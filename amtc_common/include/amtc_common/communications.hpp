#ifndef COMMUNICATIONS_H_
#define COMMUNICATIONS_H_

#include <amtc_common/definitions.hpp>
#include <amtc_common/interface/subscription_interface.hpp>
#include <mutex>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace amtc
{
// template<T>
// using Subscriber = rclcpp::Subscription<T>::SharedPtr;

using Subscriber = rclcpp::SubscriptionBase::SharedPtr;

class Communications
{
  /* Start class with public methods */
public:
  Communications(std::string node_name);
  ~Communications();

  std::shared_ptr<rclcpp::Node> getNodePtr();

private:
  std::shared_ptr<rclcpp::Node> node_ptr_;

  SubInterface sub_interface_;
};

}  // namespace amtc

#endif