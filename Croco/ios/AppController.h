//
//  CrocoAppController.h
//  Croco
//
//  Created by admin on 03.06.12.
//  Copyright __MyCompanyName__ 2012. All rights reserved.
//


@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController	*viewController;
}

@end

