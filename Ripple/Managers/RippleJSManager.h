//
//  WebViewBridgeManager.h
//  Ripple
//
//  Created by Kevin Johnson on 7/17/13.
//  Copyright (c) 2013 OpenCoin Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol RippleJSManagerNetworkStatus <NSObject>

@required
-(void)RippleJSManagerConnected;
-(void)RippleJSManagerDisconnected;

@end


@protocol RippleJSManagerBalanceDelegate <NSObject>

@required
-(void)RippleJSManagerBalances:(NSDictionary*)balances;

@end

@interface RippleJSManager : NSObject

@property (weak ,nonatomic) id<RippleJSManagerBalanceDelegate> delegate_balances;
@property (weak ,nonatomic) id<RippleJSManagerNetworkStatus> delegate_network_status;

+(RippleJSManager*)shared;

-(void)setLog:(UITextView*)textView;


-(void)login:(NSString*)username andPassword:(NSString*)password withBlock:(void(^)(NSError* error))block;
-(void)logout;

-(void)rippleFindPath:(NSDictionary*)params;
-(void)rippleSendTransactionAmount:(NSNumber*)amount toRecipient:(NSString*)recipient withBlock:(void(^)(NSError* error))block;

-(BOOL)isLoggedIn;

-(NSString*)rippleWalletAddress;

@end
