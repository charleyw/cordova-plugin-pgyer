#import "PgyerPlugin.h"
#import <PgySDK/PgyManager.h>

@implementation PgyerPlugin

- (void)init:(CDVInvokedUrlCommand*)command
{
	NSString *appID = [[NSBundle mainBundle] objectForInfoDictionaryKey:@"PgyerAppID"];
	[[PgyManager sharedPgyManager] startManagerWithAppId:appID];
	[[PgyManager sharedPgyManager] checkUpdate];
}

@end