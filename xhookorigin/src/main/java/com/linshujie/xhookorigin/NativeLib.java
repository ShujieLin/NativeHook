package com.linshujie.xhookorigin;

public class NativeLib {

    // Used to load the 'xhookorigin' library on application startup.
    static {
        System.loadLibrary("xhookorigin");
    }

    /**
     * A native method that is implemented by the 'xhookorigin' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}