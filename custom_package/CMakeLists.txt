cmake_minimum_required(VERSION 3.0.2)
project(custom_package)

## Compile as C++11, supported in ROS Kinetic and newer
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  custom_msgs
  roscpp
  rospy
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS custom_msgs roscpp rospy std_msgs
)

# Set node name as variable
set(node_name "custom_message_node")

# Create executable
add_executable(${node_name}
               src/main.cpp
)
# Link executable with library
target_link_libraries(${node_name} ${catkin_LIBRARIES})
# Add msg dependency
add_dependencies(${node_name} custom_msgs_gencpp)