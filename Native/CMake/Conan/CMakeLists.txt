set(CONAN_DISABLE_CHECK_COMPILER "True")
execute_process (

        COMMAND bash -c "cd ${CMAKE_BINARY_DIR} && conan install .. --build missing"
        OUTPUT_VARIABLE CONAN_INSTALL_SUM
)
message("Conan installation summary:\n${CONAN_INSTALL_SUM}Conan installation summary - END")
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()