//
//  PAPPhotoTimelineViewController.h
//  Anypic
//
//  Created by Héctor Ramos on 5/3/12.
//  Copyright (c) 2012 Parse. All rights reserved.
//

#import "PAPPhotoHeaderView.h"

@interface PAPPhotoTimelineViewController : PFQueryTableViewController <PAPPhotoHeaderViewDelegate>

- (PAPPhotoHeaderView *)dequeueReusableSectionHeaderView;

@end
