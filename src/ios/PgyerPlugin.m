#import "PgyerPlugin.h"
#import <PgyUpdate/PgyUpdateManager.h>

@implementation PgyerPlugin

- (void)pluginInitialize
{
    CDVViewController *viewController = (CDVViewController *)self.viewController;
    NSString *appID = [viewController.settings objectForKey:@"appid"];

    [[PgyUpdateManager sharedPgyManager] startManagerWithAppId:appID];
	[[PgyUpdateManager sharedPgyManager] checkUpdate];
    NSLog(@"Pgyer update checke registered");
}
@end
