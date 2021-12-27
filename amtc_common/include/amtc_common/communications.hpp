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

class Communications : public rclcpp::Node
{
/* Start class with public methods */
public:
  Communications(std::string node_nanme);
  ~Communications();

  template<class M>	SubscriberID add_ros_subscriber(const	std::string& topic, void(*fp)(M), const KeyWord& keyword = "", uint32_t queue_size = 100);

/* Avoid using public attibutes */

private:
  int get_new_id(const std::set<int>& set_ids);

/* Set private method after public */
private:
  std::mutex mutex_;

  /* Subscribers */
  std::set<SubscriberID>                  ros_subscribers_ids_;
  std::map<SubscriberID, Topic>           ros_subscriber_id_topic_;
  std::map<KeyWord, SubscriberID>         ros_subscriber_keyword_id_;
  std::map<SubscriberID, Subscriber>      ros_subscribers_;

};

} // End namespace

#endif