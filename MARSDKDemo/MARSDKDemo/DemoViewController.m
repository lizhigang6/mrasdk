//
//  DemoViewController.m
//  MARSDKDemo
//
//  Created by 火星人 on 2021/11/18.
//

#import "DemoViewController.h"

@implementation DemoViewController
{
    NSString* _uid;
}


-(UIView *)GetView
{
    return [self GetViewController].view;
}

-(UIViewController *)GetViewController
{
    return self;
}

-(NSString*) userID
{
    return _uid;
}

-(void) OnPlatformInit:(NSDictionary*)param
{
    [self SendCallback:"OnInitSuc" withParams:param];
}

-(void) OnUserLogin:(NSDictionary*)param
{
    NSLog(@"OnUserLogin = %@", param);
    NSUserDefaults *userDefaults = [NSUserDefaults standardUserDefaults];
    [userDefaults setObject:[param objectForKey:@"token"] forKey:@"token"];
    [userDefaults setObject:[param objectForKey:@"userId"] forKey:@"userId"];
    [self SendCallback:"OnLoginSuc" withParams:param];
}

-(void) OnUserLogout:(NSDictionary*)param
{
    [self SendCallback:"OnLogout" withParams:param];
}

-(void) OnPayPaid:(NSDictionary*)param
{
    [self SendCallback:"OnPaySuc" withParams:param];
}

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

-(void) OnEventWithCode:(int)code msg:(NSString*)msg
{
    NSLog(@"sdk event called.code:%d;msg:%@", code, msg);
}

-(void)OnEventCustom:(NSDictionary*)param
{
    NSString* name = [param valueForKey:@"name"];
    NSDictionary* params = [param valueForKey:@"params"];
    
    [self SendCallback:[name UTF8String] withParams:params];
}

-(void) SendCallback:(const char*)method withParams:(NSDictionary *)params
{
    NSString* jsStr = nil;
    
    if (params)
    {
        NSError* error;
        NSData* data = [NSJSONSerialization dataWithJSONObject:params options:kNilOptions error:&error];
        
        if (data)
        {
            jsStr = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        }
    }
    
    [self SendCallback:method withMessage:jsStr];
}

-(void) SendCallback:(const char*)method withMessage:(NSString*)msg
{
    if (msg)
    {
        NSLog(@"Callback %s %@", method, msg);
    }
    else
    {
        NSLog(@"Callback %s", method);
    }
}

- (void)showAlertView:(NSString *)message{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"" message:message delegate:self cancelButtonTitle:@"确定" otherButtonTitles:nil, nil];
    [alert show];
}

////////////////////////////////////////////////////////////


- (void)viewDidLoad {
    [super viewDidLoad];
    
    [[MARSDK sharedInstance] setDelegate:self];
    [[MARSDK sharedInstance] performSelector:@selector(setupWithParams:) withObject:nil afterDelay:0];
    
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
