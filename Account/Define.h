
//
//  Define.h
//  GuideTalker
//
//  Created by 道说01 on 16/3/30.
//  Copyright (c) 2016年 道说01. All rights reserved.
//

//获取设备尺寸
#define kDeviceH ([UIScreen mainScreen].bounds.size.height)
#define kDeviceW ([UIScreen mainScreen].bounds.size.width)

// 获取屏幕宽高
#define f_Device_w         [UIScreen mainScreen].bounds.size.width
#define f_Device_h  	   [UIScreen mainScreen].bounds.size.height

// 根据iphone6 的效果图 尺寸比例 算出实际尺
#define W_i6real(f)              (f_Device_w * ((f)/375.f))
#define H_i6real(f)              (f_Device_h * ((f)/667.f))

//获得RGB颜色
#define IWColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
#define MainColor [UIColor colorWithRed:(240)/255.0 green:(150)/255.0 blue:(58)/255.0 alpha:1]

//获得字段的长度
//#define   TextLength(titleStr)  [titleStr boundingRectWithSize:CGSizeMake(0, 40) options:NSStringDrawingTruncatesLastVisibleLine attributes:@{NSFontAttributeName:[UIFont systemFontOfSize:17]} context:nil].size.width

#define  TextLength(titleStr) [titleStr sizeWithFont:[UIFont systemFontOfSize:15] constrainedToSize:CGSizeMake(MAXFLOAT, 30)]

//导航控制器坐标
#define CoordinateAboutNav  CGRectMake(0, 0, self.view.frame.size.width, H_i6real(64))

//NSUserDefaults
#define UserDefaults [NSUserDefaults standardUserDefaults]

//视频存储路径
#define KVideoUrlPath   \
[[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0] stringByAppendingPathComponent:@"VideoURL"]

//上线时间用的IP
//#define TestIP    @"http://101.201.74.107/home/"
//上线时间用的IP（域名）
//#define TestIP    @"http://daosay.guidetalker.com/home/"

//测试时间用的IP
//#define TestIP    @"http://112.126.64.137/home/"
//#define TestIP2   @"http://112.126.64.137/home/Instant/"
//测试时间用的IP（域名）
#define TestIP    @"https://say.guidetalker.com/home/"

//字体大小
#define TextFont [UIFont systemFontOfSize:12]
#define TextFontWithSize(SIZE) [UIFont fontWithName:@"MicrosoftYaHei" size:SIZE]  
//设置字体大小
#define SetTextFont(font) [UIFont systemFontOfSize:font]

//alertview 无代理
#define SHOW_ALERT(msg) UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示" message:msg delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil, nil];\
[alert show];

//alertview 有代理
#define SHOW_ALERTWITHDELEGATE(msg) UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"提示" message:msg delegate:self cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];\
[alert show];

/**
 *define:iOS 7.0的版本判断
 */
#define iOS7_OR_LATER [UIDevice currentDevice].systemVersion.floatValue >= 7.0

/**
 *define:iOS 8.0的版本判断
 */
#define iOS8_OR_LATER [UIDevice currentDevice].systemVersion.floatValue >= 8.0

//跳转到登录界面
#define GOTO_LOGINVC  LoginVC *loginVC = [[LoginVC alloc]init];\
UINavigationController *nav = [[UINavigationController alloc]initWithRootViewController:loginVC];\
[nav setNavigationBarHidden:YES];\
[self presentViewController:nav animated:YES completion:nil]

//设置图片
#define  SetImg(imgName) [UIImage imageNamed:imgName]

#define PhoneNum        @"phoneNumber"
#define HeadUrlStr      @"headImgUrl"
#define TOKEN           @"token"
#define NICKNAME        @"nickName"
#define SessionID       @"session"
#define USER_ID         @"userid"
#define USER_LOCATION   @"location"

//一段文字改变指定的字符颜色
#define ChangeTextColor(Text,Color,Range)  NSMutableAttributedString *str = [[NSMutableAttributedString alloc]initWithString:Text];\
[str addAttribute:NSForegroundColorAttributeName value:Color range:Range];//字符串显示不同的颜色

//HUD
#define kHUDNormal(msg) {MBProgressHUD *hud=[MBProgressHUD showHUDAddedTo:[[UIApplication sharedApplication].delegate window] animated:NO];\
hud.mode = MBProgressHUDModeText;\
hud.minShowTime=1.5;\
hud.detailsLabel.text= msg;\
hud.detailsLabel.font = [UIFont systemFontOfSize:15];\
[hud hideAnimated:YES afterDelay:0.5];\
}

//masonry 适配
#define MASONRY_T_L_R_H(cview,topView,leftView,rightView,Top,Left,Right,Height)  [cview mas_makeConstraints:^(MASConstraintMaker *make) {\
                                                                                    make.top.equalTo(topView).with.offset(H_i6real(Top));\
                                                                                    make.left.equalTo(leftView).with.offset(W_i6real(Left));\
                                                                                    make.right.equalTo(rightView).with.offset(W_i6real(-Right));\
                                                                                    make.height.mas_offset(H_i6real(Height));\
                                                                                    }]

#define MASONRY_T_L_S(cview,topView,leftView,Top,Left,Width,Height)   [cview mas_makeConstraints:^(MASConstraintMaker *make) {\
                                                            make.top.equalTo(topView).with.offset(H_i6real(Top));\
                                                            make.left.equalTo(leftView).with.offset(W_i6real(Left));\
                                                            make.size.mas_offset(CGSizeMake(W_i6real(Width), H_i6real(Height)));\
                                                            }]
