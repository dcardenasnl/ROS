#ifndef SUB_INTERFACE_H_
#define SUB_INTERFACE_H_

#include <amtc_common/definitions.hpp>
#include <mutex>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

namespace amtc
{
using Subscriber = rclcpp::SubscriptionBase::SharedPtr;

class SubInterface
{
public:
  SubInterface(std::shared_ptr<rclcpp::Node> node_ptr);
  ~SubInterface();

  template <class MessageType>
  SubscriberID addSubscriber(
    const std::string & topic, void (*fp)(MessageType), const KeyWord & keyword = "",
    uint32_t queue_size = 100);
  template <class MessageType, class ObjectType>
  SubscriberID addSubscriber(
    const std::string & topic, void (ObjectType::*fp)(MessageType), ObjectType * obj,
    const KeyWord & keyword = "", uint32_t queue_size = 100);

private:
  int getNewId(const std::set<int> & set_ids);

private:
  std::mutex mutex_;
  std::shared_ptr<rclcpp::Node> node_ptr_;

  /* Params */
  std::set<SubscriberID> ros_subscribers_ids_;
  std::map<SubscriberID, Topic> ros_subscriber_id_topic_;
  std::map<KeyWord, SubscriberID> ros_subscriber_keyword_id_;
  std::map<SubscriberID, Subscriber> ros_subscribers_;
};

}  // namespace amtc

#endif