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

#include "java/jni/jni_helpers.h"
#include "peeracle/Metadata/MetadataStream.h"

#ifdef __cplusplus
extern "C" {
#endif

#define JOPMS(rettype, name) \
  rettype JNIEXPORT JNICALL Java_org_peeracle_MetadataStream_##name

static peeracle::MetadataStream *ExtractNativeMetadataStream(
  JNIEnv* jni, jobject j_MetadataStream) {
  jfieldID native_MetadataStream_id =
    GetFieldID(jni, GetObjectClass(jni, j_MetadataStream),
               "nativeMetadataStream", "J");
  jlong j_p = GetLongField(jni, j_MetadataStream, native_MetadataStream_id);
  return reinterpret_cast<peeracle::MetadataStream*>(j_p);
}

JOPMS(jchar, getType)(JNIEnv *jni, jobject j_this) {
  peeracle::MetadataStream *m =
    ExtractNativeMetadataStream(jni, j_this);
  return static_cast<jchar>(m->getType());
}

JOPMS(jstring, getMimeType)(JNIEnv *jni, jobject j_this) {
  peeracle::MetadataStream *m =
    ExtractNativeMetadataStream(jni, j_this);
  return JavaStringFromStdString(jni, m->getMimeType());
}

JOPMS(jlong, getBandwidth)(JNIEnv *jni, jobject j_this) {
  peeracle::MetadataStream *m =
    ExtractNativeMetadataStream(jni, j_this);
  return static_cast<jlong>(m->getBandwidth());
}

JOPMS(jint, getWidth)(JNIEnv *jni, jobject j_this) {
  peeracle::MetadataStream *m =
    ExtractNativeMetadataStream(jni, j_this);
  return static_cast<jint>(m->getWidth());
}

JOPMS(jint, getHeight)(JNIEnv *jni, jobject j_this) {
  peeracle::MetadataStream *m =
    ExtractNativeMetadataStream(jni, j_this);
  return static_cast<jint>(m->getHeight());
}

JOPMS(jint, getNumChannels)(JNIEnv *jni, jobject j_this) {
  peeracle::MetadataStream *m =
    ExtractNativeMetadataStream(jni, j_this);
  return static_cast<jint>(m->getNumChannels());
}

JOPMS(jint, getSamplingFrequency)(JNIEnv *jni, jobject j_this) {
  peeracle::MetadataStream *m =
    ExtractNativeMetadataStream(jni, j_this);
  return static_cast<jint>(m->getSamplingFrequency());
}

JOPMS(jlong, getChunkSize)(JNIEnv *jni, jobject j_this) {
  peeracle::MetadataStream *m =
    ExtractNativeMetadataStream(jni, j_this);
  return static_cast<jlong>(m->getChunkSize());
}

JOPMS(jbyteArray, getInitSegment)(JNIEnv *jni, jobject j_this) {
  peeracle::MetadataStream *m =
    ExtractNativeMetadataStream(jni, j_this);
  jbyteArray j_byteArray = jni->NewByteArray(static_cast<jsize>(m->getInitSegmentLength()));
  jni->SetByteArrayRegion(j_byteArray, 0, m->getInitSegmentLength(),
			  reinterpret_cast<const jbyte*>(m->getInitSegment()));
  // jbyte *bytes = jni->GetByteArrayElements(j_byteArray, NULL);
  // memcpy(bytes, m->getInitSegment(), m->getInitSegmentLength());
  // jni->ReleaseByteArrayElements(j_byteArray, bytes, JNI_ABORT);
  return j_byteArray;
}

JOPMS(jlong, getInitSegmentLength)(JNIEnv *jni, jobject j_this) {
  peeracle::MetadataStream *m =
    ExtractNativeMetadataStream(jni, j_this);
  return static_cast<jlong>(m->getInitSegmentLength());
}

JOPMS(jobject, getMediaSegments)(JNIEnv *jni, jobject j_this) {
  return NULL;
}

JOPMS(jboolean, unserialize)(JNIEnv *, jobject, jobject, jstring, jobject) {
  return static_cast<jboolean>(NULL);
}


#ifdef __cplusplus
}
#endif
