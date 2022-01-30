#include <amtc_common/communications.hpp>

namespace amtc {

Communications::Communications(std::string node_name):
  node_ptr_(new rclcpp::Node(node_name)),
  sub_interface_(node_ptr_)
{
}

Communications::~Communications()
{
}

/* ----------- Getters ---------- */

std::shared_ptr<rclcpp::Node> Communications::getNodePtr()
{
  return node_ptr_;
}

} // End namespace