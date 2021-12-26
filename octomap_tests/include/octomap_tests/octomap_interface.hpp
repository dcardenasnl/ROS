#ifndef __OCTOMAP_INTERFACE_H__
#define __OCTOMAP_INTERFACE_H__

/* ROS code includes */
#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>

#include <octomap/octomap.h>
#include <octomap_msgs/msg/octomap_with_pose.h>

/* ROS local packages */
// #include <dcn_msgs/action/fibonacci.hpp>

class OctomapInterface : public rclcpp::Node
{
public:
  /* Definition for simplicity */
  // using Fibonacci = dcn_msgs::action::Fibonacci;
  // using GoalHandleFibonacci = rclcpp_action::ClientGoalHandle<Fibonacci>;

public:
  OctomapInterface();

private:
  /* Callbacks */
  // void goal_response_callback(std::shared_future<GoalHandleFibonacci::SharedPtr> future);
  // void feedback_callback(GoalHandleFibonacci::SharedPtr, const std::shared_ptr<const Fibonacci::Feedback> feedback);
  // void result_callback(const GoalHandleFibonacci::WrappedResult & result);
  
  /* Utils */
  void createFakeCloud();
  void castingRaysInSphere();

private:
  /* ROS & common params */
  // rclcpp_action::Client<Fibonacci>::SharedPtr client_ptr_;
  octomap::OcTree octree_map_data_;
  octomap::Pointcloud octomap_cloud_;

  /* Internal Class parametters */
  // bool is_goal_done_;
};


#endif // __OCTOMAP_INTERFACE_H__