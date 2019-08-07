cmake_minimum_required(VERSION 2.8.3)
project(nodelet_example)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  nodelet
  roscpp
  std_msgs
)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )


catkin_package(
#  INCLUDE_DIRS include
  LIBRARIES nodelet_example
  CATKIN_DEPENDS nodelet roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
 include
  ${catkin_INCLUDE_DIRS}
)

SET(nodelet_example_sync_lib_src
	src/nodelet_example_class.cpp
)


## Declare a C++ library
add_library(nodelet_example_sync
   ${nodelet_example_sync_lib_src}
 )


## Specify libraries to link a library or executable target against
#target_link_libraries(nodelet_example_sync ${catkin_LIBRARIES})

#############
## Testing ##
#############
add_executable(CoreNode src/CoreNode.cpp)
target_link_libraries(CoreNode ${catkin_LIBRARIES})

if(catkin_EXPORTED_LIBRARIES)
   target_link_libraries(nodelet_example_sync ${catkin_EXPORTED_LIBRARIES})
endif()
