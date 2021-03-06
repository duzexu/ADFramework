//
//  NSStringAdditions.h
//  ADFramework
//
//  Created by DuZexu on 12-11-30.
//  Copyright (c) 2012 DuZexu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Additions)

/**
 *Parses a URLString and a baseURL, return absolute URL.
 */
+ (NSString *)URLWithString:(NSString *)URLString relativeToURL:(NSString *)baseURL;

/**
 * Returns a URL Encoded String
 */
- (NSString*)urlEncoded;

/**
 *  去除字符串前后空格以及后面的换行
 */
- (NSString*)trim;

/**
 * Parses a URL query string into a dictionary where the values are arrays.
 */
- (NSDictionary*)queryContentsUsingEncoding:(NSStringEncoding)encoding;

/**
 * Parses a URL, adds query parameters to its query, and re-encodes it as a new URL.
 */
- (NSString*)stringByAddingQueryDictionary:(NSDictionary*)query;

/**
 * Parses a URL, adds urlEncoded query parameters to its query, and re-encodes it as a new URL.
 *
 * This method encodes keys and values of query using [NSString urlEncoded] and calls
 * stringByAddingQueryDictionary with the resulting dictionary.
 *
 * @throw NSInvalidArgumentException If any value or key does not respond to urlEncoded.
 */
- (NSString*)stringByAddingURLEncodedQueryDictionary:(NSDictionary*)query;

- (NSNumber*)stringToNSNumber;
- (BOOL)isEmpty;

#pragma mark - Contains
/**
 A shorthand method that uses NSPredicate to determine if an NSString contains another NSString. This uses a case-insensitive comparison.
 @param searchString    - NSString to check against self
 @returns BOOL
 */
- (BOOL)contains:(NSString *)searchString;

/**
 A shorthand method that uses NSPredicate to determine if an NSString contains any NSString objects inside of an array. This uses a case-insensitive comparison.
 @param searchArray    - NSArray of NSStrings
 @returns BOOL
 */
- (BOOL)containsAnyInArray:(NSArray *)searchArray;

#pragma mark - Email Validation
/**
 Uses regex to determine whether the string is a valid email address or not.
 @returns BOOL
 */
- (BOOL)isValidEmail;

#pragma mark - REGEX
/**
 Takes in a regular expression string to determine whether self evaluates with it or not.
 @param regexString - NSString of the regular expression
 @returns BOOL
 */
- (BOOL)matchesRegex:(NSString *)regexString;
@end
