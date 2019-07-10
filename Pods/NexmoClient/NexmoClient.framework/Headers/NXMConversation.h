//
//  NXMConversation.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NXMConversationDelegate.h"
#import "NXMConversationEventsController.h"
#import "NXMMember.h"

typedef NS_ENUM(NSInteger, NXMAttachmentType) {
    NXMAttachmentTypeImage
};

@interface NXMConversation : NSObject

@property (readonly, nonatomic, nonnull) NSString *conversationId;
@property (readonly, nonatomic, nonnull) NSString *name;
@property (readonly, nonatomic, nullable) NSString *displayName;
@property (readonly, nonatomic) NSInteger lastEventId;
@property (readonly, nonatomic, nonnull) NSDate *creationDate;
@property (readonly, nonatomic, nullable) NXMMember *myMember;
@property (readonly, nonatomic, nullable) NSArray<NXMMember *> *otherMembers;
@property (nonatomic, weak, nullable) id <NXMConversationDelegate> delegate;
/**
 Join the current logged user as a member of the conversation

 @param completion
 A completion block with the new member of the conversation or an error object if an error occured
 */
- (void)joinWithCompletion:(void (^_Nullable)(NSError * _Nullable error, NXMMember * _Nullable member))completion;

/**
 Joins a user as a member of the conversation

 @param userId
 The id of the user to join
 
 @param completion
 A completion block with an error object if one occured, or the new member object if user joined
 */
- (void)joinMemberWithUserId:(nonnull NSString *)userId
                completion:(void (^_Nullable)(NSError * _Nullable error, NXMMember * _Nullable member))completion;


/**
 Current user's member leaves the conversation
 
 @param completion
 A completion block with an error object if one occured
 */
- (void)leaveWithCompletion:(void (^_Nullable)(NSError * _Nullable error))completion;


/**
 Kicks a member from participating in the conversation
 
 @param memberId
 The id of the member to kick
 
 @param completion
 A completion block with an error object if one occured
 */
- (void)kickMemberWithMemberId:(nonnull NSString *)memberId
                     completion:(void (^_Nullable)(NSError * _Nullable error))completion;


/**
 Sends a text message to the members of the conversation
 
 @param text
 The text to send
 
 @param completion
 A completion block with an error object if one occured
 */
- (void)sendText:(nonnull NSString *)text
     completion:(void (^_Nullable)(NSError * _Nullable error))completion;


/**
 Sends an attachment message to the members of the conversation
 
 @param attachmentType
 The type of the attachment following NXMAttachmentType enum
 
 @param name
 A name identifier of the attachment
 
 @param data
 The data of the attachment in a NSData representation
 
 @param completion
 A completion block with an error object if one occured
 */
- (void)sendAttachmentOfType:(NXMAttachmentType)attachmentType
                   WithName:(nonnull NSString *)name
                        data:(nonnull NSData *)data
                  completion:(void (^_Nullable)(NSError * _Nullable error))completion;

/**
 Sends an indication that the current user's member started typing
 
 @param completion
 A completion block with an error object if one occured
 */
- (void)sendStartTypingWithCompletion:(void (^_Nullable)(NSError * _Nullable error))completion;

/**
 Sends an indication that the current user's member stopped typing
 
 @param completion
 A completion block with an error object if one occured
 */
- (void)sendStopTypingWithCompletion:(void (^_Nullable)(NSError * _Nullable error))completion;


/**
 Get an instance of NXMConversationEventsController.
 
 
 @param eventTypes
 A NSSet of the types of events the controller should handle

 @param delegate
 An instance conforming to the NXMConversationEventsControllerDelegate protocol, used to get notifications about changes in the controller.
 
 @return a new instance of NXMConversationEventsController
 */
- (nonnull NXMConversationEventsController *)eventsControllerWithTypes:(nonnull NSSet<NSNumber *> *)eventTypes
                                                          andDelegate:(id <NXMConversationEventsControllerDelegate>_Nullable)delegate;
@end
