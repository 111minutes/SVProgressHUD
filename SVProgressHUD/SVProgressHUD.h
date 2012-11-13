//
//  SVProgressHUD.h
//
//  Created by Sam Vermette on 27.03.11.
//  Copyright 2011 Sam Vermette. All rights reserved.
//
//  https://github.com/samvermette/SVProgressHUD
//

#import <UIKit/UIKit.h>
#import <AvailabilityMacros.h>

#define SVProgressHUDTappedNotification @"SVProgressHUDTappedNotification"

enum {
    SVProgressHUDMaskTypeNone = 1, // allow user interactions while HUD is displayed
    SVProgressHUDMaskTypeClear, // don't allow
    SVProgressHUDMaskTypeBlack, // don't allow and dim the UI in the back of the HUD
    SVProgressHUDMaskTypeGradient // don't allow and dim the UI with a a-la-alert-view bg gradient
};

typedef NSUInteger SVProgressHUDMaskType;

@interface SVProgressHUD : UIView

@property (nonatomic, strong, readonly) UIView *hudView;
@property (nonatomic, strong, readonly) UILabel *stringLabel;
@property (nonatomic, strong, readonly) UIImageView *imageView;
@property (nonatomic, strong, readonly) UIActivityIndicatorView *spinnerView;

+ (void)show;
+ (void)showWithMaskType:(SVProgressHUDMaskType)maskType;

+ (void)showWithStatus:(NSString *)status;
+ (void)showWithStatus:(NSString *)status maskType:(SVProgressHUDMaskType)maskType;

+ (void)setStatus:(NSString *)string; // change the HUD loading status while it's showing

// stops the activity indicator, shows a glyph + status, and dismisses HUD 2s later
+ (void)showSuccessWithStatus:(NSString *)string;
+ (void)showErrorWithStatus:(NSString *)string;
+ (void)showImage:(UIImage *)image status:(NSString *)status; // use 28x28 white pngs
+ (void)showImage:(UIImage *)image status:(NSString *)status duration:(NSTimeInterval)duration;

+ (void)dismiss;

+ (BOOL)isVisible;

+ (void)showSuccessWithStatus:(NSString *)string duration:(NSTimeInterval)duration;
+ (void)showErrorWithStatus:(NSString *)string duration:(NSTimeInterval)duration;

+ (void)setShouldHideByTap:(BOOL)shouldHide;
+ (void)setShouldRecieveTapInHudView:(BOOL)shouldRecieveTapInHudView;

// deprecated June 9th; custom durations encourages uncessarily long status strings (inappropriate, use UIAlertView instead)
// deprecated June 9th; use the showWithSuccess/Error methods instead
+ (void)dismissWithSuccess:(NSString*)successString DEPRECATED_ATTRIBUTE; 
+ (void)dismissWithSuccess:(NSString*)successString afterDelay:(NSTimeInterval)seconds DEPRECATED_ATTRIBUTE;
+ (void)dismissWithError:(NSString*)errorString DEPRECATED_ATTRIBUTE;
+ (void)dismissWithError:(NSString*)errorString afterDelay:(NSTimeInterval)seconds DEPRECATED_ATTRIBUTE;

@end
