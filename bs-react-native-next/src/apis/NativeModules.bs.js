

import * as ReactNative from "react-native";

function get(name) {
  return ReactNative.NativeModules[name];
}

export {
  get ,
  
}
/* react-native Not a pure module */
