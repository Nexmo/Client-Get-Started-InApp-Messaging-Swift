//
//  NXMChannel.h
//  NexmoClient
//
//  Copyright © 2019 Vonage. All rights reserved.
//

#import "NXMEnums.h"

@interface NXMDirection : NSObject

@property (nonatomic, assign) NXMDirectionType type;
@property (nonatomic, copy, nullable) NSString *data;
@end

@interface NXMChannel : NSObject

@property (nonatomic, readonly, nonnull) NXMDirection *from;
@property (nonatomic, readonly, nullable) NXMDirection *to;

@end

