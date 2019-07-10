//
//  NXMRtcAnswerEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NXMRtcAnswerEvent : NSObject

@property (nonatomic, strong, nonnull) NSString *conversationId;
@property (nonatomic, strong, nonnull) NSString *rtcId;
@property (nonatomic, strong, nonnull) NSString *sdp;
@property (nonatomic, strong, nonnull) NSString *sessionId;
@property (nonatomic, strong, nonnull) NSDate *timestamp;

@end
