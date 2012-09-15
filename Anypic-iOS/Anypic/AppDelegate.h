//
//  AppDelegate.h
//  Anypic
//
//  Created by Héctor Ramos on 5/04/12.
//  Copyright (c) 2012 Parse. All rights reserved.
//

#import "PAPTabBarController.h"

@interface AppDelegate : UIResponder <UIApplicationDelegate, PFLogInViewControllerDelegate, PF_FBRequestDelegate, NSURLConnectionDataDelegate, UITabBarControllerDelegate>

@property (nonatomic, strong) UIWindow *window;

@property (nonatomic, strong) PAPTabBarController *tabBarController;
@property (nonatomic, strong) UINavigationController *navController;

@property (nonatomic, readonly) int networkStatus;

- (BOOL)isParseReachable;

- (void)presentLoginViewController;
- (void)presentLoginViewControllerAnimated:(BOOL)animated;
- (void)presentTabBarController;

- (void)logOut;


@end
