cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME SDK_Native)

include("../CMake/Version/CMakeLists.txt")

project(${PROJECT_NAME} VERSION "${VERSION_MAJOR}.${VERSION_MINOR}" DESCRIPTION "SDK native library")

include("../CMake/Standard/CMakeLists.txt")
include("../CMake/Build_Type/CMakeLists.txt")
include("../CMake/Boost/CMakeLists.txt")
include("../CMake/Conan/CMakeLists.txt")

file(GLOB LIB_SRC *.h *.cpp)
add_library(${PROJECT_NAME} SHARED ${LIB_SRC})
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

include("../CMake/Install/CMakeLists.txt")

