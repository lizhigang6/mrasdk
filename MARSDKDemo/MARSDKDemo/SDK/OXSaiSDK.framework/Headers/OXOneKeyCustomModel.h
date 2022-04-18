//
//  OXOneKeyCustomModel.h
//
//  Created by JG on 2019/11/27.
//  Copyright © 2019年 OX. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class OXOrientationLayOut;
/*
 注： 授权页一键登录按钮、运营商品牌标签、运营商条款必须显示，不得隐藏，否则取号能力可能被运营商关闭
 **/

//授权页UI配置

@interface OXOneKeyCustomModel: NSObject
#pragma mark - 自定义
/**
 *添加自定义控件
 *自定义控件坐标原点为屏幕左上角
 *可设置背景色及添加控件
 *横竖屏需要自主适配
 **/
@property (nonatomic,copy,nullable)void(^customAreaView)(UIView * customAreaView);

/**
 *授权页自定义Loading
 * containerView为loading的全屏蒙版view
 * 请自行在containerView添加自定义loading
 * 设置block后，上述loading属性将无效
 * 横竖屏位置居中
 * 目前只支持居中设置
 */
@property (nonatomic,copy,nullable)void(^loadingView)(UIView * containerView);

/**
 *协议页自定义Loading
 *containerView为loading的全屏蒙版view
 *请自行在containerView添加自定义loading
 *横竖屏位置居中
 *目前只支持居中设置
*/
@property (nonatomic,copy,nullable)void(^webLoadingView)(UIView * containerView);

/**
 *添加自定义控件toast视图
 *未勾选协议时点击一键登录按钮触发
 *视图在规定时间内移除
 *默认1.5s
 *横竖屏需要自主适配
 */
@property (nonatomic,copy,nullable)void(^toastView)(UIView * containerView);

/**
 *添加自定义控件alert视图
 */
@property (nonatomic,copy,nullable)void(^alertView)(UIViewController * authPageVC);

#pragma mark - dismiss切换
/**
 *设置dismiss管理权限
 *设置YES用户需手动调用dismissLoginPage
 *类型：BOOL,default is NO
 *eg.@(YES)
 */
@property (nonatomic,strong)NSNumber * manualDismiss;
/**
*授权页弹起动画开关
*类型：BOOL,default is YES
*eg.@(YES)
*/
@property (nonatomic,strong)NSNumber * oxPresentViewControllerAnimated;

#pragma mark - 背景图片
/**
 *授权页-背景图片
 */
@property (nonatomic,strong) UIImage *oxBackgroundImg;

#pragma mark - 导航栏
/**
 *导航栏 是否隐藏
 *设置优先级高于oxNavigationBackgroundoxear
 *类型：BOOL,default is NO
 *eg.@(YES)
 */
@property (nonatomic,strong)NSNumber * oxNavigationBarHidden;
/**
 *导航栏 背景透明
 *类型：BOOL,default is NO
 *eg.@(YES)
 */
@property (nonatomic,strong)NSNumber * oxNavigationBackgroundoxear;
/**
 *导航栏标题
 */
@property (nonatomic,strong)NSAttributedString * oxNavigationAttributesTitleText;
/**
 *导航栏右侧自定义按钮
 */
@property (nonatomic,strong)UIBarButtonItem * oxNavigationRightControl;
/**
 *导航栏左侧自定义按钮
 **/
@property (nonatomic,strong)UIBarButtonItem * oxNavigationLeftControl;
/**
 *导航栏左侧返回按钮图片
 */
@property (nonatomic,strong)UIImage   * oxNavigationBackBtnImage;
/**
 *导航栏自带返回按钮隐藏
 *类型：BOOL,default is NO
 * eg.@(YES)
 * */
@property (nonatomic,strong)NSNumber  * oxNavigationBackBtnHidden;
/**
 *返回按钮图片缩进
 *类型：UIEdgeInsetsMake
 *[NSValue valueWithUIEdgeInsets:UIEdgeInsetsMake(0, 0, 0, -15)]
 */
@property (nonatomic,strong)NSValue * oxNavBackBtnImageInsets;
/**
 *导航栏 背景色
 *default is white
 */
@property (nonatomic,strong)UIColor  * oxNavigationBarTintColor;
/**
 *导航栏 背景图片
 */
@property (nonatomic,strong)UIImage  * oxNavigationBackgroundImage;
/**
 *导航栏 导航栏底部分割线
 */
@property (nonatomic,strong)UIImage  * oxNavigationShadowImage;

#pragma mark - 状态栏
/**
 *UIBarStyleDefault：状态栏显示 黑
 *UIBarStyleBlack：状态栏显示 白
 *eg. @(UIBarStyleBlack)
 */
