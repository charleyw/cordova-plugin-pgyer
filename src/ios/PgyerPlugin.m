#import "PgyerPlugin.h"
#import <PgySDK/PgyManager.h>

@implementation PgyerPlugin

- (void)init:(CDVInvokedUrlCommand*)command
{
	[[PgyManager sharedPgyManager] startManagerWithAppId:@"91a10d133200735c9fb7097e0d2b48c5"];
	[[PgyManager sharedPgyManager] checkUpdate];
}

@end