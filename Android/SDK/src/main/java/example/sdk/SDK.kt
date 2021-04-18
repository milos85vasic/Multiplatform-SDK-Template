package example.sdk

object SDK {

    init {

        System.loadLibrary("SDK_Native_JNI")
    }

    external fun hello()
}