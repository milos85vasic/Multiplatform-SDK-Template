#include <jni.h>

#include "library.h"
#include "jni_library.h"

JNIEXPORT void JNICALL Java_example_sdk_SDK_hello(JNIEnv *, jobject) {

    hello();
}


