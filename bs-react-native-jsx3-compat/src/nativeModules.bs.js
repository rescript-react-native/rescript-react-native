

import * as ReactNative from "react-native";

function get(name) {
  return ReactNative.NativeModules[name];
}

function requireNativeComponent(name) {
  return ReactNative.requireNativeComponent(name, null);
}

export {
  get ,
  requireNativeComponent ,
  
}
/* react-native Not a pure module */
