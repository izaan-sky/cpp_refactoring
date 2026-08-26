#pragma once

#include <string>

namespace refactoring::legacycode::detail {

// Performs a blocking HTTPS GET against host+path and returns the response body.
// Platform-specific implementation: HttpGet_win.cpp (WinHTTP) or HttpGet_mac.mm (NSURLSession).
std::string httpGet(const std::string& host, const std::string& path);

} // namespace refactoring::legacycode::detail
