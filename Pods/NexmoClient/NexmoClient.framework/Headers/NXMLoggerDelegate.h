//
//  NXMLoggerDelegate.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//


@protocol NXMLoggerDelegate

- (void)error:(nullable NSString *)message;
- (void)warning:(nullable NSString *)message;
- (void)info:(nullable NSString *)message;
- (void)debug:(nullable NSString *)message;

@end
