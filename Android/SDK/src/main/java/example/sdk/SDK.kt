package example.sdk

import example.sdk.model.BoostInfo
import java.util.concurrent.Executors

object SDK {

    init {

        System.loadLibrary("SDK_Native_JNI")
    }

    private val executor = Executors.newFixedThreadPool(5)

    external fun hello()

    external fun getBoostVersion(): String

    external fun getBoostInfo(): BoostInfo

    external fun tryCallback(callback: Callback)

    external fun tryHttpGet(callback: CallbackWithData)

    fun tryHttpGetAsync(callback: CallbackWithData) = executor.execute {

        tryHttpGet(callback)
    }
}