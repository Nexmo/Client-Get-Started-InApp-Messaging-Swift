//
//  NXMMediaSettings.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NXMMediaSettings : NSObject
@property bool isEnabled;
@property bool isSuspended;

- (instancetype)initWithEnabled:(BOOL)enabled suspend:(BOOL)suspend;
@end
