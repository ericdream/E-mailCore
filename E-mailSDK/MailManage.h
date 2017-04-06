//
//  MailManage.h
//  EMailSdk
//
//  Created by apple_Eric on 05/04/2017.
//  Copyright © 2017 wangshang. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EMFolder.h"
@protocol MailManageDelegate <NSObject>
@optional
- (void)mailLoinFail:(NSError *)error;
- (void)mailLoinSuccess;

@end
@interface MailManage : NSObject
@property(nonatomic,weak)id<MailManageDelegate>mailDelegate;
- (instancetype)instance;
- (void)loginWithHost:(NSString *)host
                 port:(unsigned int)port
                userName:(NSString *)userName
                password:(NSString *)pw;

/**
 获取邮件目录

 @param foldersBlock foldersBlock description
 */
- (void)loadAllFolders:(void(^)(NSArray *folders))foldersBlock;

/**
 获取一个目录下的所有邮件

 @param folder folder description
 @param emails emails description
 */
- (void)loadAllEmailWifhFolder:(EMFolder *)folder dataCallBack:(void(^)(NSArray *emails))emails;
@end
