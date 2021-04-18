#include <jni.h>

#include "library.h"
#include "jni_library.h"

extern "C" JNIEXPORT void JNICALL Java_example_sdk_SDK_hello(JNIEnv *env, jobject) {

    hello();
}

extern "C" JNIEXPORT jstring JNICALL Java_example_sdk_SDK_getBoostVersion(JNIEnv *env, jobject) {

    auto str = getBoostVersion();
    return env->NewStringUTF(str.c_str());
}


