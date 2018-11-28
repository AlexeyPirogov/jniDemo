#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "jnidemo_JNIDemoJava.h"

JNIEXPORT jint JNICALL Java_jnidemo_JNIDemoJava_nativeCrash(JNIEnv *env, jobject obj) {
      const char *s = NULL;
      printf( "%c\n", s[0] );
      return 0;
}


JNIEXPORT jint JNICALL Java_jnidemo_JNIDemoJava_nativePrint(JNIEnv *env, jobject obj) {
    printf("\nHello World from C!\n");
    return 0;
}

JNIEXPORT jint JNICALL Java_jnidemo_JNIDemoJava_nativeSleep(JNIEnv *env, jobject obj, jint ms) {
    usleep(ms);
    return 0;
}

JNIEXPORT jobjectArray internalNativeAllocate(JNIEnv const *env, jint objNumber) {
    jclass classDouble = (*env)->FindClass(env, "java/lang/Double");
    jobjectArray outJNIArray = (*env)->NewObjectArray(env, objNumber, classDouble, NULL);

    for (int i = 0; i < objNumber; i++) {
        jmethodID midDoubleInit = (*env)->GetMethodID(env, classDouble, "<init>", "(D)V");
        if (NULL == midDoubleInit) return NULL;
        jobject iDouble = (*env)->NewObject(env, classDouble, midDoubleInit, (double) i);
        (*env)->SetObjectArrayElement(env, outJNIArray, i, iDouble);
    }

    return outJNIArray;
}

jobjectArray JNICALL Java_jnidemo_JNIDemoJava_nativeAllocate(JNIEnv *env, jobject obj, jint objNumber) {
    return internalNativeAllocate(env, objNumber);
}

