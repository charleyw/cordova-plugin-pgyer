/*global cordova, module*/

module.exports = {
    init: function (name, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "Pgyer", "init", [name]);
    },
    popup: function (name, successCallback, errorCallback) {
    	cordova.exec(successCallback, errorCallback, "Pgyer", "popup", [name]);
    }
};
