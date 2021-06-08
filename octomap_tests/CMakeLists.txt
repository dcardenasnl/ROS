cmake_minimum_required(VERSION 3.5)
project(octomap_tests)

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

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(octomap REQUIRED)
find_package(octomap_msgs REQUIRED)

set(THIS_PACKAGE_INCLUDE_DEPENDS
  rclcpp
  octomap
  octomap_msgs
)

###########
# Include #
###########

include_directories(
  include
)

########
# LIBS #
########

# octomap_interface
add_library(octomap_interface SHARED 
  src/octomap_interface.cpp
)
ament_target_dependencies(octomap_interface
  ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
# target_link_libraries(octomap_interface
#   ${THIS_PACKAGE_INCLUDE_DEPENDS}
# )

#########
# NODES #
#########

# octomap_tests
add_executable(octomap_tests
  src/octomap_tests.cpp
)
ament_target_dependencies(octomap_tests
  ${THIS_PACKAGE_INCLUDE_DEPENDS}
)
target_link_libraries(octomap_tests
  octomap_interface
)

###########
# INSTALL #
###########

install(TARGETS
  octomap_interface
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
