//
//  PAPPhotoHeaderView.h
//  Anypic
//
//  Created by Héctor Ramos on 5/15/12.
//  Copyright (c) 2012 Parse. All rights reserved.
//

typedef enum {
    PAPPhotoHeaderButtonsNone = 0,
    PAPPhotoHeaderButtonsLike = 1 << 0,
    PAPPhotoHeaderButtonsComment = 1 << 1,
    PAPPhotoHeaderButtonsUser = 1 << 2,
    
    PAPPhotoHeaderButtonsDefault = PAPPhotoHeaderButtonsLike | PAPPhotoHeaderButtonsComment | PAPPhotoHeaderButtonsUser
} PAPPhotoHeaderButtons;

@protocol PAPPhotoHeaderViewDelegate;

@interface PAPPhotoHeaderView : UIView

/*! @name Creating Photo Header View */
/*!
 Initializes the view with the specified interaction elements.
 @param buttons A bitmask specifying the interaction elements which are enabled in the view
 初始化與指定的互動元素。
 @param 按鈕指定是啟用的互動元素在視圖中的位掩碼
 */
- (id)initWithFrame:(CGRect)frame buttons:(PAPPhotoHeaderButtons)otherButtons;

/// The photo associated with this view
/// 與該視圖關聯的照片
@property (nonatomic,strong) PFObject *photo;

/// The bitmask which specifies the enabled interaction elements in the view
/// 指定功能的互動元素在視圖中的位掩碼
@property (nonatomic, readonly, assign) PAPPhotoHeaderButtons buttons;

/*! @name Accessing Interaction Elements 
    @name 訪問的互動元素
 */

/// The Like Photo button
/// 喜歡照片按鈕
@property (nonatomic,readonly) UIButton *likeButton;

/// The Comment On Photo button
/// 對照片留言按鈕
@property (nonatomic,readonly) UIButton *commentButton;

/*! @name Delegate */
@property (nonatomic,weak) id <PAPPhotoHeaderViewDelegate> delegate;

/*! @name Modifying Interaction Elements Status 
    @name 隨著互動元件狀態改變
 */

/*!
 Configures the Like Button to match the given like status.
 @param liked a BOOL indicating if the associated photo is liked by the user
 */
- (void)setLikeStatus:(BOOL)liked;

/*!
 Enable the like button to start receiving actions.
 @param enable a BOOL indicating if the like button should be enabled.
 */
- (void)shouldEnableLikeButton:(BOOL)enable;

@end


/*!
 The protocol defines methods a delegate of a PAPPhotoHeaderView should implement.
 All methods of the protocol are optional.
 該協議定義了一個委託的PAPPhotoHeaderView應該實施的方法。
  該協議的所有方法都是可選的。
 */
@protocol PAPPhotoHeaderViewDelegate <NSObject>
@optional

/*!
 Sent to the delegate when the user button is tapped
 @param user the PFUser associated with this button
 當用戶點擊按鈕，發送給委託
  @param user的PFUser的與此按鈕相關聯
 */
- (void)photoHeaderView:(PAPPhotoHeaderView *)photoHeaderView didTapUserButton:(UIButton *)button user:(PFUser *)user;

/*!
 Sent to the delegate when the like photo button is tapped
 @param photo the PFObject for the photo that is being liked or disliked
 */
- (void)photoHeaderView:(PAPPhotoHeaderView *)photoHeaderView didTapLikePhotoButton:(UIButton *)button photo:(PFObject *)photo;

/*!
 Sent to the delegate when the comment on photo button is tapped
 @param photo the PFObject for the photo that will be commented on
 */
- (void)photoHeaderView:(PAPPhotoHeaderView *)photoHeaderView didTapCommentOnPhotoButton:(UIButton *)button photo:(PFObject *)photo;

@end