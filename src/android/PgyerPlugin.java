package wang.imchao.plugin;

import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageManager.NameNotFoundException;
import android.os.Bundle;
import android.util.Log;

import com.pgyersdk.update.PgyUpdateManager;

import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CordovaWebView;

public class PgyerPlugin extends CordovaPlugin {
    private static String TAG = "PgyerPlugin";

    @Override
    public void initialize(final CordovaInterface cordova, CordovaWebView webView) {
        super.initialize(cordova, webView);
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                PgyUpdateManager.register(cordova.getActivity());
                Log.i(TAG, "Pgyer update check registered");
            }
        });
    }
}
