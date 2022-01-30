cmake_minimum_required(VERSION 3.5)
project(amtc_common)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

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
find_package(rclcpp REQUIRED)

# Include .h files in bulding
include_directories(include)

########
# LIBS #
########

# amtc_common
add_library(amtc_common SHARED 
  src/communications.cpp
)
ament_target_dependencies(amtc_common
  rclcpp
)

# example_interface
add_library(example_interface SHARED 
  test/example_interface.cpp
)
ament_target_dependencies(example_interface
  rclcpp
)
target_link_libraries(example_interface
  amtc_common
)

##########
# Nodes  #
##########

add_executable(example_interface_node test/example_interface_node.cpp)
ament_target_dependencies(example_interface_node
  rclcpp
)
target_include_directories(example_interface_node PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
target_link_libraries(example_interface_node
  amtc_common
  example_interface
)

##########
# Install  #
##########

install(TARGETS 
  amtc_common
  example_interface
  example_interface_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  #set(ament_cmake_copyright_FOUND TRUE)
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
