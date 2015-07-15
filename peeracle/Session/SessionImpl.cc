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

#include "third_party/webrtc/talk/app/webrtc/peerconnectioninterface.h"
#include "third_party/webrtc/webrtc/base/thread.h"
#include "peeracle/Session/Session.h"
#include "peeracle/Session/SessionImpl.h"

namespace peeracle {

Session::SessionImpl::SessionImpl() : _signalingThread(NULL),
                                      _workerThread(NULL),
                                      _peerConnectionFactory(NULL) {
  rtc::ThreadManager::Instance()->WrapCurrentThread();

  _signalingThread = new rtc::Thread();
  _workerThread = new rtc::Thread();

  _signalingThread->SetName("signaling_thread", NULL);
  _workerThread->SetName("worker_thread", NULL);

  ASSERT(_signalingThread->Start() && _workerThread->Start());

  _peerConnectionFactory =
    webrtc::CreatePeerConnectionFactory(_signalingThread,
                                        _workerThread,
                                        NULL, NULL, NULL);
}

Session::SessionImpl::~SessionImpl() {
  _peerConnectionFactory->Release();

  _signalingThread->Stop();
  _workerThread->Stop();

  delete _signalingThread;
  delete _workerThread;

  _signalingThread = NULL;
  _workerThread = NULL;
}

bool Session::SessionImpl::Update() {
  rtc::Thread *thread = rtc::Thread::Current();

  return thread->ProcessMessages(0);
}

rtc::Thread *Session::SessionImpl::getSignalingThread() {
  return _signalingThread;
}

rtc::Thread *Session::SessionImpl::getWorkerThread() {
  return _workerThread;
}

}  // namespace peeracle
