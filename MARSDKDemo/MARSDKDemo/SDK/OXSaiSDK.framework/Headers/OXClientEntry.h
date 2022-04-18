//
//  OXClientEntry.h
//  OXExample
//
//  Created by JG on 2019/1/29.
//  Copyright © 2019年 OX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXOneKeyCustomModel.h"
/**
 操作类型
 该每个SDK方法对应一个操作类型
 */
typedef NS_ENUM(NSInteger, OXActionType) {
    OXActionTypeNone = 0,//空值
    OXActionTypeInitSdk = 1,//SDK初始化
    OXActionTypeVerifyByOnekey = 2,//一键登录 直接获取手机号
    OXActionTypeGetOnekeyLoginToken = 3,//一键登录 获取置换手机号Token
    OXActionTypeVerifyBySmsStart = 4,//短信验证开启
    OXActionTypeVerifyBySmsCheck = 5,//短信校验
    OXActionTypeGetMobileAuthToken = 7,//本机号码校验
    OXActionTypePreLogin = 9,//预取号
    
};
/**
 代理：OXActionDelegate
 */
@protocol OXActionDelegate <NSObject>
@required

/**
 服务回调 (一键登录、本机号码校验、短信验证)
 
 @param result 回调参数
 */
- (void)onActionResult:(NSDictionary *)result;

/**
 SDK初始化回调
 @param response 回调参数
 */
- (void)oxActionInitSdkResponse:(NSDictionary *)response;

/**
 * 登录按钮、条款、协议勾选框的事件监听方法
 * 登录按钮：type=1，value =1（同意条款） value =0（未同意条款）
 * 协议勾选框：type=2，value =1（选中） value =0（未选中）
 * 条款：type=3，value =0（第一个条款） value =1（第二个条款）value =2（第三个条款）
*/
- (void)oxActionUsersInteract:(NSDictionary *)action;
@end

@interface OXClientEntry : NSObject
/**
 *网络类型及运营商（双卡下，获取上网卡的运营商）
 *"carrier"     运营商： 0.未知 / 1.中国移动 / 2.中国联通 / 3.中国电信
 *"networkType" 网络类型： 0.无网络/ 1.数据流量 / 2.wifi / 3.数据+wifi
 *@return  @{NSString : NSNumber}
 */
+ (NSDictionary<NSString *,NSNumber *> *)networkInfo;

/**
SDK初始化状态
  0,//未初始化
  1, // 成功
  2, // 正在初始化
  3, // 初始化失败
 */
+ (NSInteger)sdkInitStatus;

/**
 *SDK初始化
 *@param params 请求参数
 *key: app_id    value:后台申请的appId
 *key: app_secret   value:后台申请的appSecret
 *@param delegate 代理
 */
+ (void)initWithParams:(NSDictionary *)params
                delegate:(id<OXActionDelegate>)delegate;
/**
 *服务接口
 *(一键登录、本机号码校验、短信验证)
 *@param type 请求类型
 *@param params 请求参数
 */
+ (void)requestAction:(OXActionType)type params:(NSDictionary *)params;
/**
 *自定义一键登录UI样式参数
 *@param viewModel UI实例Model（OXOneKeyCustomModel.h可查看属性）
 */
+ (void)oneKeyCustomUIWithParams:(OXOneKeyCustomModel *)viewModel;
/**
 *控制台日志输出控制（默认关闭）
 *@param enable 开关参数
 */
+ (void)printConsoleEnable:(BOOL)enable;
/**
 *关闭授权页
 */
+ (void)dismissLoginPageAnimated: (BOOL)flag completion: (void (^)(void))completion;
/**
 *清除预取号缓存
*/
+ (void)deletePreLoginCache;
/**
 *获取当前SDK版本
 */
+ (NSString *)sdkVersion;
/**
 *获取本地风控信息
 * debugging 设备处于正在被调试状态
 * multiple_app_on 多开
 * root 越狱
 * simulator 模拟器操作
*/
+ (NSDictionary *)getLocalDeviceEnv;

///设置条款勾选框状态
+ (void)setCheckBoxStatus:(BOOL)status;
@end


