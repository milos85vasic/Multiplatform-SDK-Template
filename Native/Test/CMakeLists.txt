cmake_minimum_required(VERSION 3.10)
project(SDK_Native_Test)

set(CMAKE_CXX_STANDARD 17)

set(SDK_Native_Test_VERSION_MAJOR 1)
set(SDK_Native_Test_VERSION_MINOR 0)

include_directories("../Implementation")

file(

        GLOB SDK_SRC
        "../Implementation/library.h"
        "../Implementation/library.cpp"
)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(BOOST_ROOT "${PROJECT_SOURCE_DIR}/../Boost")
set(BOOST_INCLUDE_DIRS "${BOOST_ROOT}/include")
set(BOOST_LIBRARY_DIRS "${BOOST_ROOT}/lib")

find_package(Boost 1.71 REQUIRED)

enable_testing()

add_executable(SDK_Native_Test ${SDK_SRC} test.cpp)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

target_link_libraries(SDK_Native_Test LINK_PUBLIC ${Boost_LIBRARIES} gtest_main)

include(GoogleTest)
gtest_discover_tests(SDK_Native_Test)
