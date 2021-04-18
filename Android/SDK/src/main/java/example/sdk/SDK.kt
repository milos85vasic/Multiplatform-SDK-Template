package example.sdk

import android.util.Log

object SDK {

    private val tag = SDK::class.simpleName

    init {

        System.loadLibrary("SDK_Native")
    }

    fun hello() {

        Log.v(tag, "")
    }
}