//
//  NXMMemberEvent.h
//  NexmoNClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMEvent.h"
#import "NXMUser.h"
#import "NXMMediaSettings.h"
#import "NXMChannel.h"

@interface NXMMemberEvent : NXMEvent

@property (nonatomic, copy, nonnull) NSString *memberId;
@property (nonatomic) NXMMemberState state;
@property (nonatomic, readonly, nonnull) NXMUser *user;
@property (nonatomic, readonly, nullable) NXMMediaSettings *media;
@property (nonatomic, readonly, nullable) NXMChannel *channel;
@property (nonatomic, copy, nullable) NSString *knockingId;

@end
