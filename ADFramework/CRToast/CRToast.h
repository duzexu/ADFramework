//
//  CRToast
//  自定义状态栏通知效果
/*************************************************************************
    NSDictionary *options = @{kCRToastTextKey : @"Hello World!",
    kCRToastTextAlignmentKey : @(NSTextAlignmentCenter),
    kCRToastBackgroundColorKey : [UIColor redColor],
    kCRToastAnimationInTypeKey : @(CRToastAnimationTypeGravity),
    kCRToastAnimationOutTypeKey : @(CRToastAnimationTypeGravity),
    kCRToastAnimationInDirectionKey : @(CRToastAnimationDirectionLeft),
    kCRToastAnimationOutDirectionKey : @(CRToastAnimationDirectionRight),
    kCRToastAnimationInTimeIntervalKey : @(0.5),
    kCRToastAnimationOutTimeIntervalKey: @(0.5)};
    [CRToastManager showNotificationWithOptions:options
                                completionBlock:^{
                                    NSLog(@"Completed");
                                }];
*************************************************************************/

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, CRToastType){
    CRToastTypeStatusBar,
    CRToastTypeNavigationBar
};

typedef NS_ENUM(NSInteger, CRToastPresentationType){
    CRToastPresentationTypeCover,
    CRToastPresentationTypePush
};

typedef NS_ENUM(NSInteger, CRToastAnimationDirection) {
    CRToastAnimationDirectionTop,
    CRToastAnimationDirectionBottom,
    CRToastAnimationDirectionLeft,
    CRToastAnimationDirectionRight
};

typedef NS_ENUM(NSInteger, CRToastAnimationType) {
    CRToastAnimationTypeLinear,
    CRToastAnimationTypeSpring,
    CRToastAnimationTypeGravity
};

extern NSString *const kCRToastNotificationTypeKey;
extern NSString *const kCRToastNotificationPresentationTypeKey;

extern NSString *const kCRToastAnimationInTypeKey;
extern NSString *const kCRToastAnimationOutTypeKey;
extern NSString *const kCRToastAnimationInDirectionKey;
extern NSString *const kCRToastAnimationOutDirectionKey;

extern NSString *const kCRToastAnimationInTimeIntervalKey;
extern NSString *const kCRToastTimeIntervalKey;
extern NSString *const kCRToastAnimationOutTimeIntervalKey;

extern NSString *const kCRToastAnimationSpringDampingKey;
extern NSString *const kCRToastAnimationSpringInitialVelocityKey;

extern NSString *const kCRToastAnimationGravityMagnitudeKey;

extern NSString *const kCRToastTextKey;
extern NSString *const kCRToastFontKey;
extern NSString *const kCRToastTextColorKey;
extern NSString *const kCRToastTextAlignmentKey;
extern NSString *const kCRToastTextShadowColorKey;
extern NSString *const kCRToastTextShadowOffsetKey;
extern NSString *const kCRToastTextMaxNumberOfLinesKey;

extern NSString *const kCRToastBackgroundColorKey;
extern NSString *const kCRToastImageKey;

@interface CRToastManager : NSObject

+ (void)setDefaultOptions:(NSDictionary*)defaultOptions;
+ (void)showNotificationWithOptions:(NSDictionary*)options completionBlock:(void (^)(void))completion;
+ (void)showNotificationWithMessage:(NSString*)message completionBlock:(void (^)(void))completion;

@end