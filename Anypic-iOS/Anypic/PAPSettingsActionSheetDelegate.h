//
//  PAPSettingsActionSheetDelegate.h
//  Anypic
//
//  Created by Mattieu Gamache-Asselin on 5/9/12.
//  Copyright (c) 2012 Parse. All rights reserved.
//

@interface PAPSettingsActionSheetDelegate : NSObject <UIActionSheetDelegate>

// Navigation controller of calling view controller
@property (nonatomic, strong) UINavigationController *navController;

- (id)initWithNavigationController:(UINavigationController *)navigationController;

@end
