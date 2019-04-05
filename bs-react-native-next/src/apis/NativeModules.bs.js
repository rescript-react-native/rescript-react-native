'use strict';

var ReactNative = require("react-native");

function get(name) {
  return ReactNative.NativeModules[name];
}

exports.get = get;
/* react-native Not a pure module */
