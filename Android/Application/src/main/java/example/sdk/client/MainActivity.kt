package example.sdk.client

import android.os.Bundle
import android.widget.Button
import androidx.appcompat.app.AppCompatActivity
import example.sdk.SDK

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContentView(R.layout.activity_main)

        val button = findViewById<Button>(R.id.execute_sdk_native_method)
        button.setOnClickListener {


            SDK.hello()
        }
    }
}