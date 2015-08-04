Cordova 蒲公英自动更新插件
======
[http://www.pgyer.com/doc/view/sdk_ios_guide](http://www.pgyer.com/doc/view/sdk_ios_guide)  
[http://www.pgyer.com/doc/view/sdk_android_guide](http://www.pgyer.com/doc/view/sdk_android_guide)  

## 支持的系统

* iOS
* Android(反馈功能仅支持 Android 版本)

## 安装

	cordova plugin add https://github.com/charleyw/cordova-plugin-pgyer.git --variable ANDROID_APP_ID=[你的Android App ID] --variable IOS_APP_ID=[你的iOS App ID]

两个参数都必须同时提供才能正确安装。			  

## 使用

弹出反馈窗口
pgyer.popup()

## TODO

* ~~使用变量设置APP_ID~~
