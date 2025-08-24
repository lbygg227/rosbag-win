cmake_minimum_required (VERSION 3.20.0)
set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake)
project (test)

find_package(Boost REQUIRED)
find_package(RapidJSON CONFIG REQUIRED)

add_executable(rosbagtestmain main.cpp)

target_link_libraries(rosbagtestmain PRIVATE cpp_common rosbag_storage roscpp_serialization ros_msg_parser rostime roslz4 rapidjson)

target_include_directories(rosbagtestmain PRIVATE ${ROS_COMMON}/include
${ROS_TIME}/include
${ROSCPP_TRAITS}/include
${ROSCPP_SERIALIZATION}/include
${ROSLZ4}/include
${ROSBAG_STORAGE}/include
${ROS_MSG_PARSER}/include
${Boost_INCLUDE_DIRS}
${CMAKE_CURRENT_SOURCE_DIR}
${ROSBAG_READER}
${THIRD_PARTY_DIR}
)
