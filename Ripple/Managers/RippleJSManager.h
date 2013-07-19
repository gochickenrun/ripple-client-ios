//
//  WebViewBridgeManager.h
//  Ripple
//
//  Created by Kevin Johnson on 7/17/13.
//  Copyright (c) 2013 OpenCoin Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface RippleJSManager : NSObject

+(RippleJSManager*)shared;

-(void)setLog:(UITextView*)textView;

-(void)accountInfo;
-(void)login:(NSString*)username andPassword:(NSString*)password withBlock:(void(^)(NSError* error))block;

@end