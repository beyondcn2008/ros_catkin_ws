cmake_minimum_required(VERSION 2.8.3)
project(my_tools)

find_package(catkin REQUIRED COMPONENTS cmake_modules)

catkin_package(
	INCLUDE_DIRS include 
	LIBRARIES my_tools
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_library(my_tools SHARED ./src/my_tools.cpp)

include(GNUInstallDirs)

#install(TARGETS my_tools
#	ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#	LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#	RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(TARGETS my_tools
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION library)

install(DIRECTORY include/ DESTINATION ${CATKIN_GLOBAL_INCLUDE_DESTINATION} FILES_MATCHING PATTERN "*.h")
