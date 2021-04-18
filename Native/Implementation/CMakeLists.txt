cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME SDK_Native)
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)

project(${PROJECT_NAME} VERSION "${VERSION_MAJOR}.${VERSION_MINOR}" DESCRIPTION "SDK native library")

set(CMAKE_CXX_STANDARD 17)

set(BOOST_ROOT "${PROJECT_SOURCE_DIR}/../../Boost")
set(Boost_INCLUDE_DIR "${BOOST_ROOT}")
set(Boost_LIBRARY_DIR "${BOOST_ROOT}/libs")

find_package(Boost 1.71)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

file(GLOB LIB_SRC *.h *.cpp)
add_library(${PROJECT_NAME} SHARED ${LIB_SRC})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

file(GLOB HEADERS *.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})

