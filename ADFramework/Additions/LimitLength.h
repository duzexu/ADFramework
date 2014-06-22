//
//  LimitLength.h
//  ADFramework
//
//  Created by DuZexu on 13-4-8.
//  Copyright (c) 2013年 DuZexu. All rights reserved.
//
//  限制UITextField和UITextView的输入长度

#import <UIKit/UIKit.h>

@interface UITextField (LimitLength)

- (void)shouldChangeTextWithMaxLength:(int)length;

- (void)limitTextLength:(int)length;

@end

@interface UITextView (LimitLength)

- (void)shouldChangeTextWithMaxLength:(int)length;

- (void)limitTextLength:(int)length;

@end