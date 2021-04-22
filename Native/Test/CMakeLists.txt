cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME SDK_Native_Test)
set(IMPLEMENTATION_DIR "../Implementation")

include("../CMake/Version/CMakeLists.txt")

project(${PROJECT_NAME} VERSION "${VERSION_MAJOR}.${VERSION_MINOR}" DESCRIPTION "SDK native library test")

include("../CMake/Standard/CMakeLists.txt")
include("../CMake/Build_Type/CMakeLists.txt")
include("../CMake/Conan/CMakeLists.txt")
include("../CMake/Boost/CMakeLists.txt")
include("../CMake/Gtest/CMakeLists.txt")

include_directories(${PROJECT_SOURCE_DIR}/${IMPLEMENTATION_DIR})

file(GLOB LIB_SRC *.h *.cpp ${IMPLEMENTATION_DIR}/*.h ${IMPLEMENTATION_DIR}/*.cpp)
add_executable(${PROJECT_NAME} ${LIB_SRC})
target_link_libraries(

        ${PROJECT_NAME} PUBLIC
        CONAN_PKG::boost CONAN_PKG::openssl gtest_main
)

gtest_discover_tests(${PROJECT_NAME})
