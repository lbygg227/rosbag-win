cmake_minimum_required (VERSION 3.20.0)
project(ros_msg_parser)
set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build.")
find_package(Boost REQUIRED)
find_package(boost_format REQUIRED CONFIG)
###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations

include_directories(
    include
    3rdparty
    ${Boost_INCLUDE_DIRS}
    ${ROS_COMMON}/include
    ${ROS_TIME}/include
    ${ROSCPP_TRAITS}/include
    ${ROSCPP_SERIALIZATION}/include
    ${ROSBAG_STORAGE}/include
    ${ROSLZ4}/include
    ${ROS_TOPIC_TYPE}/ros_type/geometry_msgs
)

## Declare a C++ library
 add_library(ros_msg_parser
   src/ros_type.cpp
   src/ros_field.cpp
   src/stringtree_leaf.cpp
   src/ros_message.cpp
   src/ros_parser.cpp
 )

#target_link_libraries(ros_msg_parser ${catkin_LIBRARIES} Boost::format)
target_link_libraries(ros_msg_parser  Boost::format)


find_package(benchmark CONFIG)
if (benchmark_FOUND)

    add_executable(ros_parser_benchmark tests/benchmark.cpp)
    add_dependencies(ros_parser_benchmark
        ${${PROJECT_NAME}_EXPORTED_TARGETS}
        ${catkin_EXPORTED_TARGETS})

    target_link_libraries(ros_parser_benchmark
        ros_msg_parser
        ${catkin_LIBRARIES}
        benchmark::benchmark
        pthread
        )
endif(benchmark_FOUND)

#add_executable(simple_example          example/simple.cpp)
#target_link_libraries(simple_example   ros_msg_parser ${catkin_LIBRARIES})

#add_executable(rosbag_example          example/rosbag_example.cpp)
#target_link_libraries(rosbag_example   ros_msg_parser ${catkin_LIBRARIES})

#add_executable(generic_subscriber        example/generic_subscriber.cpp)
#target_link_libraries(generic_subscriber ros_msg_parser ${catkin_LIBRARIES})

#add_executable(selective_deserialization )
#target_link_libraries(selective_deserialization   
#    ros_msg_parser 
#    rosbag_storage
#    roscpp_serialization
#    cpp_common
#    rostime
#    roslz4
#)
#target_include_directories(selective_deserialization
#                           PRIVATE ${ROS_TOPIC_TYPE}/ros_type ${ROSCPP_SERIALIZATION}/include
#)
#target_link_libraries(selective_deserialization ros_msg_parser ${catkin_LIBRARIES})


#############
## Testing ##
#############
if(CATKIN_ENABLE_TESTING)
  add_executable(ros_msg_parsing_test
    tests/deserializer_test.cpp
  )

  target_link_libraries(ros_msg_parsing_test
    ros_msg_parser
    gtest
    ${catkin_LIBRARIES}
  )
endif()

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executables and/or libraries for installati

