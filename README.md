Cordova 蒲公英自动更新插件
======
[http://www.pgyer.com/doc/view/sdk_ios_guide](http://www.pgyer.com/doc/view/sdk_ios_guide)  
[http://www.pgyer.com/doc/view/sdk_android_guide](http://www.pgyer.com/doc/view/sdk_android_guide)  

## 支持的系统

* iOS
* Android

## 手动安装
1. 安装插件  

		cordova plugin add https://github.com/charleyw/cordova-plugin-pgyer.git
		
2. iOS  
修改下面的文件，将第8行的APP_ID替换成你自己的APP_ID。  
_platforms/ios/**YourProjectName**/Plugins/wang.imchao.plugin.pgyer/PgyerPlugin/PgyerPlugin.m_

		[[PgyManager sharedPgyManager] startManagerWithAppId:@"APP_ID"];
3. Android  
修改下面的文件，将第16行的APP_ID替换成你自己的APP_ID。  
_platforms/android/src/wang/imchao/plugin/PgyerPlugin.java_

		PgyUpdateManager.register(cordova.getActivity(), "APP_ID");
	  
## TODO

* 使用变量设置APP_ID