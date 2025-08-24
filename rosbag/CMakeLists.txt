cmake_minimum_required (VERSION 3.20.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 修复C++20中std::allocator<void>::rebind兼容性问题
add_definitions(-D_HAS_AUTO_PTR_ETC=1)

set(ROS_COMMON ${ROS_BAG_MODULE}/cpp_common)
set(ROSBAG_STORAGE ${ROS_BAG_MODULE}/rosbag_storage)
set(ROSCPP_SERIALIZATION ${ROS_BAG_MODULE}/roscpp_serialization)
set(ROSCPP_TRAITS ${ROS_BAG_MODULE}/roscpp_traits)
set(ROS_MSG_PARSER ${ROS_BAG_MODULE}/ros_msg_parser)
set(ROS_TIME ${ROS_BAG_MODULE}/rostime)
set(ROSLZ4 ${ROS_BAG_MODULE}/roslz4)
set(ROSBAG_READER ${ROS_BAG_MODULE}/rosbag_reader)
set(ROS_TOPIC_TYPE ${ROS_BAG_MODULE}/ros_topic_type)

add_subdirectory (cpp_common)
add_subdirectory (ros_msg_parser)
add_subdirectory (rosbag_storage)
add_subdirectory (roscpp_serialization)
add_subdirectory (roscpp_traits)
add_subdirectory (rostime)
add_subdirectory (roslz4)
add_subdirectory (test)
