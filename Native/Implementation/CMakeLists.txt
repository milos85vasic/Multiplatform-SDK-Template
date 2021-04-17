cmake_minimum_required(VERSION 3.10)
project(SDK_Native)

set(CMAKE_CXX_STANDARD 17)

set(SDK_Native_VERSION_MAJOR 1)
set(SDK_Native_VERSION_MINOR 0)

set(BOOST_ROOT "${PROJECT_SOURCE_DIR}/../../Boost")
set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
set(Boost_LIBRARY_DIR "${BOOST_ROOT}/libs")

find_package(Boost 1.71)

add_library(SDK_Native library.cpp library.h)

message("Include dir: ${Boost_INCLUDE_DIR}")
message("Library dir: ${Boost_LIBRARY_DIR}")

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

target_link_libraries(SDK_Native LINK_PUBLIC ${Boost_LIBRARIES})

