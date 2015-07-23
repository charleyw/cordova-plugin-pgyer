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
        String androidAppID = "";
        try {
            ApplicationInfo applicationInfo = cordova.getActivity().getPackageManager().getApplicationInfo(cordova.getActivity().getPackageName(), PackageManager.GET_META_DATA);
            Bundle bundle = applicationInfo.metaData;
            androidAppID = bundle.getString("PGYER_APP_ID");
        } catch (NameNotFoundException e) {
            Log.e(TAG, "Failed to load meta-data, NameNotFound: " + e.getMessage());
        } catch (NullPointerException e) {
            Log.e(TAG, "Failed to load meta-data, NullPointer: " + e.getMessage());
        }

        if(androidAppID.equals("")){
            return;
        }

        final String appID = androidAppID;
        cordova.getThreadPool().execute(new Runnable() {
            public void run() {
                PgyUpdateManager.register(cordova.getActivity(), appID);
                Log.i(TAG, "Pgyer update check registered, app ID: " + appID);
            }
        });
    }
}