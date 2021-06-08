#include <rclcpp/rclcpp.hpp>

#include <octomap_tests/octomap_interface.hpp>

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<OctomapInterface>());
  rclcpp::shutdown();
  return 0;
}
