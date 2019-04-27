cmake_minimum_required(VERSION 2.8.3)
project(test_node)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES test_node
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(node_sub ./src/node_sub.cpp)
target_link_libraries(node_sub ${catkin_LIBRARIES})

add_executable(node_pub ./src/node_pub.cpp)
target_link_libraries(node_pub ${catkin_LIBRARIES})

install(TARGETS node_sub node_pub RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
