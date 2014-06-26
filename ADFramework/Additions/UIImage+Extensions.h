//
//  UIImage+Extensions.h
//  TestLogoAnimation
//
//  Created by DuZexu on 11-12-22.
//  Copyright (c) 2011年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Extensions)
/**
 *  角度变弧度
 */
CGFloat DegreesToRadians(CGFloat degrees);
/**
 *  弧度变角度
 */
CGFloat RadiansToDegrees(CGFloat radians);

/**
 *  截取部分图片
 *
 *  @param rect 位置
 *
 *  @return 截取的图片
 */
- (UIImage *)imageAtRect:(CGRect)rect;

/**
 *  创建缩略图
 *
 *  @param targetSize 大小
 *
 *  @return 缩略图
 */
- (UIImage *)imageByScalingProportionallyToMinimumSize:(CGSize)targetSize;

/**
 *  缩小图片
 *
 *  @param targetSize 目标大小
 *
 *  @return 缩小的图片
 */
- (UIImage *)imageByScalingToSize:(CGSize)targetSize;

/**
 *  旋转图片
 */
- (UIImage *)imageRotatedByRadians:(CGFloat)radians;
- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees;

/**
 *  改变图片颜色
 */
- (UIImage *)imageTintedWithColor:(UIColor *)color;
- (UIImage *)imageTintedWithColor:(UIColor *)color fraction:(CGFloat)fraction;

/**
 *  保存到相册
 */
-(BOOL)saveToPhotosAlbum;
@end
