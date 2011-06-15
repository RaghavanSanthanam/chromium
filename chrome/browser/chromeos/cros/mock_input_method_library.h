// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_CHROMEOS_CROS_MOCK_INPUT_METHOD_LIBRARY_H_
#define CHROME_BROWSER_CHROMEOS_CROS_MOCK_INPUT_METHOD_LIBRARY_H_
#pragma once

#include <set>
#include <string>

#include "chrome/browser/chromeos/cros/input_method_library.h"
#include "googleurl/src/gurl.h"
#include "testing/gmock/include/gmock/gmock.h"

namespace chromeos {

class MockInputMethodLibrary : public InputMethodLibrary {
 public:
  MockInputMethodLibrary();
  virtual ~MockInputMethodLibrary();

  MOCK_METHOD1(AddObserver, void(Observer*));
  MOCK_METHOD1(AddVirtualKeyboardObserver, void(VirtualKeyboardObserver*));
  MOCK_METHOD1(RemoveObserver, void(Observer*));
  MOCK_METHOD1(RemoveVirtualKeyboardObserver, void(VirtualKeyboardObserver*));

  MOCK_METHOD0(GetActiveInputMethods,
               input_method::InputMethodDescriptors*(void));
  MOCK_METHOD0(GetNumActiveInputMethods, size_t(void));
  MOCK_METHOD0(GetSupportedInputMethods,
               input_method::InputMethodDescriptors*(void));
  MOCK_METHOD1(ChangeInputMethod, void(const std::string&));
  MOCK_METHOD2(SetImePropertyActivated, void(const std::string&, bool));
  MOCK_METHOD1(InputMethodIsActivated, bool(const std::string&));
  MOCK_METHOD3(SetImeConfig, bool(const std::string&, const std::string&,
                                  const input_method::ImeConfigValue&));
  MOCK_CONST_METHOD0(previous_input_method,
                     input_method::InputMethodDescriptor(void));
  MOCK_CONST_METHOD0(current_input_method,
                     input_method::InputMethodDescriptor(void));
  MOCK_CONST_METHOD0(current_ime_properties,
                     const input_method::ImePropertyList&(void));
  MOCK_METHOD1(GetKeyboardOverlayId, std::string(const std::string&));
  MOCK_METHOD0(StartInputMethodDaemon, bool(void));
  MOCK_METHOD0(StopInputMethodDaemon, void(void));
  MOCK_METHOD1(SetDeferImeStartup, void(bool));
  MOCK_METHOD1(SetEnableAutoImeShutdown, void(bool));
  MOCK_METHOD1(SendHandwritingStroke,
               void(const input_method::HandwritingStroke&));
  MOCK_METHOD1(CancelHandwritingStrokes, void(int));
  MOCK_METHOD3(RegisterVirtualKeyboard, void(const GURL&,
                                             const std::set<std::string>&,
                                             bool));
};

}  // namespace chromeos

#endif  // CHROME_BROWSER_CHROMEOS_CROS_MOCK_INPUT_METHOD_LIBRARY_H_
