//
//  TICWebViewController.h
//  TIC_Web_SaaS_SDK
//
//  Created by AlexiChen on 2020/5/6.
//  Copyright © 2020 AlexiChen. All rights reserved.
//
// WebSaaSSDKVersion : 1.0.126
// WebGitCommitID : 96da3d347c8949ca504ab00ff3306ab8650f28ff

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *_Nonnull const TIC_Web_SaaS_SDK_Version;

@class TICWebViewController;

typedef void (^TICWebOpenUrlFailedBlock)(NSString *module, int code, NSString *_Nullable desc);
typedef NSDictionary *_Nullable (^TICWebOpenUrlContinueBlock)(void);
typedef void (^TICWebOpenUrlBlock)(TICWebViewController *webController);
typedef void (^TICWebOpenUrlFinishBlock)(TICWebViewController *webController, BOOL openSucc);

@interface TICWebViewController : UIViewController

// 使用-initWithURL:roomOption:mainWebOption 进行构建
+ (instancetype)new  __attribute__((unavailable("Use -initWithURL:roomOption:mainWebOption instead")));
- (instancetype)init __attribute__((unavailable("Use -initWithURL:roomOption:mainWebOption instead")));

/**
* 使用H5+Native方式使用
* @param url : webview要打开的地址
* @param roomOption : 如果要进教室，配置UI相关的参数;
* @param webOption : webview相关的配置;
*/
- (instancetype)initWithURL:(NSURL * _Nonnull)url roomOption:(NSDictionary *_Nullable)roomOption mainWebOption:(NSDictionary *_Nullable)webOption;

/**
 * 当前是否在教室内;
 */
+ (BOOL)hasJoinedClassRoom;

/**
 * 用于从网页中打开上课地址的跳转，内部只解析跟上课相关的url
 * @param  url 网页中传入的url信息
 * @param  cantOpenBlock 经过解析后，发现不符合规则时回调
 * @param  handleBlock 经过解析后，发现符合规则时回调，如果需要底层继续处理，外部返回 @{continue:@(YES),roomOption:roomdic, mainWebOption:webOption }, continue必传， roomOption/mainWebOption非必传 ，详见-initWithURL:roomOption:mainWebOption 注释; 如果不需要，可返回nil, 或者 @{continue:@(NO)}
 * @param openBlock handleBlock返回YES时，内部自动创建一个TICWebViewController，如果openBlock不为空, 通过openBlock回调交由外部跳转TICWebViewController，如果openBlock为空，则由底层自动k跳转（可能与App当前结构冲突）
 * @param finishBlock 仅当openBlock为空时，如果底层自动打开打开成功或失败回调
 */
+ (void)canOpenUrl:(NSURL *_Nonnull)url cantOpen:(TICWebOpenUrlFailedBlock _Nullable)cantOpenBlock continueHandle:(TICWebOpenUrlContinueBlock _Nullable)handleBlock openHandle:(TICWebOpenUrlBlock _Nullable)openBlock finish:(TICWebOpenUrlFinishBlock _Nullable)finishBlock;

@end

NS_ASSUME_NONNULL_END
