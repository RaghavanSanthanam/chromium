// Copyright (c) 2009 The Chromium Authors. All rights reserved.  Use of this
// source code is governed by a BSD-style license that can be found in the
// LICENSE file.

#ifndef NET_FTP_FTP_DIRECTORY_LISTING_PARSERS_H_
#define NET_FTP_FTP_DIRECTORY_LISTING_PARSERS_H_

#include <queue>

#include "base/basictypes.h"
#include "base/string16.h"
#include "base/time.h"
#include "net/ftp/ftp_server_type_histograms.h"

namespace net {
  
struct FtpDirectoryListingEntry {
  enum Type {
    FILE,
    DIRECTORY,
    SYMLINK,
  };
  
  Type type;
  string16 name;
  
  // Last modified time, in local time zone.
  base::Time last_modified;
};

class FtpDirectoryListingParser {
 public:
  virtual ~FtpDirectoryListingParser();
  
  // Adds |line| to the internal parsing buffer. Returns true on success.
  virtual bool ConsumeLine(const string16& line) = 0;
  
  // Returns true if there is at least one FtpDirectoryListingEntry available.
  virtual bool EntryAvailable() const = 0;
  
  // Returns the next entry. It is an error to call this function unless
  // EntryAvailable returns true.
  virtual FtpDirectoryListingEntry PopEntry() = 0;
};
  
class FtpLsDirectoryListingParser : public FtpDirectoryListingParser {
 public:
  FtpLsDirectoryListingParser();
  
  // FtpDirectoryListingParser methods:
  virtual bool ConsumeLine(const string16& line);
  virtual bool EntryAvailable() const;
  virtual FtpDirectoryListingEntry PopEntry();
  
 private:
  std::queue<FtpDirectoryListingEntry> entries_;
  
  DISALLOW_COPY_AND_ASSIGN(FtpLsDirectoryListingParser);
};
  
}  // namespace net

#endif  // NET_FTP_FTP_DIRECTORY_LISTING_PARSERS_H_
