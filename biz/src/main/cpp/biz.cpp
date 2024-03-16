#include <jni.h>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <jni.h>
#include <android/log.h>
#include "../../../../xhookorigin/src/main/cpp/src/xhook.h"

#include <stdarg.h>

typedef int (*XhookFunction)(int, const char*, const char*, ...);

static int my_system_log_print(int prio, const char* tag, const char* fmt, ...)
{
    va_list ap;
    char buf[1024];
    int r;

    snprintf(buf, sizeof(buf), "[%s] %s", (NULL == tag ? "" : tag), (NULL == fmt ? "" : fmt));

    va_start(ap, fmt);
    r = __android_log_vprint(prio, "xhook_system", buf, ap);
    va_end(ap);
    return r;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_linshujie_biz_NativeLib_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_linshujie_biz_NativeLib_start(JNIEnv *env, jobject thiz) {
    XhookFunction  fun_ptr = my_system_log_print;
    xhook_register("^/system/.*\\.so$",  "__android_log_print", (void *)fun_ptr,  NULL);

}