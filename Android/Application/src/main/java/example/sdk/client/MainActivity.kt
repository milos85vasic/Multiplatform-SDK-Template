package example.sdk.client

import android.os.Bundle
import android.util.Log
import android.widget.Button
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import example.sdk.Callback
import example.sdk.CallbackWithData
import example.sdk.SDK

class MainActivity : AppCompatActivity() {

    private val tag = MainActivity::class.simpleName

    private val callback = object : Callback {

        override fun onSuccess(success: Boolean) {

            val msg = "Callback executed: (success=$success)"

            Log.v(tag, msg)

            Toast
                .makeText(this@MainActivity, msg, Toast.LENGTH_SHORT)
                .show()
        }
    }

    private val callbackWithData = object : CallbackWithData {

        override fun onSuccess(success: Boolean, data: String) {

            val msg = "Callback with data executed: (success=$success, data=${data.length})"

            Log.v(tag, msg)

            runOnUiThread {

                Toast
                    .makeText(this@MainActivity, msg, Toast.LENGTH_SHORT)
                    .show()
            }
        }
    }

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContentView(R.layout.activity_main)

        val btnNativeMethod = findViewById<Button>(R.id.execute_sdk_native_method)
        btnNativeMethod.setOnClickListener {


            val boostInfo = SDK.getBoostInfo()
            val msg = "Boost version: ${boostInfo.version}"

            Log.v(tag, msg)

            Toast
                .makeText(this, msg, Toast.LENGTH_SHORT)
                .show()
        }

        val btnNativeCallback = findViewById<Button>(R.id.execute_sdk_native_method_with_callback)
        btnNativeCallback.setOnClickListener {

            SDK.tryCallback(callback)
        }

        val btnNativeHttpsCall = findViewById<Button>(R.id.execute_native_https_call)
        btnNativeHttpsCall.setOnClickListener {

            SDK.tryHttpGetAsync(callbackWithData)
        }
    }
}