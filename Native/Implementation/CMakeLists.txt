cmake_minimum_required(VERSION 3.19)
project(SDK_Native)

set(CMAKE_CXX_STANDARD 17)

set(SDK_Native_VERSION_MAJOR 1)
set(SDK_Native_VERSION_MINOR 0)

find_package(Boost 1.71 REQUIRED)

add_library(SDK_Native library.cpp library.h)

include_directories(${Boost_INCLUDE_DIR})

target_link_libraries(SDK_Native LINK_PUBLIC ${Boost_LIBRARIES})