@property (nonatomic,strong)NSNumber * oxNavigationBarStyle;

#pragma mark - LOGO
/**
 *LOGO图片
 */
@property (nonatomic,strong)UIImage  * oxLogoImage;
/**
 *LOGO圆角
 *类型：CGFloat
 *eg.@(2.0)
 */
@property (nonatomic,strong)NSNumber * oxLogoCornerRadius;
/**
 *LOGO隐藏
 *类型：BOOL,default is NO
 *eg.@(NO)
 */
@property (nonatomic,strong)NSNumber * oxLogoHiden;

#pragma mark - 手机号
/**
 *手机号颜色
 */
@property (nonatomic,strong)UIColor  * oxPhoneNumberColor;
/**
 *手机号字体
 */
@property (nonatomic,strong)UIFont   * oxPhoneNumberFont;
/**
 *手机号对齐方式
 *类型：NSTextAlignment,default is NSTextAlignmentCenter
 *eg.@(NSTextAlignmentCenter)
 */
@property (nonatomic,strong)NSNumber * oxPhoneNumberTextAlignment;

#pragma mark - 登录按钮
/**
 *按钮文字
 */
@property (nonatomic,copy)NSString   * oxLoginBtnText;
/**
 *按钮文字颜色
 */
@property (nonatomic,strong)UIColor  * oxLoginBtnTextColor;
/**
 *按钮背景颜色
 */
@property (nonatomic,strong)UIColor  * oxLoginBtnBgColor;
/**
 *按钮文字字体
 */
@property (nonatomic,strong)UIFont   * oxLoginBtnTextFont;
/**
 *按钮背景图片
 */
@property (nonatomic,strong)UIImage  * oxLoginBtnNormalBgImage;
/**
 *按钮背景高亮图片
 */
@property (nonatomic,strong)UIImage  * oxLoginBtnHightLightBgImage;
/**
 *按钮边框颜色
 */
@property (nonatomic,strong)UIColor  * oxLoginBtnBorderColor;
/**
 *按钮圆角
 *类型：CGFloat
 * eg.@(5)
 */
@property (nonatomic,strong)NSNumber * oxLoginBtnCornerRadius;
/**
 *按钮边框
 *类型:CGFloat
 *eg.@(2.0)
 */
@property (nonatomic,strong)NSNumber * oxLoginBtnBorderWidth;

#pragma mark - 条款选择框
/**
 *协议勾选框隐藏
 *类型：BOOL,default is NO
 *eg.@(YES)
 */
@property (nonatomic,strong) NSNumber *oxCheckBoxHidden;
/**
 *协议勾选框选中
 *类型：BOOL,default is NO
 *eg.@(YES)
 */
@property (nonatomic,strong) NSNumber *oxCheckBoxValue;
/**
 *协议勾选框
 *类型:CGSize
 *eg.[NSValue valueWithCGSize:CGSizeMake(25, 25)]
 */
@property (nonatomic,strong) NSValue *oxCheckBoxSize;
/**
 *协议勾选框 图片缩进
 *类型：UIEdgeInset
 *eg.[NSValue valueWithUIEdgeInsets:UIEdgeInsetsMake(2, 2, 2, 2)]
 */
@property (nonatomic,strong) NSValue *oxCheckBoxImageEdgeInsets;
/**
 *协议勾选框 非选中状态图片
 */
@property (nonatomic,strong) UIImage  *oxCheckBoxUncheckedImage;
/**
 *协议勾选框 选中状态图片
 */
@property (nonatomic,strong) UIImage  *oxCheckBoxCheckedImage;

#pragma mark - 隐私条款
/**
 *隐私条款名称颜色：
 *@[条款颜色UIColor*,基础文字颜色UIColor*]
 *eg.@[[UIColor lightGrayColor],[UIColor greenColor]]
 */
@property (nonatomic,strong) NSArray<UIColor*> *oxAppTermsColor;
/**
 *隐私条款文字字体
 */
@property (nonatomic,strong)UIFont  * oxAppTermsTextFont;
/**
 *隐私条款内边距
 *类型：UIEdgeInsets
 *eg.[NSValue valueWithUIEdgeInsets:UIEdgeInsetsMake(2, 2, 2, 2)]
 */
@property (nonatomic,strong) NSValue *oxAppTermsEdgeInsets;
/**
 *隐私条款文字对齐方式
 *类型:NSTextAlignment
 *eg.@(NSTextAlignmentCenter)
 */
@property (nonatomic,strong)NSNumber * oxAppTermsTextAlignment;
/**
 *运营商隐私条款书名号
 *类型:BOOL,default is NO
 *eg.@(YES)
 */
