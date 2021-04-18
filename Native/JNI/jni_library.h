#include <jni.h>

#ifndef SDK_NATIVE_JNI_JNI_LIBRARY_H
#define SDK_NATIVE_JNI_JNI_LIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

extern "C" JNIEXPORT void JNICALL Java_example_sdk_SDK_hello(JNIEnv *, jobject);

extern "C" JNIEXPORT jstring JNICALL Java_example_sdk_SDK_getBoostVersion(JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif // SDK_NATIVE_JNI_JNI_LIBRARY_H
