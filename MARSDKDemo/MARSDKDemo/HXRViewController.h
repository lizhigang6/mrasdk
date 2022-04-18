//
//  HXRViewController.h
//  MARSDKDemo
//
//  Created by 火星人 on 2021/12/2.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface HXRViewController : UIViewController

// 单例方法
+(instancetype)shareInstance;

//登录
- (void)onLoginClick;
//登出
-(void)logoutBut;
@end

NS_ASSUME_NONNULL_END
