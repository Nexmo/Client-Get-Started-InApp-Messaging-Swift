//
//  NXMConversationDelegate.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NXMCoreEvents.h"

@protocol NXMConversationDelegate <NSObject>
@optional
- (void)textEvent:(nonnull NXMMessageEvent *)textEvent;
- (void)attachmentEvent:(nonnull NXMMessageEvent *)attachmentEvent;
- (void)messageStatusEvent:(nonnull NXMMessageStatusEvent *)messageStatusEvent;
- (void)mediaEvent:(nonnull NXMEvent *)mediaEvent;
- (void)typingEvent:(nonnull NXMTextTypingEvent *)typingEvent;
- (void)memberEvent:(nonnull NXMMemberEvent *)memberEvent;
- (void)conversationExpired;
@end
