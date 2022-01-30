#ifndef COMMUNICATIONS_H_
#define COMMUNICATIONS_H_

#include <rclcpp/rclcpp.hpp>
#include <mutex>

#include <amtc_common/definitions.hpp>

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

  template<class MessageType>	SubscriberID addSubscriber(const	std::string& topic, void(*fp)(MessageType), const KeyWord& keyword = "", uint32_t queue_size = 100);
  template<class MessageType, class ObjectType> SubscriberID addSubscriber(const	std::string& topic, void(ObjectType::*fp)(MessageType), ObjectType* obj, const KeyWord& keyword = "", uint32_t queue_size = 100);

/* Avoid using public attibutes */

private:
  int getNewId(const std::set<int>& set_ids);

/* Set private method after public */
private:
  std::mutex mutex_;
  std::shared_ptr<rclcpp::Node> node_ptr_;

  /* Subscribers */
  std::set<SubscriberID>                  ros_subscribers_ids_;
  std::map<SubscriberID, Topic>           ros_subscriber_id_topic_;
  std::map<KeyWord, SubscriberID>         ros_subscriber_keyword_id_;
  std::map<SubscriberID, Subscriber>      ros_subscribers_;

};

} // End namespace

#endif