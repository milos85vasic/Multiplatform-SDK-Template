cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME SDK_Native_JNI)
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)

project(${PROJECT_NAME} VERSION "${VERSION_MAJOR}.${VERSION_MINOR}" DESCRIPTION "SDK native JNI library")

set(CMAKE_CXX_STANDARD 17)

# Access to shared library header files:
include_directories("/usr/local/include/SDK_Native")

# Link shared library:
link_directories("/usr/local/lib/SDK_Native")
link_libraries(SDK_Native)

# Create shared library
file(GLOB LIB_SRC *.h *.cpp)
add_library(${PROJECT_NAME} SHARED ${LIB_SRC})
target_link_libraries(${PROJECT_NAME} ${SDK_Native})

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS *.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})


