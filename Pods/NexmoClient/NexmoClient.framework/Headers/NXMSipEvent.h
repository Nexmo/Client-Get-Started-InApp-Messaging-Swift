//
//  NXMSipEvent.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMEvent.h"

@interface NXMSipEvent : NXMEvent
@property (nonatomic, strong, nonnull) NSString *phoneNumber;
@property (nonatomic, strong, nonnull) NSString *applicationId;
@property (nonatomic) NXMSipEventType sipType;
@end
