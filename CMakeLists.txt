cmake_minimum_required(VERSION 3.25.0)
if(DEFINED ENV{VCPKG_DIR})
    # 将 Windows 路径转换为 CMake 兼容的格式
    file(TO_CMAKE_PATH "$ENV{VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake" VCPKG_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE ${VCPKG_TOOLCHAIN_FILE})
else()
    message(WARNING "VCPKG_DIR environment variable is not set. vcpkg toolchain will not be used.")
endif()
project(fault_diagnosis CXX)
if (MSVC)
    # 设置源码字符集为 UTF-8
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")
    add_compile_options(/bigobj)

    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zm2000")
endif()

set(CMAKE_CXX_STANDARD 20)
#三方库目录
set(ROS_BAG_MODULE ${PROJECT_SOURCE_DIR}/rosbag)
set(COMMON ${PROJECT_SOURCE_DIR}/common)


set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(rosbag)