@property (nonatomic,strong)NSNumber * oxAppTermsPunctuationMarks;
/**
 * 获取条款高度
 * 当条款layout只传入宽度时，高度自适应
*/
@property (nonatomic,assign,readonly)CGFloat  oxAppTermsHeight;
/**
 *行间距
 *类型：CGFloat
 *eg.@(2.0)
 */
@property (nonatomic,strong)NSNumber* oxAppTermsLineSpacing;
/**
 *是否需要sizeToFit,设置后与宽高约束的冲突请自行考虑
 *类型:BOOL
 *eg.@(YES)
 */
@property (nonatomic,strong)NSNumber* oxAppTermsNeedSizeToFit;
/**
 *隐私的内容模板：
 *1、全句可自定义但必须保留"&&默认&&"字段表明SDK默认协议,否则设置不生效
 *2、协议1和协议2的名称要与数组 str1 和 str2 ... 里的名称 一样
 *3、必设置项（参考SDK的demo）
 *oxPrivacieDemo设置内容：登录并同意&&默认&&和百度协议1、京东协议2登录并支持一键登录
 *展示：   登录并同意中国移动条款协议和百度协议1、京东协议2登录并支持一键登录
 */
@property (nonatomic,copy) NSAttributedString *oxTermsTemplate;

/**
 *隐私条款:数组（务必按顺序）要设置NSLinkAttributeName属性可以跳转协议
 *对象举例：
 *NSAttributedString *str1 = [[NSAttributedString alloc]initWithString:@"百度协议" attributes:@{NSLinkAttributeName:@"https://www.baidu.com"}];
 *@[str1,,str2,str3,...]
 */
@property (nonatomic,strong) NSArray <NSAttributedString *> *oxTerms;

#pragma mark - 协议页
/**
*NavigationBar.barStyle：默认UIBarStyleBlack
*UIBarStyleDefault：状态栏显示 黑
*UIBarStyleBlack：状态栏显示 白
*
*eg. @(UIBarStyleBlack)
*/
@property (nonatomic,strong)NSNumber * oxAppTermsWebNavigationBarStyle;
/**
 * 自定义协议页
 * 配合代理方法- (void)oxActionUsersInteract:(NSDictionary *)action一起使用
*/
@property (nonatomic,strong)NSNumber * oxAppTermsCustom;
/**
 *协议页标题
 */
@property (nonatomic,strong)NSAttributedString * oxAppTermsWebTitle;
/**
 *协议页自带标题样式
 */
@property (nonatomic,strong)NSDictionary * oxAppTermsWebTitleAttributes;
/**隐私协议WEB页面导航返回按钮图片
 * 不设置同授权页
 */
@property (nonatomic,strong)UIImage * oxAppTermsWebBackBtnImage;
/**协议页导航栏背景图片
 *不设置同授权页
 */
@property (nonatomic,strong)UIImage * oxWebNavigationBackgroundImage;
/**协议页导航栏背景颜色
 *不设置同授权页
*/
@property (nonatomic,strong)UIColor * oxWebNavigationBarTintColor;
/**
 *协议页开启弹框模式
 *类型:BOOL,default is NO
 *eg.@(NO)
 */
@property (nonatomic,strong)NSNumber * oxAppTermsPageWindow;
/**
 *协议页弹框圆角
 *类型：CGFloat
 *eg.@(20)
 */
@property (nonatomic,strong)NSNumber * oxAppTermsPageWindowRadius;
/**
 *协议页弹框模式关闭按钮高度
 *类型：CGFloat
 *eg.@(45)
 */
@property (nonatomic,strong)NSNumber * oxAppTermsPageWindowCloseHeight;
/**
 *协议页弹框模式关闭按钮颜色
 */
@property (nonatomic,strong)UIColor * oxAppTermsPageWindowCloseUIColor;
/**
 *协议页弹框模式关闭按钮文本
 */
@property (nonatomic,strong)NSAttributedString * oxAppTermsPageWindowCloseText;

#pragma mark - 运营商标识

/**
 *slogan文字字体
 */
@property (nonatomic,strong) UIFont   * oxSloganTextFont;
/**
 *slogan文字颜色
 */
@property (nonatomic,strong) UIColor  * oxSloganTextColor;
/**
 *slogan文字对齐方式
 *类型:NSTextAlignment
 *eg.@(NSTextAlignmentCenter)
 */
@property (nonatomic,strong) NSNumber * oxSlogaTextAlignment;

#pragma mark - Loading
/**
 *Loading 大小
 *类型:CGSize
 *eg.[NSValue valueWithCGSize:CGSizeMake(50, 50)]
 */
