cmake_minimum_required (VERSION 3.20.0)

project(roslz4)

if(NOT WIN32)
  set_directory_properties(PROPERTIES COMPILE_OPTIONS "-Wall;-Wextra")
endif()


find_path(lz4_INCLUDE_DIRS NAMES lz4.h)
if (NOT lz4_INCLUDE_DIRS)
  message(FATAL_ERROR "lz4 includes not found")
endif()

find_library(lz4_LIBRARIES NAMES lz4)
if (NOT lz4_LIBRARIES)
  message(FATAL_ERROR "lz4 library not found")
endif()
set(lz4_FOUND TRUE)


include_directories(include ${lz4_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS})
add_library(roslz4 src/lz4s.c src/xxhash.c)
target_link_libraries(roslz4 ${lz4_LIBRARIES} ${catkin_LIBRARIES})

