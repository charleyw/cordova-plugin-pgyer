/*global cordova, module*/

module.exports = {
    init: function (name, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "Pgyer", "init", [name]);
    },
    showFeedBackBox: function (name, successCallback, errorCallback) {
    	cordova.exec(successCallback, errorCallback, "Pgyer", "showFeedBackBox", [name]);
    }
};
