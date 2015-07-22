/*global cordova, module*/

module.exports = {
    init: function (name, successCallback, errorCallback) {
        cordova.exec(successCallback, errorCallback, "Hello", "init", [name]);
    }
};
