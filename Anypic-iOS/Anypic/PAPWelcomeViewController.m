//
//  PAPWelcomeViewController.m
//  Anypic
//
//  Created by Héctor Ramos on 5/10/12.
//  Copyright (c) 2012 Parse. All rights reserved.
//

#import "PAPWelcomeViewController.h"
#import "AppDelegate.h"

@implementation PAPWelcomeViewController

#pragma mark - UIViewController
- (void)loadView {
    UIImageView *backgroundImageView = [[UIImageView alloc] initWithFrame:[[UIScreen mainScreen] applicationFrame]];
    [backgroundImageView setImage:[UIImage imageNamed:@"Default.png"]];
    self.view = backgroundImageView;
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    // If not logged in, present login view controller
    if (![PFUser currentUser]) {
        [(AppDelegate*)[[UIApplication sharedApplication] delegate] presentLoginViewControllerAnimated:NO];
        return;
    }
    // Present Anypic UI
    [(AppDelegate*)[[UIApplication sharedApplication] delegate] presentTabBarController];
    
    // Refresh current user with server side data -- checks if user is still valid and so on
    [[PFUser currentUser] refreshInBackgroundWithTarget:self selector:@selector(refreshCurrentUserCallbackWithResult:error:)];
}


#pragma mark - ()

- (void)refreshCurrentUserCallbackWithResult:(PFObject *)refreshedObject error:(NSError *)error {
    // A kPFErrorObjectNotFound error on currentUser refresh signals a deleted user
    if (error && error.code == kPFErrorObjectNotFound) {
        NSLog(@"User does not exist.");
        [(AppDelegate*)[[UIApplication sharedApplication] delegate] logOut];
        return;
    }
    
    [PFFacebookUtils extendAccessTokenIfNeededForUser:[PFUser currentUser] block:^(BOOL succeeded, NSError *error) {
        // Check if user is missing a Facebook ID
        if ([PAPUtility userHasValidFacebookData:[PFUser currentUser]]) {
            // User has Facebook ID.

            // refresh Facebook friends on each launch
            [[PFFacebookUtils facebook] requestWithGraphPath:@"me/friends" andDelegate:(AppDelegate*)[[UIApplication sharedApplication] delegate]];
            
        } else {
            NSLog(@"User missing Facebook ID"); 
            [[PFFacebookUtils facebook] requestWithGraphPath:@"me/?fields=name,picture,email" andDelegate:(AppDelegate*)[[UIApplication sharedApplication] delegate]];
        }
    }];
    

}

@end
