// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "webkit/fileapi/file_system_callback_dispatcher.h"

#include "base/logging.h"

namespace fileapi {

FileSystemCallbackDispatcher::~FileSystemCallbackDispatcher() {
}

void FileSystemCallbackDispatcher::DidOpenFile(
    base::PlatformFile file,
    base::ProcessHandle peer_handle) {
  NOTREACHED();

  if (file != base::kInvalidPlatformFileValue)
    base::ClosePlatformFile(file);
}

}  // namespace fileapi
