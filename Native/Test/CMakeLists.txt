cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME SDK_Native_Test)
set(IMPLEMENTATION_DIR "../Implementation")

include("../CMake/Version/CMakeLists.txt")

project(${PROJECT_NAME} VERSION "${VERSION_MAJOR}.${VERSION_MINOR}" DESCRIPTION "SDK native library test")

include("../CMake/Standard/CMakeLists.txt")
include("../CMake/Build_Type/CMakeLists.txt")
include("../CMake/Conan/CMakeLists.txt")
include("../CMake/Boost/CMakeLists.txt")

include_directories(${PROJECT_SOURCE_DIR}/${IMPLEMENTATION_DIR})

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB LIB_SRC *.h *.cpp ${IMPLEMENTATION_DIR}/*.h ${IMPLEMENTATION_DIR}/*.cpp)
add_executable(${PROJECT_NAME} ${LIB_SRC})
target_link_libraries(

        ${PROJECT_NAME} PUBLIC
        OpenSSL::SSL OpenSSL::Crypto
        Boost::program_options Boost::system Boost::boost
        Boost::thread Boost::filesystem Boost::headers gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
