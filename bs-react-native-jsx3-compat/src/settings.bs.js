

import * as ReactNative from "react-native";

function get(prim) {
  return ReactNative.Settings.get(prim);
}

function set(prim) {
  ReactNative.Settings.set(prim);
  return /* () */0;
}

function watchKeys(prim, prim$1) {
  return ReactNative.Settings.watchKeys(prim, prim$1);
}

function clearWatch(prim) {
  ReactNative.Settings.clearWatch(prim);
  return /* () */0;
}

export {
  get ,
  set ,
  watchKeys ,
  clearWatch ,
  
}
/* react-native Not a pure module */
