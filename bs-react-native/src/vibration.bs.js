

import * as ReactNative from "react-native";

function vibrate(pattern, repeat) {
  ReactNative.Vibration.vibrate(pattern, repeat);
  return /* () */0;
}

function cancel(prim) {
  ReactNative.Vibration.cancel();
  return /* () */0;
}

export {
  vibrate ,
  cancel ,
  
}
/* react-native Not a pure module */
