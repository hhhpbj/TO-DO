//
//  Constraints.h
//  TO-DO
//
//  Created by Siegrain on 16/5/7.
//  Copyright © 2016年 com.siegrain. All rights reserved.
//

/**
 *  帮助宏
 */
#ifndef Macros_h
#define Macros_h

#import "DataKeys.h"
#import "NSObject+PropertyName.h"

//获取颜色，格式0xFFFFFF
#define ColorWithRGB(rgbValue)                                           \
    [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 \
                    green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0    \
                     blue:((float)(rgbValue & 0xFF)) / 255.0             \
                    alpha:1.0]

//屏幕尺寸
#define kScreenWidth ([[UIScreen mainScreen] bounds].size.width)
#define kScreenHeight ([[UIScreen mainScreen] bounds].size.height)

//判断网络状态
#define isNetworkUnreachable ([AppDelegate globalDelegate].reachability.currentReachabilityStatus == RealStatusNotReachable)

//获取属性名
#define PropertyName(object, property) ([object stringWithProperty:property])

//获取系统语言
#define SystemLanguege ([NSLocale preferredLanguages][0])

//判断是否是中国地区
#define isChina ([SystemLanguege rangeOfString:@"zh-Han"].location != NSNotFound)

//简化本地化字符串宏
#define Localized(string) (NSLocalizedString(string, nil))

//获取info.plist的值
#define InfoDictionary(key) ([[NSBundle mainBundle] infoDictionary][key])

//拼接本地化字符串
#define ConcatLocalizedString1(str1, str2) ([NSString stringWithFormat:@"%@%@", NSLocalizedString(str1, nil), NSLocalizedString(str2, nil)])
#define ConcatLocalizedString2(str1, str2, str3) ([NSString stringWithFormat:@"%@%@%@", NSLocalizedString(str1, nil), NSLocalizedString(str2, nil), NSLocalizedString(str3, nil)])

//根据ID和类型获取图片前缀
#define GetPicturePrefix(type, id) ([NSString stringWithFormat:@"%@%@/", type, id])

//根据图片相对路径获取完整的NSURL
#define GetPictureUrl(urlStr, style) ([NSURL URLWithString:[NSString stringWithFormat:@"%@%@-%@", kQiniuDomain, urlStr, style]])

//控制状态栏网络菊花
#define ApplicationNetworkIndicatorVisible(isVisible) ([[UIApplication sharedApplication] setNetworkActivityIndicatorVisible:isVisible])

//MagicRecord Save
#define MR_saveAndWait() [[NSManagedObjectContext MR_defaultContext] MR_saveToPersistentStoreAndWait];
#endif