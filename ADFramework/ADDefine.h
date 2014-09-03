//
//  ADDefine.h
//  ADFramework
//
//  Created by DuZexu on 14-4-10.
//  Copyright (c) 2014年 Duzexu. All rights reserved.
//

#import "ADFramework.h"

//--------------------------------------------------------------------------------------------------
#define __AD_DEBUG__ (1) //是否为debug模式
#define __AD_LOG__ (1) //是否打开log
#define __AD_SAVE_LOG__ (0) //是否将log保存到文件/Documents/log/
#define __AD_PRODUCT__ (0) //是否是生产环境，为1时需要将 __AD_DEBUG__ 置为0
//--------------------------------------------------------------------------------------------------
//Global frames
#define kScreenWidth [[UIScreen mainScreen] bounds].size.width
#define kScreenHeight [[UIScreen mainScreen] bounds].size.height
#define kAppWidth [[UIScreen mainScreen] applicationFrame].size.width
#define kAppHeight [[UIScreen mainScreen] applicationFrame].size.height
#define kStatusBarHeight 20.0f
#define kNavigationBarHeight 44.0f
#define kNavigationBarLandscapeHeight 33.0f
//--------------------------------------------------------------------------------------------------
//iPhone5
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
// 程序主目录
#define kHomePath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]
//#define kHomePath [NSHomeDirectory() stringByAppendingPathComponent:@"Library/Caches"]
// 缓存目录
#define kTempPath [NSHomeDirectory() stringByAppendingPathComponent:@"/tmp"]
//--------------------------------------------------------------------------------------------------
/**
 *  @brief  点击UIViewController的任何地方使键盘消失
 *
 *  或者在VC中重写touchbegin方法[self.vew endEditing:YES];
 */
#define DisMissKeybord [[[UIApplication sharedApplication] keyWindow] endEditing:YES]

/**
 *  @brief  移除view上的所有subviews
 */
#define RemoveAllSubviews(view) [[view subviews] makeObjectsPerformSelector:@selector(removeFromSuperview)]

/**
 *  @brief  得到UUID
 */
#define GetUUID [[[UIDevice currentDevice] identifierForVendor] UUIDString]

/**
 *  @brief  得到系统版本
 */
#define GetSystemVersion [[[UIDevice currentDevice] systemVersion] floatValue]

/**
 *  @brief  得到文件路径
 */
#define GetFullPath(fileName) [kHomePath stringByAppendingPathComponent:fileName]

//打电话
#define _MakeCall(number) [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"tel://%@", number]]]
//发短信
#define _MakeMessage(number) [[UIApplication sharedApplication] openURL:[NSURL URLWithString:[NSString stringWithFormat:@"sms://%@", number]]]

/**
 *  @brief  输出
 */
#ifdef DEBUG
#if __AD_LOG__
#define NSLogError(format, ...) NSLog(@"\033[" @"fg255,250,250;" @"\033[" @"bg0,0,0;" format @";")
#define NSLogBlue(format, ...) NSLog(@"\033[" @"fg0,0,255;" @"\033[" @"bg255,255,255;" format @";")
#define NSLogRed(format, ...) NSLog(@"\033[" @"fg255,0,0;" @"\033[" @"bg255,255,255;" format @";")
#define NSLogGreen(format, ...) NSLog(@"\033[" @"fg124,252,0;" @"\033[" @"bg255,255,255;" format @";")
#define NSLogBrown(format, ...) NSLog(@"\033[" @"fg160,82,45;" @"\033[" @"bg255,255,255;" format @";")
#undef NSLog
#define NSLog(format, ...)                                                                                                       \
fprintf(stderr, "<%s : %d> %s", [[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, __func__); \
(NSLog)((@"\033[" @"fg0,0,0;" @"\033[" @"bg255,255,255;" format), ##__VA_ARGS__);                                                                                               \
fprintf(stderr, "--------------------------------------\n");
#else
#undef NSLog
#define NSLog(format, ...) do {} while (0)
#define NSLogError(format, ...) do {} while (0)
#define NSLogBlue(format, ...) do {} while (0)
#define NSLogRed(format, ...) do {} while (0)
#define NSLogGreen(format, ...) do {} while (0)
#define NSLogBrown(format, ...) do {} while (0)
#endif
#else
#undef NSLog
#define NSLog(...) \
    do {           \
    } while (0)
#endif

#define NSLogRect(rect) NSLog(@"%s x:%.4f, y:%.4f, w:%.4f, h:%.4f", #rect, rect.origin.x, rect.origin.y, rect.size.width, rect.size.height)
#define NSLogSize(size) NSLog(@"%s w:%.4f, h:%.4f", #size, size.width, size.height)
#define NSLogPoint(point) NSLog(@"%s x:%.4f, y:%.4f", #point, point.x, point.y)

/**
 *  NSString实用方法
 */
#define NSStringFromInt(intValue) [NSString stringWithFormat:@"%d", intValue]
#define NSStringFromFloat(floatValue) [NSString stringWithFormat:@"%f", floatValue]

/**
 *  @brief  加载图片
 */
#define LOADJPGIMAGE(file, ext) [UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:file ofType:ext]]
#define LOADIMAGE(file) [UIImage imageNamed:file]

/**
 *  @brief  release方法
 *
 *  @param  obj id类型  要release的对象
 *
 *  @return  id类型
 */
static inline id _release(id obj)
{
#if !(__has_feature(objc_arc))
    if (obj)
        [obj release], obj = nil;
#endif
    return obj;
}

// 使用unix c函数来实现获取文件大小，速度超快
float getFileSizeAtPath(NSString *filePath) {
    if (filePath == nil || [filePath length] == 0) {
        return 0;
    }
    struct stat st;
    if (lstat([filePath cStringUsingEncoding:NSUTF8StringEncoding], &st) == 0) {
        return st.st_size;
    }
    return 0;
}

//获取文件夹的大小
float getFolderSizeAtPath(const char *folderPath) {
      float folderSize = 0;
      DIR *dir = opendir(folderPath);
      if (dir == NULL)
        return 0;
      struct dirent *child;
      while ((child = readdir(dir)) != NULL) {
        if (child->d_type == DT_DIR &&
            ((child->d_name[0] == '.' && child->d_name[1] == 0) || // 忽略目录 .
             (child->d_name[0] == '.' && child->d_name[1] == '.' &&
              child->d_name[2] == 0) // 忽略目录 ..
             ))
          continue;

        int folderPathLength = strlen(folderPath);
        char childPath[1024]; // 子文件的路径地址
        stpcpy(childPath, folderPath);
        if (folderPath[folderPathLength - 1] != '/') {
          childPath[folderPathLength] = '/';
          folderPathLength++;
        }
        stpcpy(childPath + folderPathLength, child->d_name);
        childPath[folderPathLength + child->d_namlen] = 0;
        if (child->d_type == DT_DIR) {                  // directory
          folderSize += getFolderSizeAtPath(childPath); // 递归调用子目录
          // 把目录本身所占的空间也加上
          struct stat st;
          if (lstat(childPath, &st) == 0)
            folderSize += st.st_size;
        } else if (child->d_type == DT_REG ||
                   child->d_type == DT_LNK) { // file or link
          struct stat st;
          if (lstat(childPath, &st) == 0)
            folderSize += st.st_size;
        }
      }
      return folderSize;
}
