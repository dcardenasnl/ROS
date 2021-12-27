# catkin build -j4 amtc_common

colcon build --parallel-workers 4 --packages-up-to amtc_common

# catkin build -j4 amtc_common --no-deps

colcon build --parallel-workers 4 --packages-select amtc_common

# rospack find

ros2 pkg prefix dcn_tests

# Create pkg

ros2 pkg create --build-type ament_cmake --node-name test_node amtc_common
