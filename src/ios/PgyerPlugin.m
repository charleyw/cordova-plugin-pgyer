#import "PgyerPlugin.h"
#import <PgySDK/PgyManager.h>

@implementation PgyerPlugin

- (void)pluginInitialize
{
    NSString *appID = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"PgyerAppID"];
    [[PgyManager sharedPgyManager] startManagerWithAppId:appID];
    [[PgyManager sharedPgyManager] checkUpdate];
    NSLog(@"Pgyer update checke registered");
}
@end