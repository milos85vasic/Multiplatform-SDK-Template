set(BOOST_ROOT "${PROJECT_SOURCE_DIR}/../../Boost")
set(Boost_INCLUDE_DIR "${BOOST_ROOT}")

find_package(Boost REQUIRED)

include_directories(${Boost_INCLUDE_DIR})