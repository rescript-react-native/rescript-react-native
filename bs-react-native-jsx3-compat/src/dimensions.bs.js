

import * as ReactNative from "react-native";

function get(key) {
  return ReactNative.Dimensions.get(key >= -762539024 ? "window" : "screen");
}

export {
  get ,
  
}
/* react-native Not a pure module */
