cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME SDK_Native_JNI)

set(IMPLEMENTATION_DIR "../Implementation")

include("../CMake/Version/CMakeLists.txt")

project(${PROJECT_NAME} VERSION "${VERSION_MAJOR}.${VERSION_MINOR}" DESCRIPTION "SDK native JNI library")

include("../CMake/Standard/CMakeLists.txt")
include("../CMake/Build_Type/CMakeLists.txt")
include("../CMake/Toolchain/CMakeLists.txt")
include("../CMake/Conan/CMakeLists.txt")
include("../CMake/Boost/CMakeLists.txt")
include("../CMake/JNI/CMakeLists.txt")

file(GLOB LIB_SRC *.h *.cpp ${IMPLEMENTATION_DIR}/*.h ${IMPLEMENTATION_DIR}/*.cpp)
add_library(${PROJECT_NAME} SHARED ${LIB_SRC})
target_link_libraries(${PROJECT_NAME} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES})

include("../CMake/Install/CMakeLists.txt")


