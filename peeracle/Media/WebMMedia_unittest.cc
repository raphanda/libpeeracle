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

#include "third_party/googletest/gtest/include/gtest/gtest.h"
#include "peeracle/DataStream/FileDataStream.h"
#include "peeracle/DataStream/MemoryDataStream.h"
#include "peeracle/Media/WebMMedia.h"

namespace peeracle {

namespace Media {

class WebMMediaTest : public testing::Test {
 protected:
  WebMMediaTest() : _media(NULL), _webmToTest(NULL) {
  }

  virtual void SetUp() {
    _media = new WebMMedia();
    _media->Load(NULL);

    _expectedTimecodes.push_back(0);
    _expectedTimecodes.push_back(2000);
    _expectedTimecodes.push_back(4000);
    _expectedTimecodes.push_back(6000);
    _expectedTimecodes.push_back(8000);
    _expectedTimecodes.push_back(10000);
    _expectedTimecodes.push_back(12000);
    _expectedTimecodes.push_back(14000);
    _expectedTimecodes.push_back(16000);
    _expectedTimecodes.push_back(18000);
    _expectedTimecodes.push_back(20000);
    _expectedTimecodes.push_back(22000);
    _expectedTimecodes.push_back(24000);
    _expectedTimecodes.push_back(26000);
    _expectedTimecodes.push_back(28000);
    _expectedTimecodes.push_back(30000);
    _expectedTimecodes.push_back(32000);
    _expectedTimecodes.push_back(34000);
    _expectedTimecodes.push_back(36000);
    _expectedTimecodes.push_back(38000);
    _expectedTimecodes.push_back(40000);
    _expectedTimecodes.push_back(42000);
    _expectedTimecodes.push_back(44000);
    _expectedTimecodes.push_back(46000);
    _expectedTimecodes.push_back(48000);
    _expectedTimecodes.push_back(50000);
    _expectedTimecodes.push_back(52000);
    _expectedTimecodes.push_back(54000);
    _expectedTimecodes.push_back(56000);
    _expectedTimecodes.push_back(58000);
  }

  virtual void TearDown() {
    delete _media;
  }

