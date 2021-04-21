package example.sdk

import org.junit.Assert
import org.junit.Test

class NativeHttpsCallTest {

    @Test
    fun testNativeHttpsCall() {

        var executed = 0

        val callback = object : CallbackWithData {

            override fun onSuccess(success: Boolean, data: String) {

                Assert.assertEquals(true, success)
                Assert.assertTrue(data.isNotEmpty())
                Assert.assertTrue(data.isNotBlank())
                executed++
            }
        }

        SDK.tryHttpGet(callback)
        Assert.assertEquals(1, executed)
    }

    @Test
    fun testNativeHttpsCallAsync() {

        var executed = 0

        val callback = object : CallbackWithData {

            override fun onSuccess(success: Boolean, data: String) {

                Assert.assertEquals(true, success)
                Assert.assertTrue(data.isNotEmpty())
                Assert.assertTrue(data.isNotBlank())
                executed++
            }
        }

        SDK.tryHttpGetAsync(callback)

        while (executed == 0) {

            Thread.yield()
        }

        Assert.assertEquals(1, executed)
    }
}