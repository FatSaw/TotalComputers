/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_jnngl_system_NativeWindowApplication */

#ifndef _Included_com_jnngl_system_NativeWindowApplication
#define _Included_com_jnngl_system_NativeWindowApplication
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_jnngl_system_NativeWindowApplication
 * Method:    _Init
 * Signature: (Ljava/lang/String;[Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_jnngl_system_NativeWindowApplication__1Init
  (JNIEnv *, jobject, jstring, jobjectArray);

/*
 * Class:     com_jnngl_system_NativeWindowApplication
 * Method:    _OnClose
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_jnngl_system_NativeWindowApplication__1OnClose
  (JNIEnv *, jobject);

/*
 * Class:     com_jnngl_system_NativeWindowApplication
 * Method:    _Update
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_jnngl_system_NativeWindowApplication__1Update
  (JNIEnv *, jobject);

/*
 * Class:     com_jnngl_system_NativeWindowApplication
 * Method:    _Render
 * Signature: (Ljava/awt/Graphics2D;)V
 */
JNIEXPORT void JNICALL Java_com_jnngl_system_NativeWindowApplication__1Render
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_jnngl_system_NativeWindowApplication
 * Method:    _ProcessInput
 * Signature: (IIZ)V
 */
JNIEXPORT void JNICALL Java_com_jnngl_system_NativeWindowApplication__1ProcessInput
  (JNIEnv *, jobject, jint, jint, jboolean);

#ifdef __cplusplus
}
#endif
#endif
