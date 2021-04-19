#include <jni.h>

#include "library.h"
#include "jni_library.h"

extern "C" JNIEXPORT void JNICALL Java_example_sdk_SDK_hello(JNIEnv *env, jobject diz) {

    hello();
}

extern "C" JNIEXPORT jstring JNICALL
Java_example_sdk_SDK_getBoostVersion(JNIEnv *env, jobject diz) {

    auto str = getBoostVersion();
    return env->NewStringUTF(str.c_str());
}

extern "C" JNIEXPORT jobject JNICALL Java_example_sdk_SDK_getBoostInfo(JNIEnv *env, jobject diz) {

    auto info = BoostInfo();

    auto str = info.getBoostVersion();
    auto jStr = env->NewStringUTF(str.c_str());

    auto boostInfoClass = env->FindClass("example/sdk/model/BoostInfo");
    auto boostInfoObject = env->AllocObject(boostInfoClass);
    auto versionField = env->GetFieldID(boostInfoClass, "version", "Ljava/lang/String;");

    env->SetObjectField(boostInfoObject, versionField, jStr);
    return boostInfoObject;
}

extern "C" JNIEXPORT void JNICALL Java_example_sdk_SDK_tryCallback(

        JNIEnv *env, jobject diz, jobject callback
) {

    auto clb = [&env, &callback](bool success) {

        /*
            Command:

            javap -s ./SDK/build/tmp/kotlin-classes/debug/example/sdk/Callback.class

            Output:

            Compiled from "Callback.kt"
            public interface example.sdk.Callback {

              public abstract void onSuccess(boolean);
                descriptor: (Z)
            }
         */
        auto clazz = env->GetObjectClass(callback);
        if (env->IsInstanceOf(callback, clazz)) {

            auto methodId = env->GetMethodID(clazz, "onSuccess", "(Z)V");
            if (methodId != nullptr) {

                jboolean s(success);
                env->CallVoidMethod(callback, methodId, s);
            } else {

                // TODO: Handle error
            }
        } else {

            // TODO: Handle error
        }
    };

    tryCallback(clb);
}


