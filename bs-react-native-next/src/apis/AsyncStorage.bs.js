'use strict';

var ReactNative = require("react-native");
var PromiseUtils$ReactNative = require("../utils/PromiseUtils.bs.js");

function getItem(key) {
  return ReactNative.AsyncStorage.getItem(key).then(PromiseUtils$ReactNative.nullableToOption);
}

function getAllKeys(param) {
  return ReactNative.AsyncStorage.getAllKeys().then(PromiseUtils$ReactNative.nullableToOption);
}

function multiGet(keys) {
  return ReactNative.AsyncStorage.multiGet(keys).then(PromiseUtils$ReactNative.nullableToOption);
}

exports.getItem = getItem;
exports.getAllKeys = getAllKeys;
exports.multiGet = multiGet;
/* react-native Not a pure module */
