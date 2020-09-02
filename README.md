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


## CMakeLists of Custom Pkg

command: `catkin_create_pkg custom_package roscpp rospy custom_msgs std_msgs`

CMakeLists.txt  
```cmake
cmake_minimum_required(VERSION 3.0.2)
project(custom_package)

## Compile as C++11, supported in ROS Kinetic and newer
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  custom_msgs   # Add
  roscpp
  rospy
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS custom_msgs roscpp rospy std_msgs    # Add
)

include_directories(
    ${catkin_INCLUDE_DIRS}
    ${CURSES_INCLUDE_DIR}
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
add_dependencies(${node_name} custom_msgs_gencpp)   # Add
```

package.xml
```xml
<?xml version="1.0"?>
<package format="2">
  <name>custom_package</name>
  <version>0.0.0</version>
  <description>The custom_package package</description>
  <author email="jianle001@e.ntu.edu.sg">brucechanjianle</author>
  <maintainer email="jianle001@e.ntu.edu.sg">brucechanjianle</maintainer>
  <license>MIT</license>
  <url type="website">https://github.com/BruceChanJianLe/ros-custom-msg</url>

  <buildtool_depend>catkin</buildtool_depend>

  <build_depend>custom_msgs</build_depend>   # Add
  <build_depend>roscpp</build_depend>
  <build_depend>rospy</build_depend>
  <build_depend>std_msgs</build_depend>

  <build_export_depend>custom_msgs</build_export_depend>
  <build_export_depend>roscpp</build_export_depend>
  <build_export_depend>rospy</build_export_depend>
  <build_export_depend>std_msgs</build_export_depend>

  <exec_depend>custom_msgs</exec_depend>   # Add
  <exec_depend>roscpp</exec_depend>
  <exec_depend>rospy</exec_depend>
  <exec_depend>std_msgs</exec_depend>


</package>
```
