if (ANDROID_BUILD)

    set(JAVA_JVM_LIBRARY NotNeeded)
    set(JAVA_AWT_LIBRARY NotNeeded)
    set(JAVA_INCLUDE_PATH2 NotNeeded)
    set(JAVA_AWT_INCLUDE_PATH NotNeeded)
endif ()

find_package(JNI)

include_directories(

        "${PROJECT_BINARY_DIR}"
        "${PROJECT_SOURCE_DIR}/${IMPLEMENTATION_DIR}"
        ${JNI_INCLUDE_DIRS}
        ${CMAKE_CURRENT_BINARY_DIR}
)