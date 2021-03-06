set(CONAN_DISABLE_CHECK_COMPILER "True")

if (ANDROID_BUILD)

    STRING(TOLOWER ${CMAKE_BUILD_TYPE} CBT)
    set(CONAN_BUILD_DIRECTORY "${CMAKE_SOURCE_DIR}/conan-build-${CBT}-${CMAKE_ANDROID_ARCH_ABI}")
    set(CONAN_PROFILE "android_${CMAKE_ANDROID_ARCH_ABI}")
    set(CONAN_PROFILE_HOST "default") # TODO: 'default or 'linux' profile file to use

    message(STATUS "Conan build directory parameter is provided: '${CONAN_BUILD_DIRECTORY}'")
    message(STATUS "Conan profile parameter is provided: '${CONAN_PROFILE}'")
else ()

    set(CONAN_BUILD_DIRECTORY "${CMAKE_BINARY_DIR}")
    message(STATUS "Conan build directory is default: '${CONAN_BUILD_DIRECTORY}'")

    set(CONAN_PROFILE "default") # TODO: 'default or 'linux' profile file to use
    set(CONAN_PROFILE_HOST "default")
    message(STATUS "Conan profile is default: '${CONAN_PROFILE}'")
endif ()

execute_process (

        COMMAND bash -c "cd ${CONAN_BUILD_DIRECTORY} &&
            conan install .. --profile=${CONAN_PROFILE} --profile:build=${CONAN_PROFILE_HOST} --build=missing"

        ECHO_OUTPUT_VARIABLE
        ECHO_ERROR_VARIABLE
)

include(${CONAN_BUILD_DIRECTORY}/conanbuildinfo.cmake)
set(CMAKE_CXX_COMPILER_VERSION "5.0")
conan_basic_setup(TARGETS)