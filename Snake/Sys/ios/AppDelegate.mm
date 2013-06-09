//
//  AppDelegate.m
//  Snake
//
//  Created by Katekov Anton on 10/16/12.
//
//

#import "AppDelegate.h"
#include "SEngine.h"
#include "SGame.h"
#include "cocos2d.h"
#import <QuartzCore/QuartzCore.h>

@interface AppDelegate ()

- (void)frameCallback:(CADisplayLink *)link;

@end

@implementation AppDelegate

- (void)initEnviroment {
    
    CADisplayLink *link = [CADisplayLink displayLinkWithTarget:self selector:@selector(frameCallback:)];
    [link addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    
    lastTime = [[NSDate dateWithTimeIntervalSinceNow:0] timeIntervalSince1970];
    engine->Init();
    game->Init();
}

- (void)frameCallback:(CADisplayLink *)link {
    NSTimeInterval time = [[NSDate dateWithTimeIntervalSinceNow:0] timeIntervalSince1970];
    NSTimeInterval delta = time - lastTime;
    lastTime = time;
    engine->RunLoop(delta);
}


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    srand([[NSDate date] timeIntervalSince1970]);
    [self initEnviroment];
    
    return YES;
}

int main(int argc, char *argv[])
{
    @autoreleasepool {
        return UIApplicationMain(argc, argv, nil, NSStringFromClass([AppDelegate class]));
    }
}



@end
