if (CMAKE_BUILD_TYPE)

    message(STATUS "Cmake build type: ${CMAKE_BUILD_TYPE}")
else ()

    set(CMAKE_BUILD_TYPE Release)
    message(STATUS "Cmake build type: ${CMAKE_BUILD_TYPE}")
endif ()