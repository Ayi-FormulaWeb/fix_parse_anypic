//
//  PAPLogInViewController.m
//  Anypic
//
//  Created by Mattieu Gamache-Asselin on 5/17/12.
//  Copyright (c) 2012 Parse. All rights reserved.
//

#import "PAPLogInViewController.h"

@implementation PAPLogInViewController

- (void)viewDidLoad {
    self.view.backgroundColor = [UIColor colorWithPatternImage:[UIImage imageNamed:@"Default.png"]];
    
    NSString *text = @"Sign up and start sharing your story with your friends.";
    CGSize textSize = [text sizeWithFont:[UIFont fontWithName:@"HelveticaNeue-Medium" size:18.0f] constrainedToSize:CGSizeMake( 255.0f, CGFLOAT_MAX) lineBreakMode:UILineBreakModeWordWrap];
    UILabel *textLabel = [[UILabel alloc] initWithFrame:CGRectMake( ([UIScreen mainScreen].bounds.size.width - textSize.width)/2.0f, 160.0f, textSize.width, textSize.height)];
    [textLabel setFont:[UIFont fontWithName:@"HelveticaNeue-Medium" size:18.0f]];
    [textLabel setLineBreakMode:UILineBreakModeWordWrap];
    [textLabel setNumberOfLines:0];
    [textLabel setText:text];
    [textLabel setTextColor:[UIColor colorWithRed:214.0f/255.0f green:206.0f/255.0f blue:191.0f/255.0f alpha:1.0f]];
    [textLabel setBackgroundColor:[UIColor clearColor]];
    [textLabel setTextAlignment:UITextAlignmentCenter];

    [self.logInView setLogo:nil];
    [self.logInView addSubview:textLabel]; 
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {
    return toInterfaceOrientation == UIInterfaceOrientationPortrait;
}

@end
