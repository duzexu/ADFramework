//
//  LimitLength.m
//  ADFramework
//
//  Created by DuZexu on 13-4-8.
//  Copyright (c) 2013年 DuZexu. All rights reserved.
//

#import "LimitLength.h"
#import <objc/objc.h>
#import <objc/runtime.h>

static NSString *kLimitTextLengthKey = @"kLimitTextLengthKey";

@implementation UITextField (LimitLength)

- (void) shouldChangeTextWithMaxLength:(NSInteger)length;
{
    NSString *toBeString = self.text;
    NSString *lang = [[UITextInputMode currentInputMode] primaryLanguage]; // 键盘输入模式
    if ([lang isEqualToString:@"zh-Hans"]) { // 简体中文输入，包括简体拼音，健体五笔，简体手写
        UITextRange *selectedRange = [self markedTextRange];
        //获取高亮部分
        UITextPosition *position = [self positionFromPosition:selectedRange.start offset:0];
        // 没有高亮选择的字，则对已输入的文字进行字数统计和限制
        if (!position) {
            if (toBeString.length > length) {
                self.text = [toBeString substringToIndex:length];
            }
        }
        // 有高亮选择的字符串，则暂不对文字进行统计和限制
        else{
            
        }
    }
    // 中文输入法以外的直接对其统计限制即可，不考虑其他语种情况
    else{
        if (toBeString.length > length) {
            self.text = [toBeString substringToIndex:length];
        }
    }
}

- (void)limitTextLength:(int)length
{
    objc_setAssociatedObject(self, (const void *)(kLimitTextLengthKey), [NSNumber numberWithInt:length], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    [self addTarget:self action:@selector(textFieldTextLengthLimit:) forControlEvents:UIControlEventEditingChanged];
}

- (void)textFieldTextLengthLimit:(id)sender
{
    NSNumber *lengthNumber = objc_getAssociatedObject(self, (const void *)(kLimitTextLengthKey));
    [self shouldChangeTextWithMaxLength:[lengthNumber intValue]];
}

@end

@implementation UITextView (LimitLength)

- (void) shouldChangeTextWithMaxLength:(NSInteger)length;
{
    NSString *toBeString = self.text;
    NSString *lang = [[UITextInputMode currentInputMode] primaryLanguage]; // 键盘输入模式
    if ([lang isEqualToString:@"zh-Hans"]) { // 简体中文输入，包括简体拼音，健体五笔，简体手写
        UITextRange *selectedRange = [self markedTextRange];
        //获取高亮部分
        UITextPosition *position = [self positionFromPosition:selectedRange.start offset:0];
        // 没有高亮选择的字，则对已输入的文字进行字数统计和限制
        if (!position) {
            if (toBeString.length > length) {
                self.text = [toBeString substringToIndex:length];
            }
        }
        // 有高亮选择的字符串，则暂不对文字进行统计和限制
        else{
            
        }
    }
    // 中文输入法以外的直接对其统计限制即可，不考虑其他语种情况
    else{
        if (toBeString.length > length) {
            self.text = [toBeString substringToIndex:length];
        }
    }
}

- (void)limitTextLength:(int)length;
{
    objc_setAssociatedObject(self, (const void *)(kLimitTextLengthKey), [NSNumber numberWithInt:length], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(textFieldTextLengthLimit:) name:UITextViewTextDidChangeNotification object:nil];
}

- (void)textFieldTextLengthLimit:(id)sender
{
    NSNumber *lengthNumber = objc_getAssociatedObject(self, (const void *)(kLimitTextLengthKey));
    [self shouldChangeTextWithMaxLength:[lengthNumber intValue]];
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UITextViewTextDidChangeNotification object:nil];
    [super dealloc];
}

@end

