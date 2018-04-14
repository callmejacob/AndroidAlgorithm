#include "common.h"

extern "C"
JNIEXPORT jstring

JNICALL
Java_com_hello_algorithm_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void

JNICALL
Java_com_hello_algorithm_MainActivity_sort(
        JNIEnv *env,
        jobject /* this */,
        jint type) {
    sort(type);
}
