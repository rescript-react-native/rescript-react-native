

import * as ReactNative from "react-native";
import * as PromiseUtils$ReactNative from "../utils/PromiseUtils.bs.js";

function getItem(key) {
  return ReactNative.AsyncStorage.getItem(key).then(PromiseUtils$ReactNative.nullableToOption);
}

function getAllKeys(param) {
  return ReactNative.AsyncStorage.getAllKeys().then(PromiseUtils$ReactNative.nullableToOption);
}

function multiGet(keys) {
  return ReactNative.AsyncStorage.multiGet(keys).then(PromiseUtils$ReactNative.nullableToOption);
}

export {
  getItem ,
  getAllKeys ,
  multiGet ,
  
}
/* react-native Not a pure module */
