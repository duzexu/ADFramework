//
//  ADCorePreprocessorMacros.h
//  ADFramework
//
//  Created by DuZexu on 14-4-9.
//  Copyright (c) 2014年 Duzexu. All rights reserved.
//


//--------------------------------------------------------------------------------------------------

#define AD_RELEASE_SAFELY(__POINTER) {  __POINTER = nil; }
#define AD_INVALIDATE_TIMER(__TIMER) { [__TIMER invalidate]; __TIMER = nil; }

#define ADAppBundleVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"]

//--------------------------------------------------------------------------------------------------
//rgb颜色
#define AD_RGB(__r, __g, __b) [UIColor colorWithRed:(__r / 255.0) green:(__g / 255.0) blue:(__b / 255.0) alpha:1]
#define AD_RGBA(__r, __g, __b, __a) [UIColor colorWithRed:(__r / 255.0) green:(__g / 255.0) blue:(__b / 255.0) alpha:__a]

#define AD_HEXCOLOR(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

//--------------------------------------------------------------------------------------------------
//生成静态属性
#define AD_GET_PROPERTY( __name) \
    @property (nonatomic, strong, readonly) NSString* __name; \
    + (NSString *)__name;

#define AD_SET_PROPERTY( __name, __value) \
    @dynamic __name; \
    + (NSString *)__name \
    { \
        return __value; \
    }


//--------------------------------------------------------------------------------------------------
//申明为单例
#undef	AD_AS_SINGLETON
#define AD_AS_SINGLETON( __class ) \
    + (__class *)sharedInstance;

#undef	AD_DEF_SINGLETON
#define AD_DEF_SINGLETON( __class ) \
    + (__class *)sharedInstance \
    { \
        static dispatch_once_t once; \
        static __class * __singleton__; \
        dispatch_once( &once, ^{ __singleton__ = [[__class alloc] init]; } ); \
        return __singleton__; \
}

//--------------------------------------------------------------------------------------------------
//6.0一下兼容6.0枚举类型，避免版本导致的警告
#define UILineBreakMode                 NSLineBreakMode
#define UILineBreakModeWordWrap			NSLineBreakByWordWrapping
#define UILineBreakModeCharacterWrap	NSLineBreakByCharWrapping
#define UILineBreakModeClip				NSLineBreakByClipping
#define UILineBreakModeHeadTruncation	NSLineBreakByTruncatingHead
#define UILineBreakModeTailTruncation	NSLineBreakByTruncatingTail
#define UILineBreakModeMiddleTruncation	NSLineBreakByTruncatingMiddle

#define UITextAlignment                 NSTextAlignment
#define UITextAlignmentLeft				NSTextAlignmentLeft
#define UITextAlignmentCenter			NSTextAlignmentCenter
#define UITextAlignmentRight			NSTextAlignmentRight

//--------------------------------------------------------------------------------------------------
//4.3的情况下兼容5.0的ARC关键字
#if (!__has_feature(objc_arc)) || \
(defined __IPHONE_OS_VERSION_MIN_REQUIRED && \
__IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_5_0) || \
(defined __MAC_OS_X_VERSION_MIN_REQUIRED && \
__MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_7)
#undef weak
#define weak unsafe_unretained
#undef __weak
#define __weak __unsafe_unretained
#endif

//--------------------------------------------------------------------------------------------------
//performSelector方法在ARC模式下会有警告
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Warc-performSelector-leaks"

#pragma clang diagnostic pop
