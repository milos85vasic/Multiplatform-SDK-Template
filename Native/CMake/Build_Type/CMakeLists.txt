if (CMAKE_BUILD_TYPE)

    message("Cmake build type: ${CMAKE_BUILD_TYPE}")
else ()

    set(CMAKE_BUILD_TYPE RelWithDebInfo)
    message("Cmake build type: ${CMAKE_BUILD_TYPE}")
endif ()