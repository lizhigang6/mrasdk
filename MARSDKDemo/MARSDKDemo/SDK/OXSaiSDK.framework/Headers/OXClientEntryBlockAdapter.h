//
//  OXResultBlockAdapter.h
//  OXExample
//
//  Created by w on 2020/2/17.
//  Copyright © 2020 OX. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OXClientEntry.h"
NS_ASSUME_NONNULL_BEGIN
typedef void(^OXResult)(NSDictionary *result );
@interface OXClientEntryBlockAdapter : OXClientEntry
/**
 使用block回调方式，必须使用SDK初始化的block方法进行初始化
 */

/**
*SDK初始化
*@param params 请求参数
*key: app_id    value:后台申请的appId
*key: app_secret   value:后台申请的appSecret
*/
+(void)initWithParams:(NSDictionary *)params result:(OXResult _Nonnull)result;

/**
*服务接口
*(一键登录、本机号码校验、短信验证)
*@param type 请求类型
*@param params 请求参数
*/
+(void)requestAction:(OXActionType)type params:(NSDictionary *)params result:(OXResult _Nonnull)result;

@end

NS_ASSUME_NONNULL_END
