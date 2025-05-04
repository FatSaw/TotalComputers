/*
    Plugin for computers in vanilla minecraft!
    Copyright (C) 2022  JNNGL

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef TC_UTILS_H
#define TC_UTILS_H

#include <memory>
#include <cstring>
#include <jni.h>
#include <cstdlib>

#include "object.h"

char* FromJString(jstring jstr);
int* FromJIntArray(int* size, jintArray jarr);
float* FromJFloatArray(int* size, jfloatArray jarr);
double* FromJDoubleArray(int* size, jdoubleArray jarr);
char* FromJCharArray(int* size, jcharArray jarr);
signed char* FromJByteArray(int* size, jbyteArray jarr);
short* FromJShortArray(int* size, jshortArray jarr);
jlong* FromJLongArray(int* size, jlongArray jarr);
bool* FromJBooleanArray(int* size, jbooleanArray jarr);
char** FromJStringArray(int* size, jobjectArray jarr);
template<typename T> inline T* FromJObjectArray(int* size, jobjectArray jarr) {
    size[0] = tc::jEnv->GetArrayLength(jarr);
    T* arr = (T*)calloc(size[0], sizeof(T));
    for(int i = 0; i < size[0]; i++) {
        arr[i] = T(tc::jEnv->GetObjectArrayElement(jarr, i));
    }
    return arr;
}

jstring ToJString(const char* str);
jintArray ToJIntArray(int* arr, int arrc);
jfloatArray ToJFloatArray(float* arr, int arrc);
jdoubleArray ToJDoubleArray(double* arr, int arrc);
jcharArray ToJCharArray(const char* arr, int arrc);
jbyteArray ToJByteArray(signed char* arr, int arrc);
jshortArray ToJShortArray(short* arr, int arrc);
jlongArray ToJLongArray(jlong* arr, int arrc);
jbooleanArray ToJBooleanArray(bool* arr, int arrc);
jobjectArray ToJStringArray(const char** arr, int arrc);
template<typename T> inline jobjectArray ToJObjectArray(T* arr, int arrc) {
    jobjectArray jarr = tc::jEnv->NewObjectArray(arrc, tc::jEnv->GetObjectClass(arr[0].instance), 0);
    for(int i = 0; i < arrc; i++) {
        tc::jEnv->SetObjectArrayElement(jarr, i, arr[i].instance);
    }
    return jarr;
}

#endif
