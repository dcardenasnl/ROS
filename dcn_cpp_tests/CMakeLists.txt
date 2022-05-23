cmake_minimum_required(VERSION 3.5)
project(dcn_cpp_tests)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

############
# REQUIRED #
############

find_package(ament_cmake REQUIRED)
find_package(builtin_interfaces REQUIRED)
find_package(dcn_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(rcutils REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)

################
# INCLUDE DIRS #
################
include_directories(include)

#########
# BUILD #
#########

# cpp_topic_publisher
add_executable(cpp_topic_publisher
  src/cpp_demos/cpp_topic_publisher.cpp
)
ament_target_dependencies(cpp_topic_publisher
  rclcpp
)

# cpp_topic_subscriber
add_executable(cpp_topic_subscriber
  src/cpp_demos/cpp_topic_subscriber.cpp
)
ament_target_dependencies(cpp_topic_subscriber
  rclcpp
)

# cpp_service_client
add_executable(cpp_service_client
  src/cpp_demos/cpp_service_client.cpp
)
ament_target_dependencies(cpp_service_client
  rclcpp
  rcutils
  std_srvs
)

# cpp_service_server
add_executable(cpp_service_server
  src/cpp_demos/cpp_service_server.cpp
)
ament_target_dependencies(cpp_service_server
  rclcpp
  rcutils
  std_srvs
)

# cpp_action_client
add_executable(cpp_action_client
  src/cpp_demos/cpp_action_client.cpp
)
ament_target_dependencies(cpp_action_client
  dcn_msgs
  rclcpp
  rclcpp_action
  rclcpp_components
  rcutils
  std_srvs
)

# cpp_action_server
add_executable(cpp_action_server
  src/cpp_demos/cpp_action_server.cpp
)
ament_target_dependencies(cpp_action_server
  dcn_msgs
  rclcpp
  rclcpp_action
  rclcpp_components
  rcutils
  std_srvs
)

###########
# INSTALL #
###########

install(TARGETS
  cpp_topic_publisher
  cpp_topic_subscriber
  cpp_service_client
  cpp_service_server
  cpp_action_client
  cpp_action_server
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
install(DIRECTORY config DESTINATION share/${PROJECT_NAME})

############
# TESTINGS #
############

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
