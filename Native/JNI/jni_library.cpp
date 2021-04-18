#include <jni.h>

#include "library.h"
#include "jni_library.h"

extern "C" JNIEXPORT void JNICALL Java_example_sdk_SDK_hello(JNIEnv *env, jobject obj) {

    hello();
}

extern "C" JNIEXPORT jstring JNICALL Java_example_sdk_SDK_getBoostVersion(JNIEnv *env, jobject obj) {

    auto str = getBoostVersion();
    return env->NewStringUTF(str.c_str());
}

extern "C" JNIEXPORT jobject JNICALL Java_example_sdk_SDK_getBoostInfo(JNIEnv *env, jobject obj) {

    auto info = BoostInfo();

    auto str = info.getBoostVersion();
    auto jStr = env->NewStringUTF(str.c_str());

    auto boostInfoClass = env->FindClass("example/sdk/model/BoostInfo");
    auto boostInfoObject = env->AllocObject(boostInfoClass);
    auto versionField = env->GetFieldID(boostInfoClass, "version", "Ljava/lang/String;");

    env->SetObjectField(boostInfoObject, versionField, jStr);
    return boostInfoObject;
}


