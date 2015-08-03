#import "PgyerPlugin.h"
#import <PgySDK/PgyManager.h>

@implementation PgyerPlugin

- (void)pluginInitialize
{
    CDVViewController *viewController = (CDVViewController *)self.viewController;
    NSString *appID = [viewController.settings objectForKey:@"appid"];

    [[PgyManager sharedPgyManager] startManagerWithAppId:appID];
    [[PgyManager sharedPgyManager] checkUpdate];
    NSLog(@"Pgyer update checke registered");
}
@end
