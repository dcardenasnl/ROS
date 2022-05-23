#include <amtc_common/communications.hpp>
#include <amtc_common/test/example_interface.hpp>
#include <rclcpp/rclcpp.hpp>

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);

  amtc::Communications * comms_ptr = new amtc::Communications("example_interface");
  ExampleNode node(comms_ptr);
  rclcpp::spin(comms_ptr->getNodePtr()->get_node_base_interface());
  rclcpp::shutdown();
  return 0;
}
