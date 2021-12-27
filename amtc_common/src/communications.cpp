#include <amtc_common/communications.hpp>

namespace amtc {

Communications::Communications(std::string node_nanme):
  Node(node_nanme)
{
}

Communications::~Communications()
{
}

/* ----------- Subs ---------- */

template<class M>	SubscriberID Communications::add_ros_subscriber(const	std::string& topic, void(*fp)(M), const KeyWord& keyword, uint32_t queue_size)
{
  // boost::mutex::scoped_lock lock(mutex_);  // Replace boost::mutex::scoped_lock with std::unique_lock<std::mutex>
  std::unique_lock<std::mutex> lock(mutex_);
  
  if(ros_subscriber_keyword_id_.count(keyword) != 0)
  {
    // ROS_WARN_NODE("add_ros_subscriber: keyword '%s' already registered with topic '%s'", keyword.c_str(), ros_subscriber_id_topic_[ros_subscriber_keyword_id_[keyword]].c_str());
    return ros_subscriber_keyword_id_[keyword];
  }

  SubscriberID id	= get_new_id(ros_subscribers_ids_);
  ros_subscribers_ids_.insert(id);
  ros_subscriber_id_topic_.insert(std::pair<SubscriberID, Topic>(id, topic));

  if(keyword != "")
  {
    ros_subscriber_keyword_id_.insert(std::pair<KeyWord, SubscriberID>(keyword, id));
  }

  ros_subscribers_.insert(std::pair<SubscriberID, Subscriber>(id, create_subscription<M>(topic, queue_size, fp)));

  return id;
}

/* ---------- PRIVATE --------------*/

int Communications::get_new_id(const std::set<int>& set_ids)
{
  if(set_ids.size() == 0)
  {
    return 1;
  }
  else
  {
    return (*set_ids.rbegin()) + 1;
  }
}


} // End namespace