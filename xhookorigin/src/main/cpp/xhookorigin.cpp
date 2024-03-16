#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_linshujie_xhookorigin_NativeLib_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_linshujie_nativehook_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI()
    return env->NewStringUTF("Hello from C++");
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_linshujie_nativehook_MainActivity_xhook_1register(JNIEnv *env, jobject thiz,
                                                           jstring pathname_regex_str,
                                                           jstring symbol, jstring new_func,
                                                           jstring old_func) {


}