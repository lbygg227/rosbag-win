cmake_minimum_required (VERSION 3.20.0)

project(rosbag_storage)

if(NOT WIN32)
  set_directory_properties(PROPERTIES COMPILE_OPTIONS "-Wall;-Wextra")
endif()

find_package(boost_format REQUIRED CONFIG)
find_package(BZip2 REQUIRED)

# Support large bags (>2GB) on 32-bit systems
add_definitions(-D_FILE_OFFSET_BITS=64)

message("----------------------------------------------------------: ${ROSCPP_TRAITS}")
include_directories(include 
${ROS_COMMON}/include
${ROS_TIME}/include
${ROSCPP_TRAITS}/include
${ROSCPP_SERIALIZATION}/include
${ROSLZ4}/include
${console_bridge_INCLUDE_DIRS} 
${BZIP2_INCLUDE_DIR})
add_definitions(${BZIP2_DEFINITIONS})

add_library(rosbag_storage
  src/bag.cpp
  src/bag_player.cpp
  src/buffer.cpp
  src/bz2_stream.cpp
  src/lz4_stream.cpp
  src/chunked_file.cpp
  src/message_instance.cpp
  src/query.cpp
  src/stream.cpp
  src/view.cpp
  src/uncompressed_stream.cpp
)

target_link_libraries(rosbag_storage ${BZIP2_LIBRARIES} Boost::format)
