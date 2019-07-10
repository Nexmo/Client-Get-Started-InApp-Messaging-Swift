//
//  NXMMember.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NXMEnums.h"
#import "NXMUser.h"
#import "NXMMediaSettings.h"
#import "NXMChannel.h"

@interface NXMMember : NSObject

@property (nonatomic, copy, nonnull) NSString *conversationId;
@property (nonatomic, copy, nonnull) NSString *memberId;
@property (nonatomic, readonly, nonnull) NXMUser *user;
@property (nonatomic, copy, nonnull) NSString *joinDate;
@property (nonatomic, copy, nullable) NSString *inviteDate;
@property (nonatomic, copy, nullable) NSString *leftDate;
@property (nonatomic, readonly) NXMMemberState state;
@property (nonatomic, readonly, nullable) NXMMediaSettings *media;
@property (nonatomic, readonly, nullable) NXMChannel *channel;

@end
