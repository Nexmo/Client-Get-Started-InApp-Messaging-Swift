//
//  NXMConversation.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import "NXMMember.h"

@interface NXMConversationDetails : NSObject

@property NSString *conversationId;
@property NSInteger sequence_number;
@property NSString *name;
@property NSString *displayName;
@property NSArray<NXMMember *> *members;
@property NSDate *created;
@property NSData *properties;

- (instancetype)initWithConversationId:(NSString *)conversationId;

@end
