# catkin build -j4 <PKG>

colcon build --parallel-workers 4 --packages-up-to <PKG> --symlink-install

# catkin build -j4 <PKG> --no-deps

colcon build --parallel-workers 4 --packages-select <PKG> --symlink-install

# rospack find

ros2 pkg prefix <PKG>

# roscd <PKG>

* colcon_cd --set
colcon_cd amtc_common

# Create pkg

ros2 pkg create --build-type ament_cmake --node-name test_node amtc_common

# Utils

colcon build --parallel-workers 4 --packages-select amtc_common --allow-overriding amtc_common

# roslaunch <PKG> <FILENAME>.launch
