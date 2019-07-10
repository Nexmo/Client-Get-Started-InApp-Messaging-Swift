//
//  NXMCall.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NXMCallMember.h"
#import "NXMConversation.h"
#import "NXMBlocks.h"

@protocol NXMCallDelegate <NSObject>
- (void)statusChanged:(nonnull NXMCallMember *)callMember;
@optional
- (void)DTMFReceived:(nonnull NSString *)dtmf callMember:(nonnull NXMCallMember *)callMember;
@end

typedef NS_ENUM(NSInteger, NXMCallHandler) {
    NXMCallHandlerInApp,
    NXMCallHandlerServer
};

@interface NXMCall : NSObject

@property (nonatomic, readonly, nonnull) NSMutableArray<NXMCallMember *> *otherCallMembers;
@property (nonatomic, readonly, nonnull) NXMCallMember *myCallMember;

- (void)setDelegate:(nonnull id<NXMCallDelegate>)delegate;

- (void)answer:(nonnull id<NXMCallDelegate>)delegate completionHandler:(NXMErrorCallback _Nullable)completionHandler;
- (void)reject:(NXMErrorCallback _Nullable)completionHandler;

- (void)addCallMemberWithUserId:(NSString *)userId completionHandler:(NXMErrorCallback _Nullable)completionHandler;
- (void)addCallMemberWithNumber:(NSString *)number completionHandler:(NXMErrorCallback _Nullable)completionHandler;

- (void)sendDTMF:(NSString *)dtmf;

- (void)hangup;

@end