  const unsigned char _expectedInitBytes[4557] = {
    0x1a, 0x45, 0xdf, 0xa3, 0x9f, 0x42, 0x86, 0x81, 0x01, 0x42, 0xf7, 0x81,
    0x01, 0x42, 0xf2, 0x81, 0x04, 0x42, 0xf3, 0x81, 0x08, 0x42, 0x82, 0x84,
    0x77, 0x65, 0x62, 0x6d, 0x42, 0x87, 0x81, 0x02, 0x42, 0x85, 0x81, 0x02,
    0x18, 0x53, 0x80, 0x67, 0x01, 0x00, 0x00, 0x00, 0x01, 0xea, 0xa5, 0xe1,
    0x11, 0x4d, 0x9b, 0x74, 0xbc, 0x4d, 0xbb, 0x8b, 0x53, 0xab, 0x84, 0x15,
    0x49, 0xa9, 0x66, 0x53, 0xac, 0x81, 0x6e, 0x4d, 0xbb, 0x8b, 0x53, 0xab,
    0x84, 0x16, 0x54, 0xae, 0x6b, 0x53, 0xac, 0x81, 0xa2, 0x4d, 0xbb, 0x8c,
    0x53, 0xab, 0x84, 0x1f, 0x43, 0xb6, 0x75, 0x53, 0xac, 0x82, 0x11, 0x9d,
    0x4d, 0xbb, 0x8e, 0x53, 0xab, 0x84, 0x1c, 0x53, 0xbb, 0x6b, 0x53, 0xac,
    0x84, 0x01, 0xea, 0xa3, 0x7f, 0xec, 0xab, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x15, 0x49, 0xa9, 0x66, 0xaf, 0x2a, 0xd7, 0xb1, 0x83, 0x0f,
    0x42, 0x40, 0x44, 0x89, 0x84, 0x47, 0x6a, 0x38, 0x00, 0x4d, 0x80, 0x8f,
    0x6c, 0x69, 0x62, 0x77, 0x65, 0x62, 0x6d, 0x2d, 0x30, 0x2e, 0x32, 0x2e,
    0x31, 0x2e, 0x30, 0x57, 0x41, 0x8c, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x65,
    0x5f, 0x6d, 0x75, 0x78, 0x65, 0x72, 0x16, 0x54, 0xae, 0x6b, 0x50, 0xf5,
    0xae, 0xa1, 0xd7, 0x81, 0x01, 0x73, 0xc5, 0x87, 0x73, 0x31, 0xe7, 0x50,
    0x12, 0x54, 0xf7, 0x83, 0x81, 0x01, 0x86, 0x85, 0x56, 0x5f, 0x56, 0x50,
    0x39, 0xe0, 0x88, 0xb0, 0x82, 0x07, 0x80, 0xba, 0x82, 0x03, 0x58, 0xae,
    0x50, 0xcf, 0xd7, 0x81, 0x02, 0x73, 0xc5, 0x87, 0xc5, 0xca, 0x0e, 0x3a,
    0x07, 0x0d, 0x4e, 0x83, 0x81, 0x02, 0x86, 0x88, 0x41, 0x5f, 0x56, 0x4f,
    0x52, 0x42, 0x49, 0x53, 0x63, 0xa2, 0x50, 0xa2, 0x02, 0x1e, 0x55, 0x01,
    0x76, 0x6f, 0x72, 0x62, 0x69, 0x73, 0x00, 0x00, 0x00, 0x00, 0x02, 0x44,
    0xac, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff, 0x00, 0xf4, 0x01, 0x00, 0xff,
    0xff, 0xff, 0xff, 0xb8, 0x01, 0x03, 0x76, 0x6f, 0x72, 0x62, 0x69, 0x73,
    0x2c, 0x00, 0x00, 0x00, 0x58, 0x69, 0x70, 0x68, 0x2e, 0x4f, 0x72, 0x67,
    0x20, 0x6c, 0x69, 0x62, 0x56, 0x6f, 0x72, 0x62, 0x69, 0x73, 0x20, 0x49,
    0x20, 0x32, 0x30, 0x31, 0x35, 0x30, 0x31, 0x30, 0x35, 0x20, 0x28, 0xe2,
    0x9b, 0x84, 0xe2, 0x9b, 0x84, 0xe2, 0x9b, 0x84, 0xe2, 0x9b, 0x84, 0x29,
    0x01, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x65, 0x6e, 0x63, 0x6f,
    0x64, 0x65, 0x72, 0x3d, 0x4c, 0x61, 0x76, 0x63, 0x35, 0x36, 0x2e, 0x34,
    0x31, 0x2e, 0x31, 0x30, 0x30, 0x01, 0x05, 0x76, 0x6f, 0x72, 0x62, 0x69,
    0x73, 0x29, 0x42, 0x43, 0x56, 0x01, 0x00, 0x08, 0x00, 0x00, 0x80, 0x22,
    0x4c, 0x18, 0xc4, 0x80, 0xd0, 0x90, 0x55, 0x00, 0x00, 0x10, 0x00, 0x00,
    0xa0, 0xac, 0x37, 0x96, 0x7b, 0xc8, 0xbd, 0xf7, 0xde, 0x7b, 0x81, 0xa8,
    0x47, 0x14, 0x7b, 0x88, 0xbd, 0xf7, 0xde, 0x7b, 0xe3, 0xac, 0x47, 0xd0,
    0x7a, 0x88, 0xb9, 0xf7, 0xde, 0x7b, 0xee, 0xbd, 0xa7, 0x1a, 0x7b, 0xcb,
    0xbd, 0xf7, 0xde, 0x73, 0x20, 0x34, 0x64, 0x15, 0x00, 0x00, 0x04, 0x00,
    0x80, 0x29, 0x08, 0x9a, 0x72, 0xe0, 0x42, 0xea, 0xbd, 0xf7, 0x1e, 0x19,
    0xe6, 0x11, 0x51, 0x1a, 0x2a, 0xc7, 0xbd, 0xf7, 0x1e, 0x19, 0x85, 0x89,
    0x30, 0x94, 0x19, 0x85, 0x3d, 0x95, 0xda, 0x5a, 0xeb, 0x21, 0x93, 0xdc,
    0x42, 0xea, 0x3d, 0xe7, 0x1e, 0x08, 0x0d, 0x59, 0x05, 0x00, 0x00, 0x02,
    0x00, 0x40, 0x08, 0x21, 0x84, 0x14, 0x52, 0x48, 0x21, 0x85, 0x14, 0x52,
    0x48, 0x21, 0x85, 0x14, 0x52, 0x48, 0x29, 0xa5, 0x98, 0x62, 0x8a, 0x29,
    0xa6, 0x98, 0x62, 0xca, 0x29, 0xa7, 0x1c, 0x73, 0xcc, 0x31, 0xc7, 0x20,
    0x83, 0x0e, 0x3a, 0xe8, 0xa4, 0x93, 0x50, 0x42, 0x09, 0x29, 0xa4, 0x50,
    0x4a, 0x2a, 0xa9, 0xa4, 0x94, 0x52, 0x4a, 0x2d, 0xd6, 0x5a, 0x73, 0xee,
    0xbd, 0x07, 0xdd, 0x73, 0xef, 0x41, 0xf8, 0x20, 0x84, 0x10, 0x42, 0x08,
    0x21, 0x84, 0x10, 0x42, 0x08, 0x21, 0x84, 0x10, 0x42, 0x08, 0x42, 0x43,
    0x56, 0x01, 0x00, 0x20, 0x00, 0x00, 0x04, 0x42, 0x08, 0x21, 0x64, 0x10,
    0x42, 0x08, 0x21, 0x84, 0x14, 0x52, 0x48, 0x21, 0xa6, 0x98, 0x62, 0xca,
    0x29, 0xa7, 0x80, 0xd0, 0x90, 0x55, 0x00, 0x00, 0x20, 0x00, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x49, 0x91, 0x14, 0xcb, 0xb1, 0x1c, 0xcd, 0xd1, 0x1c,
    0xcd, 0xf1, 0x1c, 0xcf, 0x11, 0x25, 0x51, 0x12, 0x25, 0xd1, 0x32, 0x2d,
    0xd3, 0x52, 0x35, 0x53, 0x33, 0x3d, 0x55, 0x54, 0x45, 0xd5, 0x54, 0x55,
    0x57, 0x55, 0x5d, 0x5d, 0x77, 0x6d, 0xd5, 0x76, 0x6d, 0xd5, 0x96, 0x6d,
    0xd7, 0x56, 0x6d, 0xd5, 0x76, 0x6d, 0xd5, 0x56, 0x6d, 0x59, 0xb6, 0x6d,
    0xdb, 0xb6, 0x6d, 0xdb, 0xb6, 0x6d, 0xdb, 0xb6, 0x6d, 0xdb, 0xb6, 0x6d,
    0xdb, 0xb6, 0x6d, 0x20, 0x34, 0x64, 0x15, 0x00, 0x20, 0x01, 0x00, 0xa0,
    0x23, 0x39, 0x92, 0x23, 0x29, 0x92, 0x22, 0x29, 0x92, 0xe3, 0x38, 0x92,
    0x04, 0x84, 0x86, 0xac, 0x02, 0x00, 0x64, 0x00, 0x00, 0x04, 0x00, 0xa0,
    0x28, 0x8a, 0xe3, 0x38, 0x8e, 0xe4, 0x48, 0x8e, 0x25, 0x69, 0x92, 0x66,
    0x79, 0x96, 0x67, 0x89, 0x9a, 0xa8, 0x99, 0x9a, 0xe8, 0xa9, 0x9e, 0x0a,
    0x84, 0x86, 0xac, 0x02, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xe0, 0x78, 0x8a, 0xe7, 0x78, 0x8e, 0x67, 0x79, 0x92, 0xe7,
    0x78, 0x8e, 0x67, 0x79, 0x9a, 0xa7, 0x69, 0x9a, 0xa6, 0x69, 0x9a, 0xa6,
    0x69, 0x9a, 0xa6, 0x69, 0x9a, 0xa6, 0x69, 0x9a, 0xa6, 0x69, 0x9a, 0xa6,
    0x69, 0x9a, 0xa6, 0x69, 0x9a, 0xa6, 0x69, 0x9a, 0xa6, 0x69, 0x9a, 0xa6,
    0x69, 0x9a, 0xa6, 0x69, 0x9a, 0xa6, 0x69, 0x9a, 0xa6, 0x69, 0x9a, 0xa6,
    0x69, 0x40, 0x68, 0xc8, 0x2a, 0x00, 0x40, 0x02, 0x00, 0x40, 0xc7, 0x71,
    0x1c, 0xc7, 0x71, 0x1c, 0xc7, 0x71, 0x1c, 0x47, 0x72, 0x24, 0x07, 0x08,
    0x0d, 0x59, 0x05, 0x00, 0xc8, 0x00, 0x00, 0x08, 0x00, 0x40, 0x52, 0x24,
    0xc7, 0x72, 0x2c, 0x47, 0x73, 0x34, 0xc7, 0x73, 0x3c, 0x47, 0x74, 0x44,
    0xc7, 0x74, 0x4c, 0xc9, 0x94, 0x54, 0xc9, 0xb5, 0x5c, 0x0b, 0x08, 0x0d,
    0x59, 0x05, 0x00, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0x13, 0x2c, 0x45, 0x53, 0x3c, 0xc7, 0x93, 0x3c, 0xcf, 0x13, 0x35,
    0xcf, 0xd3, 0x34, 0xcd, 0x13, 0x4d, 0x51, 0x34, 0x4d, 0xd3, 0x34, 0x4d,
    0xd3, 0x34, 0x4d, 0xd3, 0x34, 0x4d, 0xd3, 0x34, 0x4d, 0xd3, 0x34, 0x4d,
    0xd3, 0x34, 0x4d, 0xd3, 0x34, 0x4d, 0xd3, 0x34, 0x4d, 0xd3, 0x34, 0x4d,
    0xd3, 0x34, 0x4d, 0xd3, 0x34, 0x4d, 0xd3, 0x34, 0x4d, 0x53, 0x14, 0x81,
    0xd0, 0x90, 0x55, 0x00, 0x00, 0x04, 0x00, 0x00, 0x21, 0x9d, 0x66, 0x96,
    0x6a, 0x80, 0x08, 0x33, 0x90, 0x61, 0x20, 0x34, 0x64, 0x15, 0x00, 0x80,
    0x00, 0x00, 0x00, 0x18, 0xa1, 0x08, 0x43, 0x0c, 0x08, 0x0d, 0x59, 0x05,
    0x00, 0x00, 0x04, 0x00, 0x00, 0x88, 0xa1, 0xe4, 0x20, 0x9a, 0xd0, 0x9a,
    0xf3, 0xcd, 0x39, 0x0e, 0x9a, 0xe5, 0xa0, 0xa9, 0x14, 0x9b, 0xd3, 0xc1,
    0x89, 0x54, 0x9b, 0x27, 0xb9, 0xa9, 0x98, 0x9b, 0x73, 0xce, 0x39, 0xe7,
    0x9c, 0x6c, 0xce, 0x19, 0xe3, 0x9c, 0x73, 0xce, 0x29, 0xca, 0x99, 0xc5,
    0xa0, 0x99, 0xd0, 0x9a, 0x73, 0xce, 0x49, 0x0c, 0x9a, 0xa5, 0xa0, 0x99,
    0xd0, 0x9a, 0x73, 0xce, 0x79, 0x12, 0x9b, 0x07, 0xad, 0xa9, 0xd2, 0x9a,
    0x73, 0xce, 0x19, 0xe7, 0x9c, 0x0e, 0xc6, 0x19, 0x61, 0x9c, 0x73, 0xce,
    0x69, 0xd2, 0x9a, 0x07, 0xa9, 0xd9, 0x58, 0x9b, 0x73, 0xce, 0x59, 0xd0,
    0x9a, 0xe6, 0xa8, 0xb9, 0x14, 0x9b, 0x73, 0xce, 0x89, 0x94, 0x9b, 0x27,
    0xb5, 0xb9, 0x54, 0x9b, 0x73, 0xce, 0x39, 0xe7, 0x9c, 0x73, 0xce, 0x39,
    0xe7, 0x9c, 0x73, 0xce, 0xa9, 0x5e, 0x9c, 0xce, 0xc1, 0x39, 0xe1, 0x9c,
    0x73, 0xce, 0x89, 0xda, 0x9b, 0x6b, 0xb9, 0x09, 0x5d, 0x9c, 0x73, 0xce,
    0xf9, 0x64, 0x9c, 0xee, 0xcd, 0x09, 0xe1, 0x9c, 0x73, 0xce, 0x39, 0xe7,
    0x9c, 0x73, 0xce, 0x39, 0xe7, 0x9c, 0x73, 0xce, 0x09, 0x42, 0x43, 0x56,
    0x01, 0x00, 0x40, 0x00, 0x00, 0x04, 0x61, 0xd8, 0x18, 0xc6, 0x9d, 0x82,
    0x20, 0x7d, 0x8e, 0x06, 0x62, 0x14, 0x21, 0xa6, 0x21, 0x93, 0x1e, 0x74,
    0x8f, 0x0e, 0x93, 0xa0, 0x31, 0xc8, 0x29, 0xa4, 0x1e, 0x8d, 0x8e, 0x46,
    0x4a, 0xa9, 0x83, 0x50, 0x52, 0x19, 0x27, 0xa5, 0x74, 0x82, 0xd0, 0x90,
    0x55, 0x00, 0x00, 0x20, 0x00, 0x00, 0x84, 0x10, 0x52, 0x48, 0x21, 0x85,
    0x14, 0x52, 0x48, 0x21, 0x85, 0x14, 0x52, 0x48, 0x21, 0x86, 0x18, 0x62,
    0x88, 0x21, 0xa7, 0x9c, 0x72, 0x0a, 0x2a, 0xa8, 0xa4, 0x92, 0x8a, 0x2a,
    0xca, 0x28, 0xb3, 0xcc, 0x32, 0xcb, 0x2c, 0xb3, 0xcc, 0x32, 0xcb, 0xac,
    0xc3, 0xce, 0x3a, 0xeb, 0xb0, 0xc3, 0x10, 0x43, 0x0c, 0x31, 0xb4, 0xd2,
    0x4a, 0x2c, 0x35, 0xd5, 0x56, 0x63, 0x8d, 0xb5, 0xe6, 0x9e, 0x73, 0xae,
    0x39, 0x48, 0x6b, 0xa5, 0xb5, 0xd6, 0x5a, 0x2b, 0xa5, 0x94, 0x52, 0x4a,
    0x29, 0xa5, 0x20, 0x34, 0x64, 0x15, 0x00, 0x00, 0x02, 0x00, 0x40, 0x20,
    0x64, 0x90, 0x41, 0x06, 0x19, 0x85, 0x14, 0x52, 0x48, 0x21, 0x86, 0x98,
    0x72, 0xca, 0x29, 0xa7, 0xa0, 0x82, 0x0a, 0x08, 0x0d, 0x59, 0x05, 0x00,
    0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0xf0, 0x24, 0xcf, 0x11, 0x1d,
    0xd1, 0x11, 0x1d, 0xd1, 0x11, 0x1d, 0xd1, 0x11, 0x1d, 0xd1, 0x11, 0x1d,
    0xcf, 0xf1, 0x1c, 0x51, 0x12, 0x25, 0x51, 0x12, 0x25, 0xd1, 0x32, 0x2d,
    0x53, 0x33, 0x3d, 0x55, 0x54, 0x55, 0x57, 0x76, 0x6d, 0x59, 0x97, 0x75,
    0xdb, 0xb7, 0x85, 0x5d, 0xd8, 0x75, 0xdf, 0xd7, 0x7d, 0xdf, 0xd7, 0x8d,
    0x5f, 0x17, 0x86, 0x65, 0x59, 0x96, 0x65, 0x59, 0x96, 0x65, 0x59, 0x96,
    0x65, 0x59, 0x96, 0x65, 0x59, 0x96, 0x65, 0x09, 0x42, 0x43, 0x56, 0x01,
    0x00, 0x20, 0x00, 0x00, 0x00, 0x42, 0x08, 0x21, 0x84, 0x14, 0x52, 0x48,
    0x21, 0x85, 0x94, 0x62, 0x8c, 0x31, 0xc7, 0x9c, 0x83, 0x4e, 0x42, 0x09,
    0x81, 0xd0, 0x90, 0x55, 0x00, 0x00, 0x20, 0x00, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x47, 0x71, 0x14, 0xc7, 0x91, 0x1c, 0xc9, 0x91, 0x24, 0x4b, 0xb2,
    0x24, 0x4d, 0xd2, 0x2c, 0xcd, 0xf2, 0x34, 0x4f, 0xf3, 0x34, 0xd1, 0x13,
    0x45, 0x51, 0x34, 0x4d, 0x53, 0x15, 0x5d, 0xd1, 0x15, 0x75, 0xd3, 0x16,
    0x65, 0x53, 0x36, 0x5d, 0xd3, 0x35, 0x65, 0xd3, 0x55, 0x65, 0xd5, 0x76,
    0x65, 0xd9, 0xb6, 0x65, 0x5b, 0xb7, 0x7d, 0x59, 0xb6, 0x7d, 0xdf, 0xf7,
    0x7d, 0xdf, 0xf7, 0x7d, 0xdf, 0xf7, 0x7d, 0xdf, 0xf7, 0x7d, 0xdf, 0xd7,
    0x75, 0x20, 0x34, 0x64, 0x15, 0x00, 0x20, 0x01, 0x00, 0xa0, 0x23, 0x39,
    0x92, 0x22, 0x29, 0x92, 0x22, 0x39, 0x8e, 0xe3, 0x48, 0x92, 0x04, 0x84,
    0x86, 0xac, 0x02, 0x00, 0x64, 0x00, 0x00, 0x04, 0x00, 0xa0, 0x28, 0x8e,
    0xe2, 0x38, 0x8e, 0x23, 0x49, 0x92, 0x24, 0x59, 0x92, 0x26, 0x79, 0x96,
    0x67, 0x89, 0x9a, 0xa9, 0x99, 0x9e, 0xe9, 0xa9, 0xa2, 0x0a, 0x84, 0x86,
    0xac, 0x02, 0x00, 0x00, 0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xa0, 0x68, 0x8a, 0xa7, 0x98, 0x8a, 0xa7, 0x88, 0x8a, 0xe7, 0x88, 0x8e,
    0x28, 0x89, 0x96, 0x69, 0x89, 0x9a, 0xaa, 0xb9, 0xa2, 0x6c, 0xca, 0xae,
    0xeb, 0xba, 0xae, 0xeb, 0xba, 0xae, 0xeb, 0xba, 0xae, 0xeb, 0xba, 0xae,
    0xeb, 0xba, 0xae, 0xeb, 0xba, 0xae, 0xeb, 0xba, 0xae, 0xeb, 0xba, 0xae,
    0xeb, 0xba, 0xae, 0xeb, 0xba, 0xae, 0xeb, 0xba, 0xae, 0xeb, 0xba, 0x40,
    0x68, 0xc8, 0x2a, 0x00, 0x40, 0x02, 0x00, 0x40, 0x47, 0x72, 0x24, 0x47,
    0x72, 0x24, 0x45, 0x52, 0x24, 0x45, 0x72, 0x24, 0x07, 0x08, 0x0d, 0x59,
    0x05, 0x00, 0xc8, 0x00, 0x00, 0x08, 0x00, 0xc0, 0x31, 0x1c, 0x43, 0x52,
    0x24, 0xc7, 0xb2, 0x2c, 0x4d, 0xf3, 0x34, 0x4f, 0xf3, 0x34, 0xd1, 0x13,
    0x3d, 0xd1, 0x33, 0x3d, 0x55, 0x74, 0x45, 0x17, 0x08, 0x0d, 0x59, 0x05,
    0x00, 0x00, 0x02, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x90,
    0x0c, 0x4b, 0xb1, 0x1c, 0xcd, 0xd1, 0x24, 0x51, 0x52, 0x2d, 0xd5, 0x52,
    0x35, 0xd5, 0x52, 0x2d, 0x55, 0x54, 0x3d, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0xd5, 0x34, 0x4d, 0xd3, 0x34, 0x81, 0xd0, 0x90,
    0x95, 0x00, 0x00, 0x19, 0x00, 0x00, 0xc3, 0xb4, 0xe4, 0xd2, 0x72, 0xcf,
    0x8d, 0xa0, 0x48, 0x2a, 0x47, 0xb5, 0xd6, 0x92, 0x51, 0xe5, 0x24, 0xc5,
    0x1c, 0x1a, 0x8a, 0xa0, 0x82, 0x56, 0x73, 0x0d, 0x15, 0x34, 0x88, 0x49,
    0x8b, 0x21, 0x62, 0x0a, 0x21, 0x26, 0x31, 0x96, 0x0e, 0x3a, 0xa6, 0x9c,
    0xd4, 0x1a, 0x53, 0x29, 0x19, 0x73, 0x54, 0x73, 0x6c, 0x21, 0x54, 0x88,
    0x49, 0x0d, 0x3a, 0xa6, 0x52, 0x29, 0x06, 0x2d, 0x08, 0x42, 0x43, 0x56,
    0x08, 0x00, 0xa1, 0x19, 0x00, 0x0e, 0xc7, 0x01, 0x24, 0xcb, 0x02, 0x24,
    0x4b, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0xd3, 0x00,
    0xcd, 0xf3, 0x00, 0xcb, 0xf3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0xd2, 0x34, 0xc0, 0xf2, 0x34, 0x40, 0xf3, 0x3c, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x4d, 0x03, 0x34, 0xcf, 0x03, 0x34,
    0xcf, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcd, 0xf3, 0x00,
    0x4f, 0x14, 0x01, 0x4f, 0x14, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xf2, 0x3c, 0xc0, 0x13, 0x3d, 0xc0, 0x13, 0x45, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x4d, 0x03, 0x34, 0xcf, 0x03, 0x34,
    0xcf, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xcb, 0xf3, 0x00,
    0x4f, 0x14, 0x01, 0xcf, 0x13, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x40, 0xf3, 0x3c, 0xc0, 0x13, 0x45, 0xc0, 0x13, 0x45, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x01, 0x0e, 0x00, 0x00, 0x01, 0x16, 0x42, 0xa1, 0x21,
    0x2b, 0x02, 0x80, 0x38, 0x01, 0x00, 0x87, 0x24, 0x41, 0x92, 0x20, 0x49,
    0xd0, 0x34, 0x80, 0x64, 0x59, 0xd0, 0x34, 0x68, 0x1a, 0x4c, 0x13, 0x20,
    0x59, 0x16, 0x34, 0x0d, 0x9a, 0x06, 0xd3, 0x04, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xf2, 0x34, 0x68, 0x1a, 0x34, 0x0d,
    0xa2, 0x08, 0x90, 0x34, 0x0f, 0x9a, 0x06, 0x4d, 0x83, 0x28, 0x02, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x69, 0x1a, 0x34,
    0x0d, 0x9a, 0x06, 0x51, 0x04, 0x48, 0x9a, 0x06, 0x4d, 0x83, 0xa6, 0x41,
    0x14, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd0,
    0x4c, 0x13, 0xa2, 0x08, 0x51, 0x84, 0x69, 0x02, 0x3c, 0xd3, 0x84, 0x28,
    0x42, 0x14, 0x61, 0x9a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x01, 0x07, 0x00, 0x80, 0x00, 0x13,
    0xca, 0x40, 0xa1, 0x21, 0x2b, 0x02, 0x80, 0x38, 0x01, 0x00, 0x87, 0xa2,
    0x58, 0x16, 0x00, 0x00, 0x38, 0x92, 0x63, 0x59, 0x00, 0x00, 0xe0, 0x38,
    0x92, 0x65, 0x01, 0x00, 0x80, 0x65, 0x59, 0xa2, 0x08, 0x00, 0x00, 0x96,
    0xa5, 0x89, 0x22, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x80, 0x01,
    0x07, 0x00, 0x80, 0x00, 0x13, 0xca, 0x40, 0xa1, 0x21, 0x2b, 0x01, 0x80,
    0x28, 0x00, 0x00, 0x87, 0xa2, 0x58, 0x16, 0x70, 0x1c, 0xcb, 0x02, 0x8e,
    0x63, 0x59, 0x40, 0x92, 0x2c, 0x0b, 0x60, 0x59, 0x00, 0xcd, 0x03, 0x68,
    0x1a, 0x40, 0x14, 0x01, 0x80, 0x00, 0x00, 0x80, 0x02, 0x07, 0x00, 0x80,
    0x00, 0x1b, 0x34, 0x25, 0x16, 0x07, 0x28, 0x34, 0x64, 0x25, 0x00, 0x10,
    0x05, 0x00, 0xe0, 0x50, 0x14, 0xcb, 0xd2, 0x34, 0x51, 0xe4, 0x38, 0x96,
    0xa5, 0x69, 0xa2, 0xc8, 0x91, 0x2c, 0x4b, 0xd3, 0x44, 0x91, 0x65, 0x69,
    0x9a, 0xe7, 0x99, 0x26, 0x34, 0xcd, 0xf3, 0x4c, 0x11, 0xa2, 0xe7, 0x79,
    0xa6, 0x09, 0xcf, 0xf3, 0x3c, 0xd3, 0x84, 0x69, 0x8a, 0xa2, 0xaa, 0x02,
    0x51, 0x34, 0x4d, 0x01, 0x00, 0x00, 0x05, 0x0e, 0x00, 0x00, 0x01, 0x36,
    0x68, 0x4a, 0x2c, 0x0e, 0x50, 0x68, 0xc8, 0x4a, 0x00, 0x20, 0x24, 0x00,
    0xc0, 0xe1, 0x38, 0x96, 0xe5, 0x79, 0xa2, 0xe8, 0x79, 0xa2, 0x68, 0x9a,
    0xaa, 0xca, 0x71, 0x2c, 0xcb, 0xf3, 0x44, 0x51, 0x14, 0x4d, 0x53, 0x55,
    0x55, 0x95, 0xe3, 0x68, 0x96, 0xe7, 0x89, 0xa2, 0x28, 0x9a, 0xa6, 0xaa,
    0xaa, 0x2a, 0xcb, 0xd2, 0x34, 0xcf, 0x13, 0x45, 0x51, 0x34, 0x4d, 0x55,
    0x55, 0x5d, 0x68, 0x9a, 0xe7, 0x89, 0xa2, 0x28, 0x9a, 0xa6, 0xaa, 0xba,
    0x2e, 0x3c, 0xcf, 0xf3, 0x44, 0x51, 0x14, 0x4d, 0x53, 0x55, 0x5d, 0x17,
    0x9e, 0xe7, 0x79, 0xa2, 0x28, 0x8a, 0xa6, 0xa9, 0xaa, 0xae, 0x0b, 0x51,
    0x14, 0x45, 0xd3, 0x34, 0x4d, 0x55, 0x55, 0x55, 0xd7, 0x05, 0xa2, 0x68,
    0x9a, 0xa6, 0xa9, 0xaa, 0xaa, 0xea, 0xba, 0x40, 0x14, 0x45, 0xd3, 0x34,
    0x55, 0x55, 0x55, 0x5d, 0x17, 0x88, 0xa2, 0x28, 0x9a, 0xa6, 0xaa, 0xaa,
    0xae, 0xeb, 0x02, 0xd3, 0x34, 0x4d, 0x55, 0x55, 0x55, 0xd7, 0x95, 0x5d,
    0x80, 0x69, 0xaa, 0xaa, 0xaa, 0xba, 0xae, 0xeb, 0x02, 0x54, 0x55, 0x55,
    0x5d, 0xd7, 0x75, 0x65, 0x19, 0xa0, 0xaa, 0xaa, 0xea, 0xba, 0xae, 0x2b,
    0xcb, 0x00, 0xd7, 0x75, 0x5d, 0xd7, 0x95, 0x65, 0x59, 0x06, 0xe0, 0xba,
    0xae, 0xeb, 0xca, 0xb2, 0x2c, 0x00, 0x00, 0xe0, 0xc0, 0x01, 0x00, 0x20,
    0xc0, 0x08, 0x3a, 0xc9, 0xa8, 0xb2, 0x08, 0x1b, 0x4d, 0xb8, 0xf0, 0x00,
    0x14, 0x1a, 0xb2, 0x22, 0x00, 0x88, 0x02, 0x00, 0x00, 0x8c, 0x61, 0x4a,
    0x31, 0xa5, 0x0c, 0x63, 0x12, 0x42, 0x0a, 0xa1, 0x61, 0x4c, 0x42, 0x48,
    0x21, 0x64, 0x52, 0x52, 0x2a, 0x29, 0xa5, 0x0a, 0x42, 0x2a, 0x25, 0x95,
    0x52, 0x41, 0x48, 0xa5, 0xa4, 0x52, 0x32, 0x4a, 0x2d, 0xa5, 0x96, 0x52,
    0x05, 0x21, 0x95, 0x92, 0x4a, 0xa9, 0x20, 0xa4, 0x52, 0x52, 0x29, 0x05,
    0x00, 0x80, 0x1d, 0x38, 0x00, 0x80, 0x1d, 0x58, 0x08, 0x85, 0x86, 0xac,
    0x04, 0x00, 0xf2, 0x00, 0x00, 0x08, 0x63, 0x94, 0x62, 0x8c, 0x31, 0xe7,
    0x24, 0x42, 0x4a, 0x31, 0xe6, 0x9c, 0x73, 0x12, 0x21, 0xa5, 0x18, 0x73,
    0xce, 0x39, 0xa9, 0x14, 0x63, 0xce, 0x39, 0xe7, 0x9c, 0x94, 0x92, 0x31,
    0xe7, 0x9c, 0x73, 0x4e, 0x4a, 0xe9, 0x98, 0x73, 0xce, 0x39, 0x27, 0xa5,
    0x64, 0xcc, 0x39, 0xe7, 0x9c, 0x93, 0x52, 0x3a, 0xe7, 0x9c, 0x73, 0xce,
    0x49, 0x29, 0xa5, 0x74, 0xce, 0x39, 0xe7, 0xa4, 0x94, 0x52, 0x42, 0xe8,
    0x1c, 0x74, 0x52, 0x4a, 0x29, 0x9d, 0x73, 0x0e, 0x42, 0x01, 0x00, 0x40,
    0x05, 0x0e, 0x00, 0x00, 0x01, 0x36, 0x8a, 0x6c, 0x4e, 0x30, 0x12, 0x54,
    0x68, 0xc8, 0x4a, 0x00, 0x20, 0x15, 0x00, 0xc0, 0xe0, 0x38, 0x96, 0xa5,
    0x69, 0x9e, 0x27, 0x8a, 0xa6, 0x69, 0x49, 0x92, 0xa6, 0x79, 0x9e, 0xe7,
    0x89, 0xa6, 0xaa, 0x6a, 0x92, 0xa4, 0x69, 0x9e, 0x27, 0x8a, 0xa6, 0xa9,
    0xaa, 0x3c, 0xcf, 0xf3, 0x44, 0x51, 0x14, 0x4d, 0x53, 0x55, 0x79, 0x9e,
    0xe7, 0x89, 0xa2, 0x28, 0x9a, 0xa6, 0xaa, 0x72, 0x5d, 0x51, 0x14, 0x45,
    0xd3, 0x34, 0x4d, 0x55, 0x25, 0xcb, 0xa2, 0x68, 0x8a, 0xa6, 0xa9, 0xaa,
    0xaa, 0x0b, 0xd3, 0x34, 0x4d, 0xd3, 0x54, 0x55, 0xd7, 0x85, 0x69, 0x9a,
    0xa6, 0x69, 0xaa, 0xaa, 0xeb, 0xc2, 0xb6, 0x55, 0x55, 0x55, 0x5d, 0xd7,
    0x75, 0x61, 0xdb, 0xaa, 0xaa, 0xaa, 0xae, 0xeb, 0xca, 0xc0, 0x75, 0x5d,
    0xd7, 0x75, 0x65, 0x19, 0xc8, 0xae, 0xeb, 0xba, 0xae, 0x2c, 0x0b, 0x00,
    0x00, 0x4f, 0x70, 0x00, 0x00, 0x2a, 0xb0, 0x61, 0x75, 0x84, 0x93, 0xa2,
    0xb1, 0xc0, 0x42, 0x43, 0x56, 0x02, 0x00, 0x19, 0x00, 0x00, 0x84, 0x31,
    0x08, 0x29, 0x84, 0x10, 0x52, 0xc8, 0x20, 0xa4, 0x10, 0x42, 0x48, 0x29,
    0x85, 0x90, 0x00, 0x00, 0x80, 0x01, 0x07, 0x00, 0x80, 0x00, 0x13, 0xca,
    0x40, 0xa1, 0x21, 0x2b, 0x01, 0x80, 0x54, 0x00, 0x00, 0x80, 0x10, 0x6b,
    0xad, 0xb5, 0xd6, 0x5a, 0x6b, 0x0d, 0x63, 0xd6, 0x5a, 0x6b, 0xad, 0xb5,
    0xd6, 0x12, 0xe7, 0xac, 0xb5, 0xd6, 0x5a, 0x6b, 0xad, 0xb5, 0xd6, 0x5a,
    0x6b, 0xad, 0xb5, 0xd6, 0x5a, 0x6b, 0xad, 0xb5, 0xd6, 0x5a, 0x6b, 0xad,
    0xb5, 0xd6, 0x5a, 0x6b, 0xad, 0xb5, 0xd6, 0x5a, 0x6b, 0xad, 0xb5, 0xd6,
    0x5a, 0x6b, 0xad, 0xb5, 0xd6, 0x5a, 0x6b, 0xad, 0xb5, 0xd6, 0x5a, 0x6b,
    0xad, 0xb5, 0xd6, 0x5a, 0x6b, 0xad, 0xb5, 0xd6, 0x5a, 0x6b, 0xad, 0xb5,
    0xd6, 0x5a, 0x6b, 0xad, 0xb5, 0xd6, 0x5a, 0x6b, 0xad, 0xb5, 0xd6, 0x5a,
    0x6b, 0xad, 0xb5, 0xd6, 0x5a, 0x6b, 0xad, 0xb5, 0xd6, 0x5a, 0x6b, 0xad,
    0xb5, 0xd6, 0x5a, 0x6b, 0xad, 0xb5, 0x56, 0x00, 0x20, 0x76, 0x85, 0x03,
    0xc0, 0x4e, 0x84, 0x0d, 0xab, 0x23, 0x9c, 0x14, 0x8d, 0x05, 0x16, 0x1a,
    0xb2, 0x12, 0x00, 0x08, 0x07, 0x00, 0x00, 0x8c, 0x41, 0x88, 0x31, 0xe8,
    0x24, 0x94, 0x52, 0x4a, 0x85, 0x10, 0x63, 0xd0, 0x49, 0x48, 0xa5, 0xb5,
    0x18, 0x2b, 0x84, 0x18, 0x83, 0x50, 0x4a, 0x4a, 0xad, 0xb5, 0x98, 0x3c,
    0xe7, 0x1c, 0x84, 0x52, 0x5a, 0x6a, 0x2d, 0xc6, 0xe4, 0x39, 0xe7, 0x20,
    0xa4, 0xd4, 0x5a, 0x8c, 0x31, 0x26, 0xd7, 0x42, 0x48, 0x29, 0xa5, 0x96,
    0x62, 0x8b, 0xb1, 0xb8, 0x16, 0x42, 0x2a, 0x29, 0xb5, 0xd6, 0x62, 0xac,
    0xc9, 0x18, 0x95, 0x52, 0x6a, 0x2d, 0xb6, 0x18, 0x6b, 0xed, 0xc5, 0xa8,
    0x94, 0x4a, 0x4b, 0x31, 0xc6, 0x18, 0x6b, 0x30, 0xc6, 0xe6, 0xd4, 0x5a,
    0x8c, 0x31, 0xd6, 0x5a, 0x8b, 0x31, 0x3a, 0xb7, 0x12, 0x4b, 0x8c, 0x31,
    0xc6, 0x5a, 0x84, 0x11, 0xc6, 0xc5, 0x16, 0x63, 0xac, 0xb5, 0xd7, 0x22,
    0x8c, 0x11, 0xb2, 0xc5, 0xd2, 0x5a, 0xad, 0xb5, 0x06, 0x63, 0x8c, 0xb1,
    0xb9, 0xb5, 0xd8, 0x6a, 0xcd, 0xb9, 0x18, 0x23, 0x8c, 0xae, 0x2d, 0xb5,
    0x56, 0x6b, 0xcd, 0x05, 0x00, 0x98, 0x3c, 0x38, 0x00, 0x40, 0x25, 0xd8,
    0x38, 0xc3, 0x4a, 0xd2, 0x59, 0xe1, 0x68, 0x70, 0xa1, 0x21, 0x2b, 0x01,
    0x80, 0xdc, 0x00, 0x00, 0x02, 0x21, 0xa5, 0x18, 0x63, 0xcc, 0x39, 0xe7,
    0x9c, 0x73, 0x0e, 0x42, 0x08, 0xa9, 0x52, 0x8c, 0x39, 0xe7, 0x1c, 0x84,
    0x10, 0x42, 0x08, 0xa1, 0x94, 0x52, 0x52, 0xa5, 0x18, 0x73, 0xce, 0x39,
    0x08, 0x21, 0x84, 0x50, 0x42, 0x29, 0xa5, 0xa4, 0x8c, 0x31, 0xe6, 0x1c,
    0x84, 0x10, 0x42, 0x08, 0xa5, 0x94, 0x52, 0x4a, 0x69, 0x29, 0x65, 0xcc,
    0x39, 0x08, 0x21, 0x84, 0x50, 0x4a, 0x29, 0xa5, 0x94, 0xd2, 0x52, 0xeb,
    0x9c, 0x73, 0x10, 0x42, 0x08, 0xa5, 0x94, 0x52, 0x4a, 0x29, 0x25, 0xa5,
    0xd4, 0x39, 0xe7, 0x20, 0x84, 0x50, 0x4a, 0x29, 0xa5, 0x94, 0x52, 0x4a,
    0x4a, 0x2d, 0x84, 0x10, 0x42, 0x28, 0xa1, 0x94, 0x52, 0x4a, 0x29, 0xa5,
    0x94, 0x94, 0x52, 0x4a, 0x21, 0x84, 0x50, 0x4a, 0x29, 0xa5, 0x94, 0x52,
    0x4a, 0x29, 0xa9, 0xa5, 0x94, 0x42, 0x08, 0xa5, 0x94, 0x52, 0x4a, 0x29,
    0xa5, 0x94, 0x52, 0x52, 0x4a, 0x29, 0x85, 0x10, 0x42, 0x29, 0xa5, 0x94,
    0x52, 0x4a, 0x29, 0xa5, 0xa4, 0x94, 0x5a, 0x2b, 0xa5, 0x94, 0x52, 0x4a,
    0x29, 0xa5, 0x94, 0x52, 0x4a, 0x49, 0x2d, 0xb5, 0x94, 0x52, 0x28, 0xa5,
    0x94, 0x52, 0x4a, 0x29, 0xa5, 0x94, 0x92, 0x5a, 0x4a, 0x29, 0xa5, 0x52,
    0x4a, 0x29, 0xa5, 0x94, 0x52, 0x4a, 0x29, 0x25, 0xa5, 0xd4, 0x52, 0x4a,
    0xa5, 0x94, 0x52, 0x4a, 0x29, 0xa5, 0x94, 0x52, 0x4a, 0x4b, 0xa9, 0xa5,
    0x94, 0x4a, 0x29, 0xa5, 0x94, 0x52, 0x4a, 0x29, 0xa5, 0x94, 0x94, 0x52,
    0x4a, 0x29, 0xa5, 0x54, 0x4a, 0x29, 0xa5, 0x94, 0x52, 0x4a, 0x29, 0x29,
    0xa5, 0xd4, 0x5a, 0x4a, 0x29, 0xa5, 0x94, 0x4a, 0x29, 0xa5, 0x94, 0x52,
    0x5a, 0x6b, 0x29, 0xa5, 0x96, 0x52, 0x2a, 0xa5, 0x94, 0x52, 0x4a, 0x29,
    0xa5, 0xb4, 0xd4, 0x5a, 0x6b, 0x2d, 0xb5, 0x94, 0x4a, 0x29, 0xa5, 0x94,
    0x52, 0x4a, 0x69, 0xad, 0xb5, 0x94, 0x52, 0x4a, 0x29, 0x95, 0x52, 0x4a,
    0x29, 0xa5, 0x94, 0x52, 0x00, 0x00, 0xd0, 0x81, 0x03, 0x00, 0x40, 0x80,
    0x11, 0x95, 0x16, 0x62, 0xa7, 0x19, 0x57, 0x1e, 0x81, 0x23, 0x0a, 0x19,
    0x26, 0xa0, 0x42, 0x43, 0x56, 0x02, 0x00, 0x64, 0x00, 0x00, 0x0c, 0xa3,
    0x94, 0x52, 0x49, 0x2d, 0x45, 0x82, 0x22, 0xa5, 0x18, 0xa4, 0x96, 0x42,
    0x25, 0x15, 0x73, 0x50, 0x52, 0x8a, 0x28, 0x73, 0x0e, 0x52, 0xac, 0xa9,
    0x42, 0xce, 0x20, 0xe6, 0x24, 0x95, 0x8a, 0x31, 0x84, 0x94, 0x83, 0x54,
    0x32, 0x07, 0x95, 0x52, 0xcc, 0x41, 0x0a, 0x21, 0x65, 0x4c, 0x29, 0x06,
    0xad, 0x95, 0x18, 0x3a, 0xc6, 0x98, 0xa3, 0x98, 0x6a, 0x2a, 0xa1, 0x63,
    0x0c, 0x00, 0x00, 0x00, 0x41, 0x00, 0x00, 0x81, 0x90, 0x09, 0x04, 0x0a,
    0xa0, 0xc0, 0x40, 0x06, 0x00, 0x1c, 0x20, 0x24, 0x48, 0x01, 0x00, 0x85,
    0x05, 0x86, 0x0e, 0x11, 0x22, 0x40, 0x8c, 0x02, 0x03, 0xe3, 0xe2, 0xd2,
    0x06, 0x00, 0x20, 0x08, 0x91, 0x19, 0x22, 0x11, 0xb1, 0x18, 0x24, 0x26,
    0x54, 0x03, 0x45, 0xc5, 0x74, 0x00, 0xb0, 0xb8, 0xc0, 0x90, 0x0f, 0x00,
    0x19, 0x1a, 0x1b, 0x69, 0x17, 0x17, 0xd0, 0x65, 0x80, 0x0b, 0xba, 0xb8,
    0xeb, 0x40, 0x08, 0x41, 0x08, 0x42, 0x10, 0x8b, 0x03, 0x28, 0x20, 0x01,
    0x07, 0x27, 0xdc, 0xf0, 0xc4, 0x1b, 0x9e, 0x70, 0x83, 0x13, 0x74, 0x8a,
    0x4a, 0x1d, 0x08, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03, 0x00, 0x3c, 0x00,
    0x00, 0x24, 0x1b, 0x40, 0x44, 0x44, 0x34, 0x73, 0x1c, 0x1d, 0x1e, 0x1f,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x02, 0x00, 0x00,
    0x00, 0x00, 0xe0, 0x06, 0x00, 0x1f, 0x00, 0x00, 0x49, 0x0a, 0x10, 0x11,
    0x11, 0xcd, 0x1c, 0x47, 0x87, 0xc7, 0x07, 0x48, 0x88, 0xc8, 0x08, 0x49,
    0x89, 0xc9, 0x09, 0x4a, 0x00, 0x00, 0x20, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x20, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0xe1, 0x8d, 0xb5, 0x84, 0x47, 0x2c,
    0x44, 0x00, 0x9f, 0x81, 0x02, 0x62, 0x64, 0x81, 0x20
  };

