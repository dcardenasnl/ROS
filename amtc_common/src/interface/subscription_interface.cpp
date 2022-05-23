#include <amtc_common/interface/subscription_interface.hpp>

namespace amtc
{
SubInterface::SubInterface(std::shared_ptr<rclcpp::Node> node_ptr) : node_ptr_(node_ptr) {}

SubInterface::~SubInterface() {}

/* ----------- Subs ---------- */

template <class MessageType>
SubscriberID SubInterface::addSubscriber(
  const std::string & topic, void (*fp)(MessageType), const KeyWord & keyword, uint32_t queue_size)
{
  // boost::mutex::scoped_lock lock(mutex_);  // Replace boost::mutex::scoped_lock with std::unique_lock<std::mutex>
  std::unique_lock<std::mutex> lock(mutex_);

  if (ros_subscriber_keyword_id_.count(keyword) != 0) {
    // ROS_WARN_NODE("addSubscriber: keyword '%s' already registered with topic '%s'", keyword.c_str(), ros_subscriber_id_topic_[ros_subscriber_keyword_id_[keyword]].c_str());
    return ros_subscriber_keyword_id_[keyword];
  }

  SubscriberID id = getNewId(ros_subscribers_ids_);
  ros_subscribers_ids_.insert(id);
  ros_subscriber_id_topic_.insert(std::pair<SubscriberID, Topic>(id, topic));

  if (keyword != "") {
    ros_subscriber_keyword_id_.insert(std::pair<KeyWord, SubscriberID>(keyword, id));
  }

  ros_subscribers_.insert(std::pair<SubscriberID, Subscriber>(
    id, node_ptr_->create_subscription<MessageType>(topic, queue_size, fp)));

  return id;
}

template <class MessageType, class ObjectType>
SubscriberID SubInterface::addSubscriber(
  const std::string & topic, void (ObjectType::*fp)(MessageType), ObjectType * obj,
  const KeyWord & keyword, uint32_t queue_size)
{
  std::unique_lock<std::mutex> lock(mutex_);
  if (ros_subscriber_keyword_id_.count(keyword) != 0) {
    // ROS_WARN_NODE("addSubscriber: keyword '%s' already registered with topic '%s'", keyword.c_str(), ros_subscriber_id_topic_[ros_subscriber_keyword_id_[keyword]].c_str());
    return ros_subscriber_keyword_id_[keyword];
  }
  SubscriberID id = getNewId(ros_subscribers_ids_);
  ros_subscribers_ids_.insert(id);
  ros_subscriber_id_topic_.insert(std::pair<SubscriberID, Topic>(id, topic));
  if (keyword != "") {
    ros_subscriber_keyword_id_.insert(std::pair<KeyWord, SubscriberID>(keyword, id));
  }
  ros_subscribers_.insert(std::pair<SubscriberID, Subscriber>(
    id, node_ptr_->create_subscription<MessageType>(topic, queue_size, fp)));
  return id;
}

/* ---------- PRIVATE --------------*/

int SubInterface::getNewId(const std::set<int> & set_ids)
{
  if (set_ids.size() == 0) {
    return 1;
  } else {
    return (*set_ids.rbegin()) + 1;
  }
}

}  // namespace amtc