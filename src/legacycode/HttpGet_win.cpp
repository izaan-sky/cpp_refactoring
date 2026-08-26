#include "legacycode/HttpGet.h"

#include <stdexcept>

#include <windows.h>
#include <winhttp.h>

namespace refactoring::legacycode::detail {

std::string httpGet(const std::string& host, const std::string& path) {
    std::string result;

    std::wstring whost(host.begin(), host.end());
    std::wstring wpath(path.begin(), path.end());

    HINTERNET hSession = WinHttpOpen(L"ShippingCalculator/1.0",
            WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
            WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (!hSession) {
        throw std::runtime_error("Failed to open WinHTTP session");
    }

    HINTERNET hConnect = WinHttpConnect(hSession, whost.c_str(), INTERNET_DEFAULT_HTTPS_PORT, 0);
    if (!hConnect) {
        WinHttpCloseHandle(hSession);
        throw std::runtime_error("Failed to connect to host");
    }

    HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", wpath.c_str(),
            nullptr, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES,
            WINHTTP_FLAG_SECURE);
    if (!hRequest) {
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);
        throw std::runtime_error("Failed to open request");
    }

    bool ok = WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0,
                       WINHTTP_NO_REQUEST_DATA, 0, 0, 0) != FALSE
            && WinHttpReceiveResponse(hRequest, nullptr) != FALSE;

    if (ok) {
        for (;;) {
            DWORD available = 0;
            if (!WinHttpQueryDataAvailable(hRequest, &available) || available == 0) {
                break;
            }
            std::string buffer(available, '\0');
            DWORD read = 0;
            if (!WinHttpReadData(hRequest, buffer.data(), available, &read)) {
                break;
            }
            result.append(buffer, 0, read);
        }
    }

    WinHttpCloseHandle(hRequest);
    WinHttpCloseHandle(hConnect);
    WinHttpCloseHandle(hSession);

    if (!ok) {
        throw std::runtime_error("HTTP request failed");
    }

    return result;
}

} // namespace refactoring::legacycode::detail
