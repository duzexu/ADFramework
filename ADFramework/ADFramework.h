//
//  ADFramework.h
//  ADFramework
//
//  Created by DuZexu on 14-4-9.
//  Copyright (c) 2014年 Duzexu. All rights reserved.
//
/***************************************************************
 使用方法：
    1.添加libz动态链接库
    2.把bundle文件拖入工程，不选择copy
    3.加入Quarz Core
    
****************************************************************/
//#import <Foundation/Foundation.h>

/**
 *  常用define
 */
#import <ADFramework/ADDefine.h>
#import <ADFramework/ADCorePreprocessorMacros.h>
/**
 *  进度提示
 */
#import <ADFramework/SVProgressHUD.h>
/**
 *  加载gif图片
 *  YLImageView* imageView = [[YLImageView alloc] initWithFrame:CGRectMake(0, 160, 320, 240)];
 *  [self.view addSubview:imageView];
 *  imageView.image = [YLGIFImage imageNamed:@"joy.gif"];
 */
#import <ADFramework/YLImageView.h>
/**
 *  支持键盘出来后自动适应的ScrollowView
 */
#import <ADFramework/MSKeyboardScrollView.h>
/**
 *  XML解析
 *  NSError *err = nil;
 */
#import <ADFramework/XMLReader.h>
/**
 *  给所有类添加NSCodeing支持
 */
#import <ADFramework/AutoCoding.h>
/**
 *  自动移除观察者
 */
#import <ADFramework/SFObservers.h>
/**
 *  ASIHTTP库
 */
#import <ADFramework/ASIHTTPRequest.h>
#import <ADFramework/ASIFormDataRequest.h>
#import <ADFramework/ASINetworkQueue.h>
#import <ADFramework/ASIDownloadCache.h>
#import <ADFramework/Reachability.h>
/**
 *  日志框架
 *  在applicationDidFinishLaunching 加入
 *  [DDLog addLogger:[DDASLLogger sharedInstance]];日志输出到系统日志系统
 *  [DDLog addLogger:[DDTTYLogger sharedInstance]];日志输出到Xcode控制台
 *  [DDLog addLogger:[DDFileLogger sharedInstance]];日志输出到文件
 *  [DDLog addLogger:[DDLog sharedInstance]];日志全部输出
 *  fileLogger = [[DDFileLogger alloc] init];
    fileLogger.rollingFrequency = 60 * 60 * 24; // 24 hour rolling
    fileLogger.logFileManager.maximumNumberOfLogFiles = 7;
    [DDLog addLogger:fileLogger];
 *
 */
//#import <ADFramework/DDLog.h>
/**
 *  自定义通知
 */
#import <ADFramework/CRToast.h>
/**
 *  自动解析模型类别和Json输入结构
 */
#import <ADFramework/JSONModelLib.h>
/**
 *  文件管理
 */
#import <ADFramework/FCFileManager.h>
/********************* 常用Category ***********************/
/**
 *  UIView常用方法
 */
#import <ADFramework/UIView+Utils.h>
#import <ADFramework/UIView+Toast.h>
#import <ADFramework/UIView+EasingFunctions.h>//给View添加弹性效果
/**
 *  更详细的类描述
 */
#import <ADFramework/NSObject+AutoDescription.h>
/**
 *  给类添加属性
 *  Just simply add a property in a @interface and use @dynamic in an @implementation.
 */
#import <ADFramework/NSObject+DProperty.h>
/**
 *  计算Label的高度
 */
#import <ADFramework/UILabel+ContentSize.h>
/**
 *  NSDate的实用方法
 */
#import <ADFramework/NSDate+Exts.h>
/**
 *  UIActionView 和 UIAlertView 的实用方法
 */
#import <ADFramework/UIAlertView+MKBlockAdditions.h>
#import <ADFramework/UIActionSheet+MKBlockAdditions.h>
#import <ADFramework/NSObject+MKBlockAdditions.h>
/**
 *  UITextField 和 UITextView 的实用方法
 *  限制UITextField和UITextView的输入长度
 */
#import <ADFramework/LimitLength.h>
/**
 *  UIImage的实用方法
 */
#import <ADFramework/UIImage+Extensions.h>
/**
 *  NSArray的实用方法
 */
#import <ADFramework/NSArrayAdditions.h>
/**
 *  NSString的实用方法
 */
#import <ADFramework/NSStringAdditions.h>
/**
 *  NSData的实用方法
 *    [NSData getDataFromURL:[NSURL URLWithString:@"http://www.baidu.com"]
 *                   toBlock:^(NSData *data, BOOL *retry) {
 *        if (data == nil) {
 *        *retry = YES;
 *        return;
 *       }
 *       //Do something。。。
 *    }];
 */
#import <ADFramework/NSData+AsyncCacher.h>
/**
 *  自定义的present modal controller
 */
#import <ADFramework/UIViewController+MaryPopin.h>
/**
 *  NSTimer的实用方法
 */
#import <ADFramework/NSTimer+Extension.h>
/**
 *  给UIViewController添加子控制器
 */
#import <ADFramework/UIViewController+ChildViewController.h>
/**
 *  NSFileManager的实用方法
 */
#import <ADFramework/NSFileManager+Utils.h>