  const unsigned int _expectedInitLength = 4557;

  std::vector<uint32_t> _expectedTimecodes;

  WebMMedia *_media;
  DataStreamInterface *_webmToTest;
};

TEST_F(WebMMediaTest, getInitSegment) {
  DataStreamInit actualDSInit;
  DataStreamInterface *actualDS = new MemoryDataStream(actualDSInit);

  uint8_t *actualBytes;

  _media->getInitSegment(actualDS);

  ASSERT_EQ(_expectedInitLength, actualDS->length());

  actualBytes = new uint8_t[actualDS->length()];
  actualDS->read(reinterpret_cast<char*>(actualBytes), actualDS->length());

  for (std::streamsize i = 0; i < _expectedInitLength; ++i) {
    EXPECT_EQ(_expectedInitBytes[i], actualBytes[i]);
  }

  delete actualBytes;
  delete actualDS;
}

TEST_F(WebMMediaTest, getMediaSegment) {
  std::stringstream filestrm;
  const std::vector<uint32_t> &actualTimecodes = _media->getTimecodes();

  ASSERT_EQ(_expectedTimecodes.size(), actualTimecodes.size());
  for (size_t i = 0; i < _expectedTimecodes.size(); ++i) {
    EXPECT_EQ(_expectedTimecodes[i], actualTimecodes[i]);
  }
}

}  // namespace Media

}  // namespace peeracle
