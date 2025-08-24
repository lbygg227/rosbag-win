cmake_minimum_required (VERSION 3.20.0)
project(roscpp_serialization)
find_package(Boost REQUIRED)

include_directories(include 
${catkin_INCLUDE_DIRS}
${ROS_COMMON}/include
${ROS_TIME}/include
${ROSCPP_TRAITS}/include
${ROSCPP_SERIALIZATION}/include
${ROSLZ4}/include
${Boost_INCLUDE_DIRS})
link_directories(${catkin_LIBRARY_DIRS})

add_library(roscpp_serialization src/serialization.cpp)

