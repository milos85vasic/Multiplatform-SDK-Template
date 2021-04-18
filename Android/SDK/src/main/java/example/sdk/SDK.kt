package example.sdk

import example.sdk.model.BoostInfo

object SDK {

    init {

        System.loadLibrary("SDK_Native_JNI")
    }

    external fun hello()

    external fun getBoostVersion(): String

    external fun getBoostInfo(): BoostInfo
}