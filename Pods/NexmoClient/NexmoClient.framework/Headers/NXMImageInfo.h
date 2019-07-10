//
//  NXMImageInfo.h
//  NexmoClient
//
//  Copyright © 2018 Vonage. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, NXMImageType) {
    NXMImageTypeMedium,
    NXMImageTypeOriginal,
    NXMImageTypeThumbnail
};

@interface NXMImageInfo : NSObject
@property (nonatomic, strong, nonnull) NSString *imageId;
@property (nonatomic, strong, nonnull) NSURL *url;
@property NSInteger size;
@property NXMImageType type;

- (nullable instancetype)initWithId:(nonnull NSString *)imageId size:(NSInteger)size url:(nonnull NSURL *)url type:(NXMImageType)type;

@end
