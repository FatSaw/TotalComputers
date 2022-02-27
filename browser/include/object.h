#ifndef TC_OBJECT_H
#define TC_OBJECT_H

#include <jni.h>
#include <vector>

#include "j_env.h"

#define tcClass jclass
#define tcMethods std::vector<jmethodID>
#define tcFields std::vector<jfieldID>

#define __FIELD__

struct NativeObject {
    tcClass clazz;
    tcMethods methods; 
    tcFields fields;
};

#define ADD_METHOD(object, desc) if(desc.isStatic) object.methods.push_back(tc::jEnv->GetStaticMethodID(object.clazz, desc.name, desc.signature)); \
    else object.methods.push_back(tc::jEnv->GetMethodID(object.clazz, desc.name, desc.signature));
#define ADD_FIELD(object, desc) if(desc.isStatic) object.fields.push_back(tc::jEnv->GetStaticFieldID(object.clazz, desc.name, desc.signature)); \
    else object.fields.push_back(tc::jEnv->GetFieldID(object.clazz, desc.name, desc.signature));
#define METHOD(object, id) instance, object.methods[id]
#define FIELD(object, id) instance, object.fields[id]

struct tcNativeDesc {
    const char* name;
    const char* signature;
    bool isStatic = false;
};

inline jclass tcInitNativeObject(NativeObject& dst, const char* clazz, std::vector<tcNativeDesc> methods, std::vector<tcNativeDesc> fields) {
    if(!dst.clazz) {
        dst.clazz = tc::jEnv->FindClass(clazz);

        for(tcNativeDesc method : methods) {
            ADD_METHOD(dst, method);
        }

        for(tcNativeDesc field : fields) {
            ADD_FIELD(dst, field);
        }
    }
    return dst.clazz;
}

class NativeObjectInstance {
public:
    NativeObjectInstance(jobject instance);
    NativeObjectInstance();
    ~NativeObjectInstance();

public:
    jobject instance;

};

#endif