// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_EXTENSIONS_API_PERMISSIONS_PERMISSIONS_API_HELPERS_H_
#define CHROME_BROWSER_EXTENSIONS_API_PERMISSIONS_PERMISSIONS_API_HELPERS_H_
#pragma once

#include <string>
#include "base/memory/scoped_ptr.h"
#include "base/memory/ref_counted.h"

namespace base {
class DictionaryValue;
}

class ExtensionPermissionSet;

namespace extensions {

namespace api {
namespace permissions {
struct Permissions;
}
}

namespace permissions_api_helpers {

// Converts the permission |set| to a permissions object.
scoped_ptr<api::permissions::Permissions> PackPermissionSet(
    const ExtensionPermissionSet* set);

// Creates a permission set from |permissions|. Returns NULL if the permissions
// cannot be converted to a permission set, in which case |error| will be set.
scoped_refptr<ExtensionPermissionSet> UnpackPermissionSet(
    const api::permissions::Permissions& permissions, std::string* error);

}  // namespace permissions_api_helpers
}  // namespace extensions

#endif  // CHROME_BROWSER_EXTENSIONS_API_PERMISSIONS_PERMISSIONS_API_HELPERS_H_
