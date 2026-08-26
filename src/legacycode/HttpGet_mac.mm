#include "legacycode/HttpGet.h"

#include <stdexcept>

#import <Foundation/Foundation.h>

namespace refactoring::legacycode::detail {

std::string httpGet(const std::string& host, const std::string& path) {
    NSString* urlString = [NSString stringWithFormat:@"https://%s%s", host.c_str(), path.c_str()];
    NSURL* url = [NSURL URLWithString:urlString];
    if (!url) {
        throw std::runtime_error("Invalid URL");
    }

    NSMutableURLRequest* request = [NSMutableURLRequest requestWithURL:url];
    [request setHTTPMethod:@"GET"];
    [request setValue:@"ShippingCalculator/1.0" forHTTPHeaderField:@"User-Agent"];

    __block NSData* responseData = nil;
    __block NSError* requestError = nil;
    __block NSInteger statusCode = 0;
    dispatch_semaphore_t semaphore = dispatch_semaphore_create(0);

    NSURLSessionDataTask* task = [[NSURLSession sharedSession]
            dataTaskWithRequest:request
            completionHandler:^(NSData* data, NSURLResponse* response, NSError* error) {
                responseData = data;
                requestError = error;
                if ([response isKindOfClass:[NSHTTPURLResponse class]]) {
                    statusCode = [(NSHTTPURLResponse*)response statusCode];
                }
                dispatch_semaphore_signal(semaphore);
            }];
    [task resume];

    dispatch_semaphore_wait(semaphore, DISPATCH_TIME_FOREVER);

    if (requestError) {
        throw std::runtime_error(std::string("HTTP request failed: ")
                + [[requestError localizedDescription] UTF8String]);
    }
    if (statusCode != 0 && (statusCode < 200 || statusCode >= 300)) {
        throw std::runtime_error("HTTP request failed with status " + std::to_string(statusCode));
    }
    if (!responseData) {
        return std::string();
    }

    return std::string(static_cast<const char*>([responseData bytes]), [responseData length]);
}

} // namespace refactoring::legacycode::detail
