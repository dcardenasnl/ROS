#include <octomap_tests/octomap_interface.hpp>

OctomapInterface::OctomapInterface():
  Node("ros_node_name"),
  octree_(0.1)
{
}