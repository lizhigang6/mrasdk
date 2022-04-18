//
//  DemoViewController.h
//  MARSDKDemo
//
//  Created by 火星人 on 2021/11/18.
//

#import <UIKit/UIKit.h>
#import <MARSDKCore/MARSDK.h>
NS_ASSUME_NONNULL_BEGIN

@interface DemoViewController : UINavigationController<MARSDKDelegate>
@property (readonly) NSString* userID;

@end

NS_ASSUME_NONNULL_END
