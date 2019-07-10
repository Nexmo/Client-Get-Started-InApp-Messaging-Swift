//
//  NXMClientDelegate.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NXMUser.h"
#import "NXMEnums.h"

@class NXMCall;
@class NXMConversation;

@protocol NXMClientDelegate <NSObject>

- (void)connectionStatusChanged:(NXMConnectionStatus)status reason:(NXMConnectionStatusReason)reason;

@optional
- (void)incomingCall:(nonnull NXMCall *)call;
- (void)addedToConversation:(nonnull NXMConversation *)conversation;

@end
