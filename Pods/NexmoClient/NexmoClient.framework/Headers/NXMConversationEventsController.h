//
//  NXMConversationEventsController.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NXMCoreEvents.h"

@class NXMConversationEventsController;

@protocol NXMConversationEventsControllerDelegate <NSObject>

typedef NS_ENUM(NSUInteger, NXMConversationEventsControllerChangeType) {
    NXMConversationEventsControllerChangeInsert = 1,
    NXMConversationEventsControllerChangeDelete = 2,
    NXMConversationEventsControllerChangeMove = 3,
    NXMConversationEventsControllerChangeUpdate = 4
};

@optional
- (void)nxmConversationEventsController:(nonnull NXMConversationEventsController *)controller
                         didChangeEvent:(nonnull NXMEvent *)anEvent
                                atIndex:(NSUInteger)index
                          forChangeType:(NXMConversationEventsControllerChangeType)type
                               newIndex:(NSUInteger)newIndex;

@optional
- (void)nxmConversationEventsControllerWillChangeContent:(nonnull NXMConversationEventsController *)controller;

@optional
- (void)nxmConversationEventsControllerDidChangeContent:(nonnull NXMConversationEventsController *)controller;

@end

@interface NXMConversationEventsController : NSObject

@property (nonatomic,weak, nullable) id <NXMConversationEventsControllerDelegate> delegate;
@property (nonatomic,strong,readonly, nonnull) NSArray<NXMEvent*>*  events;

-(void)loadEarlierEventsWithMaxAmount:(NSUInteger)maxAmount completion:(void (^_Nullable)(NSError * _Nullable error))completion;
@end
