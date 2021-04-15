cmake_minimum_required(VERSION 3.19)
project(SDK_Native_Test)

set(CMAKE_CXX_STANDARD 17)

set(SDK_Native_Test_VERSION_MAJOR 1)
set(SDK_Native_Test_VERSION_MINOR 0)


include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(SDK_Native_Test test.cpp)
target_link_libraries(SDK_Native_Test gtest_main)

include(GoogleTest)
gtest_discover_tests(SDK_Native_Test)
