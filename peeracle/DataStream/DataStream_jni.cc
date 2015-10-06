/*
 * Copyright (c) 2015 peeracle contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifdef WEBRTC_ANDROID
#include <android/log.h>
#endif
#include "third_party/webrtc/webrtc/base/logging.h"
#include "java/jni/jni_helpers.h"
#include "peeracle/DataStream/DataStream.h"

namespace peeracle {

class JNIDataStream : public DataStream {
 public:
  JNIDataStream(JNIEnv *jni, jobject j_DataStream)
    : _j_global(jni, j_DataStream),
      _j_class(jni, GetObjectClass(jni, j_DataStream)) {
  }

  ~JNIDataStream() {
  }

  std::streamsize length() {
    jmethodID m = GetMethodID(jni(), *_j_class, "length", "()J");
    return jni()->CallLongMethod(*_j_global, m);
  }

  std::streamsize tell() {
    jmethodID m = GetMethodID(jni(), *_j_class, "tell", "()J");
    return jni()->CallLongMethod(*_j_global, m);
  }

  std::streamsize seek(std::streamsize position) {
    jmethodID m = GetMethodID(jni(), *_j_class, "seek", "(J)J");
    jlong j_position = static_cast<jlong>(position);
    return jni()->CallLongMethod(*_j_global, m, j_position);
  }

 private:
  std::streamsize vread(char *buffer, std::streamsize length) {
    JNIEnv *env = jni();
    jmethodID m = GetMethodID(env, *_j_class, "read", "(J)[B");

    CHECK_EXCEPTION(env) << "error during NewByteArray";
    jlong j_length = static_cast<jlong>(length);

    CHECK_EXCEPTION(env) << "error during GetByteArrayRegion";

    jbyteArray j_byteArray = reinterpret_cast<jbyteArray>
      (env->CallObjectMethod(*_j_global, m, j_length));

    CHECK_EXCEPTION(env) << "error during CallLongMethod";

    jbyte *bytes = env->GetByteArrayElements(j_byteArray, NULL);
    memcpy(buffer, bytes, length);

    env->ReleaseByteArrayElements(j_byteArray, bytes, JNI_ABORT);
    env->DeleteLocalRef(j_byteArray);
    CHECK_EXCEPTION(env) << "error during DeleteLocalRef";
    return static_cast<std::streamsize>(length);
  }

  std::streamsize vpeek(char *buffer, std::streamsize length) {
    /*jmethodID m = GetMethodID(jni(), *_j_class, "peek", "([BJ)J");
    jbyteArray j_buffer = jni()->NewByteArray(static_cast<jsize>(length));
    jlong j_length = static_cast<jlong>(length);

    jni()->GetByteArrayRegion(j_buffer, 0, static_cast<jsize>(length),
                              reinterpret_cast<jbyte*>(buffer));
    jlong ret = jni()->CallLongMethod(*_j_global, m, j_buffer, j_length);
    jni()->DeleteLocalRef(j_buffer);
    return static_cast<std::streamsize>(ret);*/
    JNIEnv *env = jni();
    jmethodID m = GetMethodID(env, *_j_class, "peek", "([BJ)[B");

    CHECK_EXCEPTION(env) << "error during NewByteArray";
    jlong j_length = static_cast<jlong>(length);

    CHECK_EXCEPTION(env) << "error during GetByteArrayRegion";

    jbyteArray j_buffer = jni()->NewByteArray(static_cast<jsize>(length));
    jni()->GetByteArrayRegion(j_buffer, 0, static_cast<jsize>(length),
                              reinterpret_cast<jbyte*>(buffer));

    jbyteArray j_byteArray = reinterpret_cast<jbyteArray>
    (env->CallObjectMethod(*_j_global, m, j_buffer, j_length));

    CHECK_EXCEPTION(env) << "error during CallLongMethod";

    jbyte *bytes = env->GetByteArrayElements(j_byteArray, NULL);
    memcpy(buffer, bytes, length);

    env->ReleaseByteArrayElements(j_byteArray, bytes, JNI_ABORT);
    env->DeleteLocalRef(j_byteArray);
    jni()->DeleteLocalRef(j_buffer);
    CHECK_EXCEPTION(env) << "error during DeleteLocalRef";
    return static_cast<std::streamsize>(length);
  }

  std::streamsize vwrite(const char *buffer, std::streamsize length) {
    jmethodID m = GetMethodID(jni(), *_j_class, "write", "([BJ)J");
    jbyteArray j_buffer = jni()->NewByteArray(static_cast<jsize>(length));
    jlong j_length = static_cast<jlong>(length);

    jni()->SetByteArrayRegion(j_buffer, 0, static_cast<jsize>(length),
                              reinterpret_cast<const jbyte*>(buffer));
    jlong ret = jni()->CallLongMethod(*_j_global, m, j_buffer, j_length);
    jni()->DeleteLocalRef(j_buffer);
    return static_cast<std::streamsize>(ret);
  }

  JNIEnv* jni() {
    return AttachCurrentThreadIfNeeded();
  }

  const ScopedGlobalRef<jobject> _j_global;
  const ScopedGlobalRef<jclass> _j_class;
};

}

#ifdef __cplusplus
extern "C" {
#endif

#define JOPD(rettype, name) \
  rettype JNIEXPORT JNICALL Java_org_peeracle_DataStream_##name

JOPD(jlong, nativeCreateDataStream)(JNIEnv *jni, jobject j_this) {
  peeracle::DataStream *dataStream = new peeracle::JNIDataStream(jni, j_this);
  return jlongFromPointer(dataStream);
}

#ifdef __cplusplus
}
#endif
