# catkin build -j4 amtc_common

colcon build --parallel-workers 4 --packages-up-to <PKG>

# catkin build -j4 amtc_common --no-deps

colcon build --parallel-workers 4 --packages-select <PKG>

# rospack find

ros2 pkg prefix <PKG>

# roscd <PKG>

* colcon_cd --set
colcon_cd amtc_common

# Create pkg

ros2 pkg create --build-type ament_cmake --node-name test_node amtc_common

# Utils

colcon build --parallel-workers 4 --packages-select amtc_common --allow-overriding amtc_common

