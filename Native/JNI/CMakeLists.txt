cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME SDK_Native_JNI)
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)

project(${PROJECT_NAME} VERSION "${VERSION_MAJOR}.${VERSION_MINOR}" DESCRIPTION "SDK native JNI library")

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "${PROJECT_SOURCE_DIR}/../../Boost")
set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
set(Boost_LIBRARY_DIR "${BOOST_ROOT}/libs")

find_package(Boost 1.71)

message("Boost library include dir: ${Boost_INCLUDE_DIR}")
message("Boost library library dir: ${Boost_LIBRARY_DIR}")

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

if(ANDROID_BUILD)

    set(JAVA_JVM_LIBRARY NotNeeded)
    set(JAVA_AWT_LIBRARY NotNeeded)
    set(JAVA_INCLUDE_PATH2 NotNeeded)
    set(JAVA_AWT_INCLUDE_PATH NotNeeded)
endif()

find_package(JNI)

include_directories(

        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/../Implementation"
        ${JNI_INCLUDE_DIRS}
        ${CMAKE_CURRENT_BINARY_DIR}
)

file(GLOB LIB_SRC *.h *.cpp ../Implementation/*.h ../Implementation/*.cpp)
add_library(${PROJECT_NAME} SHARED ${LIB_SRC})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES})

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS *.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})


