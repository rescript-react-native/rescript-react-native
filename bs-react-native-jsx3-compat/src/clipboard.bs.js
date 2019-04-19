

import * as ReactNative from "react-native";

function getString(prim) {
  return ReactNative.Clipboard.getString();
}

function setString(prim) {
  ReactNative.Clipboard.setString(prim);
  return /* () */0;
}

export {
  getString ,
  setString ,
  
}
/* react-native Not a pure module */
