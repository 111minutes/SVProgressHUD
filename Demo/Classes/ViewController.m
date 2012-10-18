//
//  SVProgressHUDViewController.m
//  SVProgressHUD
//
//  Created by Sam Vermette on 27.03.11.
//  Copyright 2011 Sam Vermette. All rights reserved.
//

#import "ViewController.h"
#import "SVProgressHUD.h"

@implementation ViewController

- (id)initWithCoder:(NSCoder *)aDecoder {
    
    self = [super initWithCoder:aDecoder];
    if (self) {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(hudTapped:)
                                                     name:SVProgressHUDTappedNotification
                                                   object:nil];
    }
    return self;
}


- (void)dealloc {
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)toInterfaceOrientation {
    return YES;
}

#pragma mark -
#pragma mark - Show Methods Sample

- (void)show {
	[SVProgressHUD show];
}

- (void)showWithStatus {
    [SVProgressHUD showSuccessWithStatus:@"bla" duration:10];
}

- (void)showWithHidingOnTap {
    [SVProgressHUD setShouldHideByTap:YES];
    [SVProgressHUD setShouldRecieveTapInHudView:YES];
    [SVProgressHUD show];
}

#pragma mark -
#pragma mark - Dismiss Methods Sample

- (void)dismiss {
	[SVProgressHUD dismiss];
}

- (void)dismissSuccess {
	[SVProgressHUD dismissWithSuccess:@"Great Success!"];
}

- (void)dismissError {
	[SVProgressHUD dismissWithError:@"Failed with Error"];
}

#pragma mark -
#pragma mark - Notifications

- (void)hudTapped:(NSNotification *)aNotification {
    NSLog(@"hud tapped -- %@", aNotification);
}

@end
