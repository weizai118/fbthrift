/*
 * Copyright 2018-present Facebook, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <thrift/lib/cpp2/transport/rocket/test/network/Util.h>

#include <algorithm>
#include <iterator>
#include <string>

#include <gtest/gtest.h>

#include <folly/ExceptionWrapper.h>
#include <folly/Range.h>
#include <folly/io/IOBuf.h>

#include <thrift/lib/cpp/transport/TTransportException.h>
#include <thrift/lib/cpp2/transport/rocket/RocketException.h>

namespace apache {
namespace thrift {
namespace rocket {
namespace test {

std::string repeatPattern(folly::StringPiece pattern, size_t nbytes) {
  std::string rv;
  rv.reserve(nbytes);
  for (size_t remaining = nbytes; remaining != 0;) {
    const size_t toCopy = std::min<size_t>(pattern.size(), remaining);
    std::copy_n(pattern.begin(), toCopy, std::back_inserter(rv));
    remaining -= toCopy;
  }
  return rv;
}

folly::StringPiece getRange(folly::IOBuf& iobuf) {
  return folly::StringPiece(iobuf.coalesce());
}

void expectTransportExceptionType(
    transport::TTransportException::TTransportExceptionType expectedType,
    folly::exception_wrapper ew) {
  const auto* const tex =
      dynamic_cast<transport::TTransportException*>(ew.get_exception());
  ASSERT_NE(nullptr, tex);
  EXPECT_EQ(expectedType, tex->getType());
}

void expectRocketExceptionType(
    ErrorCode expectedCode,
    folly::exception_wrapper ew) {
  const auto* const rex = dynamic_cast<RocketException*>(ew.get_exception());
  ASSERT_NE(nullptr, rex);
  EXPECT_EQ(expectedCode, rex->getErrorCode());
}

} // namespace test
} // namespace rocket
} // namespace thrift
} // namespace apache
