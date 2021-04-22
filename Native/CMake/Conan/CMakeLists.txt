set(CONAN_DISABLE_CHECK_COMPILER "True")

if (CONAN_BUILD_DIRECTORY)

    message("Conan build directory parameter is provided: '${CONAN_BUILD_DIRECTORY}'")
else ()

    set(CONAN_BUILD_DIRECTORY "${CMAKE_BINARY_DIR}")
    message("Conan build directory is default: '${CONAN_BUILD_DIRECTORY}'")
endif ()

if (CONAN_PROFILE)

    message("Conan profile parameter is provided: '${CONAN_PROFILE}'")
else ()

    set(CONAN_PROFILE "default")
    message("Conan profile is default: '${CONAN_PROFILE}'")
endif ()

execute_process (

        COMMAND bash -c "cd ${CONAN_BUILD_DIRECTORY} &&
            conan install .. --profile:host=default --profile:build=${CONAN_PROFILE} --build=missing"

        ECHO_OUTPUT_VARIABLE
        ECHO_ERROR_VARIABLE
)
include(${CONAN_BUILD_DIRECTORY}/conanbuildinfo.cmake)
conan_basic_setup()