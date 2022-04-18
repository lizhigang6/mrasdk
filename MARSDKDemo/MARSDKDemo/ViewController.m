//
//  ViewController.m
//  MARSDKDemo
//
//  Created by 火星人 on 2021/11/18.
//

#import "ViewController.h"
#import <MARSDKCore/MARSDK.h>
#import <MARSDKCore/MARSDKCore.h>

@interface ViewController ()<MARSDKDelegate>
{
    NSString* _uid;
}

@property (readonly) NSString* userID;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    [[MARSDK sharedInstance] setDelegate:self];
    [[MARSDK sharedInstance] performSelector:@selector(setupWithParams:) withObject:nil afterDelay:0];
    
    
   
    MARUserExtraData* extraData = [[MARUserExtraData alloc] init];
    extraData.dataType = TYPE_CREATE_ROLE;
    extraData.roleID = @"100";
    extraData.roleName = @"小兵";
    extraData.serverID = 1000;
    extraData.serverName = @"初来乍到";
    extraData.roleLevel = @"22";
    extraData.vip = @"101";
    //  extraData.moneyNum = 100;
    //  extraData.roleCreateTime = time(NULL);
    //  extraData.roleLevelUpTime = time(NULL);
    
    [[MARSDK sharedInstance] submitExtraData:extraData];
    
    
    if([[MARSDK sharedInstance] hasRealNameQuery]){
        
        [[MARSDK sharedInstance] realNameQuery];
    }
    else
    {
        // 渠道不支持实名查询接口，游戏可以调用自己的实名查询
    }
    
    if([[MARSDK sharedInstance] hasRealNameRegister]){
        [[MARSDK sharedInstance] realNameRegister];
    }
    else
    {
        // 渠道不支持实名查询接口，游戏可以调用自己的实名查询
    }

    UIButton *loginBut =[[UIButton alloc] initWithFrame:CGRectMake(20, 100, 200, 50)];
    [loginBut setTitle:@"登录" forState:UIControlStateNormal];
    [loginBut addTarget:self action:@selector(onLoginClick:) forControlEvents:UIControlEventTouchUpInside];
    [loginBut setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [self.view addSubview:loginBut];
    
    UIButton *logoutBut =[[UIButton alloc] initWithFrame:CGRectMake(20, 200, 200, 50)];
    [logoutBut setTitle:@"登出" forState:UIControlStateNormal];
    [logoutBut addTarget:self action:@selector(logoutBut:) forControlEvents:UIControlEventTouchUpInside];
    [logoutBut setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [self.view addSubview:logoutBut];
    
    
    
    
    UIButton *payBtn =[[UIButton alloc] initWithFrame:CGRectMake(20, 300, 200, 50)];
    [payBtn setTitle:@"充值" forState:UIControlStateNormal];
    [payBtn addTarget:self action:@selector(payBtnClick:) forControlEvents:UIControlEventTouchUpInside];
    [payBtn setTitleColor:[UIColor blackColor] forState:UIControlStateNormal];
    [self.view addSubview:payBtn];
    [[MARSDK sharedInstance] login];

    
}

//登录
- (void)onLoginClick:(UIButton *)sender {
   [[MARSDK sharedInstance] login];
//    [[HXRViewController shareInstance] onLoginClick];
}
//登出
-(void)logoutBut:(UIButton *)sender
{
   [[MARSDK sharedInstance] logout];
//    [[HXRViewController shareInstance] logoutBut];


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
//    productInfo.productId = @"1";
    productInfo.productId = @"com.sx.MHJY.08";
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

    
    
   

    
    [[MARSDK sharedInstance].defaultPay pay:productInfo];
    
    

}

//获取当前视图
-(UIView *)GetView
{
    NSLog(@"OnPlatformInit===222222");

    return [self GetViewController].view;
}
//获取当前ViewController
-(UIViewController *)GetViewController
{
    
    NSLog(@"OnPlatformInit===1111111");

    return self;
}



-(void) OnPlatformInit:(NSDictionary*)param
{
    
    NSLog(@"OnPlatformInit====%@",param);
}

//登录成功回调
-(void) OnUserLogin:(NSDictionary*)param
{
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

//-(void) OnEventWithCode:(int)code msg:(NSString*)msg
//{
//    NSLog(@"sdk event called.code:%d;msg:%@", code, msg);
//}
//
//-(void)OnEventCustom:(NSDictionary*)param
//{
//    NSString* name = [param valueForKey:@"name"];
//    NSDictionary* params = [param valueForKey:@"params"];
//
//    NSLog(@"msg:%@", params);
//
//}


//弹出对话框 返回错误信息
- (void)showAlertView:(NSString *)message{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:message delegate:self cancelButtonTitle:@"确定" otherButtonTitles:nil, nil];
    [alert show];
}


@end
