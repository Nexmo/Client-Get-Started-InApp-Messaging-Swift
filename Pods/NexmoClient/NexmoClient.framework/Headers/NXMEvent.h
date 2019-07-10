//
//  NXMEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NXMEnums.h"

@interface NXMEvent : NSObject

@property (nonatomic, copy, nonnull) NSString *conversationId;
@property (nonatomic, copy, nonnull) NSString *fromMemberId; // TOOD: rename to initiator
@property (nonatomic, copy, nonnull) NSDate *creationDate;
@property (nonatomic, copy, nullable) NSDate *deletionDate;
@property NXMEventType type;
@property NSInteger sequenceId;

@end
