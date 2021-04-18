cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME SDK_Native_Test)
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)

project(${PROJECT_NAME} VERSION "${VERSION_MAJOR}.${VERSION_MINOR}" DESCRIPTION "SDK native library test")

set(CMAKE_CXX_STANDARD 17)

# Access to shared library header files:
include_directories("/usr/local/include/SDK_Native")

# Link shared library:
link_directories("/usr/local/lib/SDK_Native")
link_libraries(SDK_Native)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME} test.cpp)

target_link_libraries(${PROJECT_NAME} gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
