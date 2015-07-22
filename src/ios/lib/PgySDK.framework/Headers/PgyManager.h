//
//  PgyManager.h
//  PgySDK
//
//  Created by Scott Lei on 2015-1-7.
//  Copyright (c) 2015年 蒲公英. All rights reserved.
//  Version: 2.3

#import <Foundation/Foundation.h>

/**
 *  激活反馈功能的方式
 */
typedef NS_ENUM(NSInteger, KPGYFeedbackActiveType){
    /**
     *  摇晃手机激活用户反馈界面
     */
    kPGYFeedbackActiveTypeShake = 0,
    /**
     *  在界面上三指下滑或者上滑激活用户反馈界面
     */
    kPGYFeedbackActiveTypeThreeFingersPan = 1,
};

@interface PgyManager : NSObject

/**
 *  是否显示蒲公英SDK的Debug Log，如果遇到SDK无法正常工作的情况可以开启此标志以确认原因，默认为关闭。
 */
@property (nonatomic, assign, getter = isDebugLogEnabled) BOOL enableDebugLog;

/**
 *  激活用户反馈的方式，如果不设置的话，则默认为摇一摇激活用户反馈界面。
 *  设置激活用户反馈方式需在调用 - (void)startManagerWithAppId:(NSString *)appId 之前。
 */
@property (nonatomic, assign) KPGYFeedbackActiveType feedbackActiveType;

/**
 *  开启或关闭用户手势反馈功能，默认为开启。
 */
@property (nonatomic, assign, getter=isFeedbackEnabled) BOOL enableFeedback;

/**
 *  设置用户反馈界面的颜色，颜色会影响到Title的背景颜色和录音按钮的边框颜色，默认为0x37C5A1。
 */
@property (nonatomic, retain) UIColor *themeColor;

/**
 *  激活用户反馈界面的阈值，数字越小灵敏度越高，默认为2.3。
 */
@property (nonatomic, assign) double shakingThreshold;

/**
 *  初始化蒲公英SDK
 *
 *  @return PgyManger的单例对象
 */
+ (PgyManager *)sharedPgyManager;

/**
 *  启动蒲公英SDK
 *  如果需要自定义用户反馈激活模式，则需要在调用此方法之前设置。
 *  @param appId 应用程序ID，从蒲公英网站上获取。
 */
- (void)startManagerWithAppId:(NSString *)appId;

/**
 *  显示用户反馈界面
 */
- (void)showFeedbackView;

/**
 *  检查是否有版本更新。
 *  如果开发者在蒲公英上提交了新版本，则调用此方法后会弹出更新提示界面。
 */
- (void)checkUpdate;

/**
 *  检查是否有版本更新。
 *
 *  @param delegate 自定义checkUpdateWithDelegete方法的对象
 *  @param updateMethodWithDictionary 当checkUpdateWithDelegete事件完成时此方法会被调用，包含更新信息的字典也被回传。
 *         如果有更新信息，那么字典里就会包含新版本的信息，否则的话字典信息为nil。
 */
- (void)checkUpdateWithDelegete:(id)delegate selector:(SEL)updateMethodWithDictionary;

/**
 *  检查更新是根据本地存储的Build号和蒲公英上的最新Build号比较来完成的。如果调用checkUpdateWithDelegete，SDK会获取到最新的
 *  Build号，但是checkUpdateWithDelegete方法自己不会来更新本地版本号，如果需要更新本地版本号，则需要调用此方法。
 */
- (void)updateLocalBuildNumber;

/**
 *  上报Exception，Exception的name，reason，callStackSymbols会被上报至蒲公英服务器。
 *
 *  @param exception 异常
 */
- (void)reportException:(NSException *)exception;

@end
