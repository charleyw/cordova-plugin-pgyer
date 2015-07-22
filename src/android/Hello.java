package com.example.plugin;

import org.apache.cordova.*;
import org.json.JSONArray;
import org.json.JSONException;

import com.pgyersdk.update.PgyUpdateManager;

public class Hello extends CordovaPlugin {

    @Override
    public boolean execute(String action, JSONArray data, CallbackContext callbackContext) throws JSONException {
        if (action.equals("init")) {
            cordova.getThreadPool().execute(new Runnable() {
                public void run() {
                    PgyUpdateManager.register(cordova.getActivity(), "91a10d133200735c9fb7097e0d2b48c5");
                }
            });
            return true;
        } else {
            return false;
        }
    }
}
