//
//  HXRViewController.m
//  MARSDKDemo
//
//  Created by 火星人 on 2021/12/2.
//

#import "HXRViewController.h"
#import <MARSDKCore/MARSDK.h>
#import <MARSDKCore/MARSDKCore.h>
@interface HXRViewController ()<MARSDKDelegate>

@end

@implementation HXRViewController
static id _instance = nil;

+ (HXRViewController *) shareInstance
{
    return [[self alloc] init];
}

+ (instancetype)allocWithZone:(struct _NSZone *)zone{
//     只进行一次
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [super allocWithZone:zone];
    });
    return _instance;
}

-(id)init{
   
    NSLog(@"1111111");
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _instance = [super init];
        [[MARSDK sharedInstance] setDelegate:self];
        [[MARSDK sharedInstance] performSelector:@selector(setupWithParams:) withObject:nil afterDelay:0];

    });
    return _instance;
}
- (void)viewDidLoad {
    [super viewDidLoad];
    NSLog(@"88888888");

}

//登录
- (void)onLoginClick{
    NSLog(@"22222222");

    [[MARSDK sharedInstance] login];
}
//登出
-(void)logoutBut
{
    [[MARSDK sharedInstance] logout];

}
//切换账号
-(void)switchAccount
{
    [[MARSDK sharedInstance] switchAccount];
}

//支付
- (void)payBtnClick:(id)sender {
    
    [[MARAction sharedInstance] purchase:@{
            MAR_ACTION_KEY_SUCCESS: @"1",
            MAR_ACTION_KEY_SERVERID: @"1",
            MAR_ACTION_KEY_SERVER_NAME:@"一区",
            MAR_ACTION_KEY_ROLEID:@"1",
            MAR_ACTION_KEY_ROLE_NAME:@"天下第一",
            MAR_ACTION_KEY_ROLE_LEVEL:@"100",
            MAR_ACTION_KEY_PRODUCT_TYPE: @"礼包",
            MAR_ACTION_KEY_PRODUCTID: @"p1",
            MAR_ACTION_KEY_PRODUCT_NAME: @"60钻石",
            MAR_ACTION_KEY_PRODUCT_NUM: @"1",
            MAR_ACTION_KEY_PAY_TYPE: @"channelId",
            MAR_ACTION_KEY_CURRENCY: @"CNY",
            MAR_ACTION_KEY_PRICE: @"600",    //fen
            MAR_ACTION_KEY_ORDERID: @"542rwer223244"
    }];
    
    
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyyMMdd"];
    NSString *orderId = [NSString stringWithFormat:@"%@%08d", [formatter stringFromDate:[NSDate date]], arc4random() % 10000000];
    
    MARProductInfo* productInfo = [[MARProductInfo alloc] init];
    productInfo.orderID = orderId;
    productInfo.productName = @"一元充值";
    productInfo.productDesc = @"礼包1";
    productInfo.productId = @"1";
//    productInfo.productId = @"com.sx.MHJY.08";
    productInfo.price = [NSNumber numberWithInt:1];
    productInfo.buyNum = 1;
    productInfo.coinNum = 900;
    productInfo.roleId = @"1";
    productInfo.roleName = @"角色名称";
    productInfo.roleLevel = @"66";
    productInfo.serverId = @"1";
    productInfo.serverName = @"桃源";
    productInfo.vip = @"1";
    productInfo.extension = @"";
    productInfo.notifyUrl = @"http://110.54.33.45/game/pay/notify";
    
//    NSUserDefaults* userDefaults = [NSUserDefaults standardUserDefaults];
//    NSString* playId = [userDefaults valueForKey:@"playId"];
//    NSString* username = [userDefaults valueForKey:@"username"];
//    NSString *token = [userDefaults objectForKey: @"token"];
//    NSMutableDictionary *d = [NSMutableDictionary dictionaryWithDictionary:@ {
//        @"extension" : [NSString stringWithFormat: @"{ \"playId\": \"%@\", \"username\": \"%@\"}",
//                        playId, username],
//        @"token" : token
//    }];
//
//    NSLog(@"userLogin = %@", d);
    
    [[MARSDK sharedInstance].defaultPay pay:productInfo];

}

//获取当前视图
-(UIView *)GetView
{
    NSLog(@"333333");

    return [self GetViewController].view;
}
//获取当前ViewController
-(UIViewController *)GetViewController
{
    NSLog(@"4444444444");

    return self;
}



-(void) OnPlatformInit:(NSDictionary*)param
{
    
    NSLog(@"OnPlatformInit====%@",param);
}

//登录成功回调
-(void) OnUserLogin:(NSDictionary*)param
{
    NSLog(@"555555");

    NSLog(@"OnUserLogin = %@", param);
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:[param objectForKey:@"token"] forKey:@"token"];
    [userDefaults setObject:[param objectForKey:@"userId"] forKey:@"userId"];
}

//登出成功回调
-(void) OnUserLogout:(NSDictionary*)param
{
    NSLog(@"OnUserLogout====%@",param);
}
//支付成功回调
-(void) OnPayPaid:(NSDictionary*)param
{
    NSLog(@"OnPayPaid====%@",param);
}
//实名成功
-(void) OnRealName:(NSDictionary *)params
{
    int isRealName = [[params valueForKey:@"isRealName"] intValue];
    int age = [[params valueForKey:@"age"] intValue];
    
    if(isRealName == 1){
        NSLog(@"user is realnamed ");
    }else {
        NSLog(@"user is not realnamed");
    }
}



//弹出对话框 返回错误信息
- (void)showAlertView:(NSString *)message{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:message delegate:self cancelButtonTitle:@"确定" otherButtonTitles:nil, nil];
    [alert show];
}


@end
