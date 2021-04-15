cmake_minimum_required(VERSION 3.19)
project(SDK_Native)

set(CMAKE_CXX_STANDARD 17)

set(SDK_Native_VERSION_MAJOR 1)
set(SDK_Native_VERSION_MINOR 0)

find_package(Boost 1.71 REQUIRED)

add_library(SDK_Native library.cpp library.h)

include_directories(${Boost_INCLUDE_DIR})

target_link_libraries(SDK_Native LINK_PUBLIC ${Boost_LIBRARIES})

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