@property (nonatomic,strong) NSValue *oxLoadingSize;
/**
 *Loading 圆角
 *类型:CGFloat
 *eg.@(5)
 */
@property (nonatomic,strong) NSNumber *oxLoadingCornerRadius;
/**
 *Loading 背景色
 *eg.[UIColor colorWithRed:0.8 green:0.5 blue:0.8 alpha:0.8];
 */
@property (nonatomic,strong) UIColor *oxLoadingBackgroundColor;
/**
 *Loading 颜色
 */
@property (nonatomic,strong) UIColor *oxLoadingColor;
/**
 *UIActivityIndicatorViewStyle
 *eg.@(UIActivityIndicatorViewStyleWhiteLarge)
 */
@property (nonatomic,strong) NSNumber *oxLoadingIndicatorStyle;

#pragma mark - toast视图
/**
 *是否开启toast视图
 *类型：BOOL,default is YES
 *eg.@(YES)
 */
@property (nonatomic,strong)NSNumber * oxShowToast;
/**
 *toast文本
 */
@property (nonatomic,strong)NSString * oxShowToastStr;
/**
 *toast视图显示时常
 *类型:CGFloat 默认  eg.@(1.5)
 * toast视图在1.5秒后移除视图
 */
@property (nonatomic,strong)NSNumber * oxShowToastTime;

#pragma mark - 横竖屏设置
/**
 *是否支持自动旋转 BOOL
 *类型:BOOL,default is NO
 *eg.@(YES)
 */
@property (nonatomic,strong) NSNumber * oxShouldAutorotate;
/**
 *支持方向 UIInterfaceOrientationMask
 *如果设置只支持竖屏，只需设置oxOrientationLayOutPortrait竖屏布局对象
 *如果设置只支持横屏，只需设置oxOrientationLayOutLandscape横屏布局对象
 *横竖屏均支持，需同时设置oxOrientationLayOutPortrait和oxOrientationLayOutLandscape
 */
@property (nonatomic,strong) NSNumber * oxSupportedInterfaceOrientations;

#pragma mark - 窗口授权页设置
/**
 *以窗口方式显示
 *类型：BOOL, default is NO
 *eg.@(YES)
 */
@property (nonatomic,strong) NSNumber * oxAuthTypeUseWindow;
/**
 *窗口圆角
 *类型:CGFloat
 *eg.@(10)
 */
@property (nonatomic,strong) NSNumber * oxAuthWindowCornerRadius;

/**
 *窗口展示动画
 *oxAuthWindowModalTransitionStyle系统自带的弹出方式 仅支持以下三种
 *UIModalTransitionStyleCoverVertical 底部弹出
 *UIModalTransitionStyleCrossDissolve 淡入
 *UIModalTransitionStyleFlipHorizontal 翻转显示
 */
@property (nonatomic,strong) NSNumber * oxAuthWindowModalTransitionStyle;

#pragma mark - 授权页布局
/**
 *竖屏布局配置对象 -->创建一个布局对象，设置好控件约束属性值，再设置到此属性中
 *竖屏：UIInterfaceOrientationPortrait|UIInterfaceOrientationPortraitUpsideDown
 *eg.OXOneKeyCustomModel * model = [OXOneKeyCustomModel new];
 *   OXOrientationLayOut *oxOrientationLayOutPortrait = [OXOrientationLayOut new];
 *   oxOrientationLayOutPortrait.oxAuthWindowOrientationWidth = @(330);
 *   oxOrientationLayOutPortrait.oxAuthWindowOrientationHeight = @(400);0);
 *   ...
 *   model.oxOrientationLayOutPortrait = oxOrientationLayOutPortrait;
 */
@property (nonatomic,strong) OXOrientationLayOut * oxOrientationLayOutPortrait;
/**
 *横屏布局配置对象 -->创建一个布局对象，设置好控件约束属性值，再设置到此属性中
 *横屏：UIInterfaceOrientationLandscapeLeft|UIInterfaceOrientationLandscapeRight
 *eg.OXOneKeyCustomModel * model = [OXOneKeyCustomModel new];
 *   OXOrientationLayOut *oxOrientationLayOutLandscape = [OXOrientationLayOut new];
 *   oxOrientationLayOutLandscape.oxAuthWindowOrientationWidth = @(400);
 *   oxOrientationLayOutLandscape.oxAuthWindowOrientationHeight = @(250);
 *   ...
 *   model.oxOrientationLayOutLandscape = oxOrientationLayOutLandscape;
 */
@property (nonatomic,strong) OXOrientationLayOut * oxOrientationLayOutLandscape;

