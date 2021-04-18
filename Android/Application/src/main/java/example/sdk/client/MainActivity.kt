package example.sdk.client

import android.os.Bundle
import androidx.appcompat.app.AppCompatActivity
import example.sdk.SDK

class MainActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        setContentView(R.layout.activity_main)

        SDK.hello()
    }
}