

import * as ReactNative from "react-native";
import * as PromiseUtils$ReactNative from "../utils/PromiseUtils.bs.js";

function getInitialURL(param) {
  return ReactNative.Linking.getInitialURL().then(PromiseUtils$ReactNative.nullableToOption);
}

export {
  getInitialURL ,
  
}
/* react-native Not a pure module */
