//
//  NXMClient.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NXMClientDelegate.h"
#import "NXMConversation.h"
#import "NXMCall.h"
#import "NXMLoggerDelegate.h"

@interface NXMClient : NSObject

/*!
Return the connection status.
*/
@property (nonatomic, assign, readonly, getter=getConnectionStatus) NXMConnectionStatus connectionStatus;

/*!
 Return the current user
 */
@property (nonatomic, readonly, nullable, getter=getUser) NXMUser *user;

/*!
 Return the current authentication token
 */
@property (nonatomic, readonly, nullable, getter=getToken) NSString *token;

/**
 init nxmClient with authentication token
 @param authToken user authentication token
 */
- (instancetype)initWithToken:(nonnull NSString *)authToken;

/*!
 Set nexmo client logger delegate
 *  @param delegate a `NXMLoggerDelegate` object.
 *
 */
- (void)setLoggerDelegate:(nullable id <NXMLoggerDelegate>)delegate;

/*!
 Set nexmo client delegate
 *  @param delegate a `NXMClientDelegate` object.
 *
 */
- (void)setDelegate:(nonnull id <NXMClientDelegate>)delegate;

/**
 login and connect to nexmo sdk.
 */
- (void)login;

/**
 Update authentication token when logged in
 @param authToken user authentication token
 */
- (void)refreshAuthToken:(nonnull NSString *)authToken;

/**
Logout
 */
- (void)logout;

#pragma mark - Conversation

/**
 Get a conversation object by id
 @param converesationId     conversation id
 @param completion          completion block
 */
- (void)getConversationWithId:(nonnull NSString *)converesationId
                   completion:(void(^_Nullable)(NSError * _Nullable error, NXMConversation * _Nullable conversation))completion;


/**
 Creatw a new conversation with name

 @param name                conversation name
 @param completion          completion block
 */
- (void)createConversationWithName:(nonnull NSString *)name completion:(void(^_Nullable)(NSError * _Nullable error, NXMConversation * _Nullable conversation))completion;

#pragma mark - Call

///**
// Create a new call to users
//
// @param callees         user ids/name or pstn number to call
// @param callHandler        type of the call (InApp/SERVER)
// @param delegate        call delegate
// @param completion      completion block
// */
- (void)call:(nonnull NSArray<NSString *>*)callees
    callHandler:(NXMCallHandler)callHandler
    delegate:(nullable id<NXMCallDelegate>)delegate
  completion:(void(^_Nullable)(NSError * _Nullable error, NXMCall * _Nullable call))completion;

- (void)onMemberEvent:(NSNotification* )notification;

#pragma mark - Push Notifications

/**
 Enable push notification for specific device

 @param deviceToken     the device token
 @param isPushKit       is the app using PushKit
 @param isSandbox       is apple sandbox enviroment
 @param completion      completion block
 */
- (void)enablePushNotificationsWithDeviceToken:(nonnull NSData *)deviceToken
                                     isPushKit:(BOOL)isPushKit
                                     isSandbox:(BOOL)isSandbox
                                    completion:(void(^_Nullable)(NSError * _Nullable error))completion;

/**
 Disable push notification for the current device
 
 @param completion      completion block
 */
- (void)disablePushNotificationsWithCompletion:(void(^_Nullable)(NSError * _Nullable error))completion;

/**
 Call this method on incoming push

 @param userInfo    pushInfo
 @return true if nexmo push
 */
- (BOOL)isNexmoPushWithUserInfo:(nonnull NSDictionary *)userInfo;

/**
 Handle nexmo push
 Call this method when isNexmoPushWithUserInfo:userInfo return true
 
 @param userInfo    pushInfo
 @param completion  completion block
 */
- (void)processNexmoPushWithUserInfo:(nonnull NSDictionary *)userInfo
                           completion:(void(^_Nullable)(NSError * _Nullable error))completion;

@end
