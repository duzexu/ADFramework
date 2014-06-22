//
//  NSData+AsyncCacher.h
//  ADFramework
//
//  Created by DuZexu on 28.06.13.
//  Copyright (c) 2013 DuZexu. All rights reserved.
//
// 带缓存的NSData请求，可多次请求

#import <Foundation/Foundation.h>

@interface NSData (AsyncCacher)

+ (void)getDataFromURL:(NSURL *)url
               toBlock:(void(^)(NSData * data, BOOL * retry))block;

+ (void)getDataFromURL:(NSURL *)url
               toBlock:(void(^)(NSData * data, BOOL * retry))block
             needCache:(BOOL)needCache;

@end
