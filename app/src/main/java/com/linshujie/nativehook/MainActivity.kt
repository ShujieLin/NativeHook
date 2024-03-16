package com.linshujie.nativehook

import android.app.Application
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.linshujie.biz.NativeLib
import com.linshujie.nativehook.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = "hello native hook"

        testNativeHook()
    }

    private fun testNativeHook() {
        XHook.getInstance().init(application)
        if (!XHook.getInstance().isInited) return

        XHook.getInstance().enableDebug(true)
        XHook.getInstance().enableSigSegvProtection(false)

        //load the target lib
        val nativeLib = NativeLib()
        nativeLib.start()

        XHook.getInstance().refresh(false)
    }
}