#define MASONRY_T_R_S(cview,topView,rightView,Top,Right,Width,Height)  [cview mas_makeConstraints:^(MASConstraintMaker *make) {\
                                                                    make.top.equalTo(topView).with.offset(H_i6real(Top));\
                                                                    make.right.equalTo(rightView).with.offset(W_i6real(-Right));\
                                                                    make.size.mas_offset(CGSizeMake(W_i6real(Width), H_i6real(Height)));\
                                                                    }]


#define  MASONRY_B_L_S(cview,bottomView,leftView,Bottom,Left,Width,Height) [cview mas_makeConstraints:^(MASConstraintMaker *make) {\
                                                                            make.left.equalTo(leftView).with.offset(W_i6real(Left));\
                                                                            make.bottom.equalTo(bottomView).with.offset(-H_i6real(Bottom));\
                                                                            make.size.mas_offset(CGSizeMake(W_i6real(Width), H_i6real(Height)));\
                                                                            }]

#define  MASONRY_B_R_S(cview,bottomView,rightView,Bottom,Right,Width,Height) [cview mas_makeConstraints:^(MASConstraintMaker *make) {\
                                                                            make.right.equalTo(rightView).with.offset(-W_i6real(Right));\
                                                                            make.bottom.equalTo(bottomView).with.offset(-H_i6real(Bottom));\
                                                                            make.size.mas_offset(CGSizeMake(W_i6real(Width), H_i6real(Height)));\
                                                                            }]
#define   MASONRY_B_CX_S(cview,centerXView,bottomView,Bottom,Width,Height) [cview mas_makeConstraints:^(MASConstraintMaker *make) {\
                                                                                make.bottom.equalTo(bottomView).with.offset(-H_i6real(Bottom));\
                                                                                make.centerX.equalTo(centerXView);\
                                                                                make.size.mas_offset(CGSizeMake(W_i6real(Width), H_i6real(Height)));\
                                                                                }]
#define MASONRY_B_L_R_H(cview,bottomView,leftView,rightView,Bottom,Left,Right,Height) [cview mas_makeConstraints:^(MASConstraintMaker *make) {\
                                                                                        make.bottom.equalTo(bottomView).with.offset(-H_i6real(Bottom));\
                                                                                        make.left.equalTo(leftView).with.offset(W_i6real(Left));\
                                                                                        make.right.equalTo(rightView).with.offset(W_i6real(-Right));\
                                                                                        make.height.mas_offset(H_i6real(Height));\
                                                                                        }];
#define   MASONRY_T_CX_S(cview,centerXView,TopView,Top,Width,Height) [cview mas_makeConstraints:^(MASConstraintMaker *make) {\
                                                                            make.top.equalTo(TopView).with.offset(H_i6real(Top));\
                                                                            make.centerX.equalTo(centerXView);\
                                                                            make.size.mas_offset(CGSizeMake(W_i6real(Width), H_i6real(Height)));\
                                                                            }]

#define  MASONRY_T_L_B_R(cview,topView,leftView,bottomView,rightView,Top,Left,Bottom,Right) [cview mas_makeConstraints:^(MASConstraintMaker *make) {\
                                                                                            make.top.equalTo(topView).with.offset(H_i6real(Top));\
                                                                                            make.left.equalTo(leftView).with.offset(W_i6real(Left));\
                                                                                            make.bottom.equalTo(bottomView).with.offset(-H_i6real(Bottom));\
                                                                                            make.right.equalTo(rightView).with.offset(-W_i6real(Right));\
                                                                                            }];
#define MASONRY_T_L_B_W(cview,topView,leftView,bottomView,Top,Left,Bottom,Width)  [cview mas_makeConstraints:^(MASConstraintMaker *make) {\
                                                                                            make.top.equalTo(topView).with.offset(H_i6real(Top));\
                                                                                            make.left.equalTo(leftView).with.offset(Left);\
                                                                                            make.bottom.equalTo(bottomView).with.offset(-H_i6real(Bottom));\
                                                                                            make.width.mas_offset(W_i6real(Width));\
                                                                                            }];
#define MASONRY_T_B_R_W(cview,topView,bottomView,rightView,Top,Bottom,Right,Width)  [cview mas_makeConstraints:^(MASConstraintMaker *make) {\
                                                                                    make.top.equalTo(topView).with.offset(H_i6real(Top));\
                                                                                    make.bottom.equalTo(bottomView).with.offset(-H_i6real(Bottom));\
                                                                                    make.right.equalTo(rightView).with.offset(-W_i6real(Right));\
                                                                                    make.width.mas_offset(W_i6real(Width));\
                                                                                    }];

//判断字符串是否为空
#define STR_IS_NULL(Str)   [Str isKindOfClass:[NSNull class]]

//重写nslog方法
#ifdef DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\n %s:%d   %s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String],__LINE__, [[[NSString alloc] initWithData:[[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] dataUsingEncoding:NSUTF8StringEncoding] encoding:NSNonLossyASCIIStringEncoding] UTF8String]);
#else
#define NSLog(...)
#endif


#define IS_IOS_8  (([[[[UIDevice currentDevice].systemVersion componentsSeparatedByString:@"."] objectAtIndex:0] intValue] <= 8) ? YES : NO)















