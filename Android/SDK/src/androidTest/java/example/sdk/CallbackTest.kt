package example.sdk

import org.junit.Test

import org.junit.Assert.*

class CallbackTest {

    @Test
    fun testCallback() {

        var executed = 0

        val callback = object : Callback {

            override fun onSuccess(success: Boolean) {

                assertEquals(true, success)
                executed++
            }
        }

        SDK.tryCallback(callback)
        assertEquals(1, executed)
    }
}