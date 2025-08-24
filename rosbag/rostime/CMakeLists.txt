cmake_minimum_required (VERSION 3.20.0)
project(rostime)

find_package(Boost REQUIRED)

include_directories(include ${catkin_INCLUDE_DIRS} 
${ROS_COMMON}/include
${ROS_TIME}/include
${ROSCPP_TRAITS}/include
${ROSCPP_SERIALIZATION}/include
${Boost_INCLUDE_DIRS})

add_library(rostime
  src/duration.cpp
  src/rate.cpp
  src/time.cpp)

target_link_libraries(rostime ${Boost_LIBRARIES})
if(NOT APPLE)
  target_link_libraries(rostime ${RT_LIBRARY})
endif()
