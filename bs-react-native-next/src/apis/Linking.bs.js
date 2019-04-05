'use strict';

var ReactNative = require("react-native");
var PromiseUtils$ReactNative = require("../utils/PromiseUtils.bs.js");

function getInitialURL(param) {
  return ReactNative.Linking.getInitialURL().then(PromiseUtils$ReactNative.nullableToOption);
}

exports.getInitialURL = getInitialURL;
/* react-native Not a pure module */
