#include <jni.h>

#ifndef SDK_NATIVE_JNI_JNI_LIBRARY_H
#define SDK_NATIVE_JNI_JNI_LIBRARY_H

#ifdef __cplusplus
extern "C" {
#endif

extern "C" JNIEXPORT void JNICALL Java_example_sdk_SDK_hello(JNIEnv *env, jobject obj);

extern "C" JNIEXPORT jstring JNICALL Java_example_sdk_SDK_getBoostVersion(JNIEnv *env, jobject obj);

extern "C" JNIEXPORT jobject JNICALL Java_example_sdk_SDK_getBoostInfo(JNIEnv *env, jobject obj);

#ifdef __cplusplus
}
#endif
#endif // SDK_NATIVE_JNI_JNI_LIBRARY_H
