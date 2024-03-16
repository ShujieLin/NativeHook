package com.linshujie.biz

class NativeLib {

    /**
     * A native method that is implemented by the 'biz' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    companion object {
        // Used to load the 'biz' library on application startup.
        init {
            System.loadLibrary("biz")
        }
    }
}