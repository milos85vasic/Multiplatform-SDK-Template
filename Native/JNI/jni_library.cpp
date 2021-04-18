#include <jni.h>

#include "library.h"
#include "jni_library.h"

extern "C" JNIEXPORT void JNICALL Java_example_sdk_SDK_hello(JNIEnv *, jobject) {

    hello();
}


