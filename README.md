# ROS Custom Msg

There are two ROS package in this repository. The first one is the custom msg and the second one is the package which utilizes the custom msg.

## CMakeLists of Custom Msg

command: `catkin_create_pkg custom_msgs roscpp rospy message_runtime message_generation`

CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.0.2)
project(custom_msgs)

## Compile as C++11, supported in ROS Kinetic and newer
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  message_generation
  message_runtime
  roscpp
  rospy
)

# Message file
add_message_files(
  DIRECTORY
    msg
  FILES
    CustomMsg.msg
)

generate_messages(
  DEPENDENCIES
    std_msgs
)

catkin_package(
  CATKIN_DEPENDS
    message_runtime
)
```

**Reference**  
- https://answers.ros.org/question/213020/writing-a-custom-message-and-using-it-in-a-different-package/
- 

