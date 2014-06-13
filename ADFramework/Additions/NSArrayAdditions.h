//
//  NSArrayAdditions.h
//  ADFramework
//
//  Created by DuZexu on 12-11-30.
//  Copyright (c) 2012 China DuZexu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSArray (Additions)

/**
 * @return nil or an object that matches value with isEqual:
 */
- (id)objectWithValue:(id)value forKey:(id)key;

/**
 * @return the first object with the given class.
 */
- (id)objectWithClass:(Class)cls;

/**
 * @param selector Required format: - (NSNumber*)method:(id)object;
 */
- (BOOL)containsObject:(id)object withSelector:(SEL)selector;


@end
