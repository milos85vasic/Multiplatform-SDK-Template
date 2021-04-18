package example.sdk.client

import android.os.Bundle
import android.util.Log
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import example.sdk.SDK

class MainActivity : AppCompatActivity() {

    private val tag = MainActivity::class.simpleName

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContentView(R.layout.activity_main)

        val button = findViewById<Button>(R.id.execute_sdk_native_method)
        button.setOnClickListener {


            val boostInfo = SDK.getBoostInfo()
            Log.v(tag, "Boost version: ${boostInfo.version}")
        }
    }
}