@end

/**横竖屏布局配置对象
 配置页面布局相关属性
 */
@interface OXOrientationLayOut : NSObject
/**
 *LOGO图片
 *约束均相对vc.view
 */
@property (nonatomic,strong)NSNumber * oxLayoutLogoLeft;
@property (nonatomic,strong)NSNumber * oxLayoutLogoTop;
@property (nonatomic,strong)NSNumber * oxLayoutLogoRight;
@property (nonatomic,strong)NSNumber * oxLayoutLogoBottom;
@property (nonatomic,strong)NSNumber * oxLayoutLogoWidth;
@property (nonatomic,strong)NSNumber * oxLayoutLogoHeight;
@property (nonatomic,strong)NSNumber * oxLayoutLogoCenterX;
@property (nonatomic,strong)NSNumber * oxLayoutLogoCenterY;

/**
 *手机号显示控件
 *layout 约束均相对vc.view
 */
@property (nonatomic,strong)NSNumber * oxLayoutPhoneLeft;
@property (nonatomic,strong)NSNumber * oxLayoutPhoneTop;
@property (nonatomic,strong)NSNumber * oxLayoutPhoneRight;
@property (nonatomic,strong)NSNumber * oxLayoutPhoneBottom;
@property (nonatomic,strong)NSNumber * oxLayoutPhoneWidth;
@property (nonatomic,strong)NSNumber * oxLayoutPhoneHeight;
@property (nonatomic,strong)NSNumber * oxLayoutPhoneCenterX;
@property (nonatomic,strong)NSNumber * oxLayoutPhoneCenterY;

/**
 *Slogan 运营商品牌标签："认证服务由中国移动/联通/电信提供" label
 *layout 约束均相对vc.view
 *注： 运营商品牌标签，不得隐藏
 */
@property (nonatomic,strong)NSNumber * oxLayoutSloganLeft;
@property (nonatomic,strong)NSNumber * oxLayoutSloganTop;
@property (nonatomic,strong)NSNumber * oxLayoutSloganRight;
@property (nonatomic,strong)NSNumber * oxLayoutSloganBottom;
@property (nonatomic,strong)NSNumber * oxLayoutSloganWidth;
@property (nonatomic,strong)NSNumber * oxLayoutSloganHeight;
@property (nonatomic,strong)NSNumber * oxLayoutSloganCenterX;
@property (nonatomic,strong)NSNumber * oxLayoutSloganCenterY;

/**一键登录按钮 控件
 *layout 约束均相对vc.view
 *注： 一键登录授权按钮 不得隐藏
 */
@property (nonatomic,strong)NSNumber * oxLayoutLoginBtnLeft;
@property (nonatomic,strong)NSNumber * oxLayoutLoginBtnTop;
@property (nonatomic,strong)NSNumber * oxLayoutLoginBtnRight;
@property (nonatomic,strong)NSNumber * oxLayoutLoginBtnBottom;
@property (nonatomic,strong)NSNumber * oxLayoutLoginBtnWidth;
@property (nonatomic,strong)NSNumber * oxLayoutLoginBtnHeight;
@property (nonatomic,strong)NSNumber * oxLayoutLoginBtnCenterX;
@property (nonatomic,strong)NSNumber * oxLayoutLoginBtnCenterY;

/**
 *隐私条款Terms
 *layout 约束均相对vc.view
 *条款高度会自适应
 *注： 运营商隐私条款 不得隐藏， 用户条款不限制
 */
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsLeft;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsTop;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsRight;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsBottom;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsWidth;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsHeight;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsCenterX;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsCenterY;

/**
 *协议页（弹框模式）
 *layout 约束均相对vc.view
 */
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsPageLeft;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsPageTop;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsPageRight;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsPageBottom;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsPageWidth;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsPageHeight;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsPageCenterX;
@property (nonatomic,strong)NSNumber * oxLayoutAppTermsPageCenterY;

/**窗口模式*/
/**窗口中心：CGPoint X Y*/
@property (nonatomic,strong) NSValue * oxAuthWindowOrientationCenter;
/**窗口左上角：frame.origin：CGPoint X Y*/
//@property (nonatomic,strong) NSValue * oxAuthWindowOrientationOrigin;
/**窗口大小：宽 float */
@property (nonatomic,strong) NSNumber * oxAuthWindowOrientationWidth;
/**窗口大小：高 float */
@property (nonatomic,strong) NSNumber * oxAuthWindowOrientationHeight;
//默认样式
+ (OXOrientationLayOut *)oxDefaultOrientationLayOut;
@end

NS_ASSUME_NONNULL_END
