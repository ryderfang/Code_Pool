//  weibo: http://weibo.com/xiaoqing28
//  blog:  http://www.alonemonkey.com
//
//  RevAwemeDylib.m
//  RevAwemeDylib
//
//  Created by Ryder Fang on 2021/8/3.
//  Copyright (c) 2021 ___ORGANIZATIONNAME___. All rights reserved.
//

#import "RevAwemeDylib.h"
#import <CaptainHook/CaptainHook.h>
#import <UIKit/UIKit.h>
#import <Cycript/Cycript.h>
#import <MDCycriptManager.h>
#import "MonkeyDebugView.h"

CHConstructor{
    printf(INSERT_SUCCESS_WELCOME);
    
    [[NSNotificationCenter defaultCenter] addObserverForName:UIApplicationDidFinishLaunchingNotification object:nil queue:[NSOperationQueue mainQueue] usingBlock:^(NSNotification * _Nonnull note) {
        
#ifndef __OPTIMIZE__
        CYListenServer(6666);

        MD_CycriptManager* manager = [MD_CycriptManager sharedInstance];
        [manager loadCycript:NO];

        NSError* error;
        NSString* result = [manager evaluateCycript:@"UIApp" error:&error];
        NSLog(@"result: %@", result);
        if(error.code != 0){
            NSLog(@"error: %@", error.localizedDescription);
        }
#endif
        
    }];
}


CHDeclareClass(CustomViewController)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wstrict-prototypes"

//add new method
CHDeclareMethod1(void, CustomViewController, newMethod, NSString*, output){
    NSLog(@"This is a new method : %@", output);
}

#pragma clang diagnostic pop

CHOptimizedClassMethod0(self, void, CustomViewController, classMethod){
    NSLog(@"hook class method");
    CHSuper0(CustomViewController, classMethod);
}

CHOptimizedMethod0(self, NSString*, CustomViewController, getMyName){
    //get origin value
    NSString* originName = CHSuper(0, CustomViewController, getMyName);
    
    NSLog(@"origin name is:%@",originName);
    
    //get property
    NSString* password = CHIvar(self,_password,__strong NSString*);
    
    NSLog(@"password is %@",password);
    
    [self newMethod:@"output"];
    
    //set new property
    self.newProperty = @"newProperty";
    
    NSLog(@"newProperty : %@", self.newProperty);
    
    //change the value
    return @"Ryder Fang";
    
}

//add new property
CHPropertyRetainNonatomic(CustomViewController, NSString*, newProperty, setNewProperty);

CHConstructor{
    CHLoadLateClass(CustomViewController);
    CHClassHook0(CustomViewController, getMyName);
    CHClassHook0(CustomViewController, classMethod);
    
    CHHook0(CustomViewController, newProperty);
    CHHook1(CustomViewController, setNewProperty);
}

// 抖音首页
@interface AWERecorderViewController

- (void)viewDidAppear:(BOOL)animated;
- (UIView *)view;
- (void)checkAddDebugAlbumPhotosButton;

@end

CHDeclareClass(AWERecorderViewController)
CHOptimizedMethod(1, self, void, AWERecorderViewController, viewDidAppear, BOOL, arg1){
    NSLog(@"AWERecorderViewController viewDidAppear");
//    [self.view addSubview:[MonkeyDebugView sharedView]];
#if ENABLE_PRINT_GL_DRAW_IMAGES
//    [self checkAddDebugAlbumPhotosButton];
#endif
    CHSuper(1, AWERecorderViewController, viewDidAppear, arg1);
}
CHConstructor{
    CHLoadLateClass(AWERecorderViewController);
    CHClassHook(1, AWERecorderViewController, viewDidAppear);
}

@interface IESEffectModel

@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;

@end
// 滤镜面板
@interface AWETabFilterViewController : UIViewController
- (void)onEffectListUpdated:(id)arg1;
- (void)applyFilter:(IESEffectModel *)arg1 fromBox:(BOOL)arg2;
@end

CHDeclareClass(AWETabFilterViewController)
CHOptimizedMethod(1, self, void, AWETabFilterViewController, onEffectListUpdated, id, arg1){
    NSLog(@"AWETabFilterViewController show");
    CHSuper(1, AWETabFilterViewController, onEffectListUpdated, arg1);
}

CHOptimizedMethod(2, self, void, AWETabFilterViewController, applyFilter, IESEffectModel*, arg1, fromBox, BOOL, arg2) {
    NSLog(@"AWETabFilterViewController apply: %@, arg2: %d", [arg1 debugDescription], arg2);
    CHSuper(2, AWETabFilterViewController, applyFilter, arg1, fromBox, arg2);
}

CHConstructor{
    CHLoadLateClass(AWETabFilterViewController);
    CHClassHook(1, AWETabFilterViewController, onEffectListUpdated);
    CHClassHook(2, AWETabFilterViewController, applyFilter, fromBox);
}

// AWEComposerBeautyEffectWrapper *
// AWEComposerBeautyEffectCategoryWrapper *
@interface AWEComposerBeautyEffectViewModel : NSObject
- (void)updateSelectedEffect:(id)arg1 forCategory:(id)arg2 gender:(long long)arg3;
- (void)updateSelectedEffect:(id)arg1 forCategory:(id)arg2;
@end

CHDeclareClass(AWEComposerBeautyEffectViewModel)
CHOptimizedMethod(2, self, void, AWEComposerBeautyEffectViewModel, updateSelectedEffect, id, arg1, forCategory, id, arg2) {
    NSLog(@"AWEComposerBeautyEffectViewModel updateSelectedEffect");
    CHSuper(2, AWEComposerBeautyEffectViewModel, updateSelectedEffect, arg1, forCategory, arg2);
}

CHConstructor{
    CHLoadLateClass(AWEComposerBeautyEffectViewModel);
    CHClassHook(2, AWEComposerBeautyEffectViewModel, updateSelectedEffect, forCategory);
}
