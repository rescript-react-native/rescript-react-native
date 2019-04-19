

import * as ReactNative from "react-native";

function getGravity(g) {
  switch (g) {
    case 0 : 
        return ReactNative.ToastAndroid.BOTTOM;
    case 1 : 
        return ReactNative.ToastAndroid.CENTER;
    case 2 : 
        return ReactNative.ToastAndroid.TOP;
    
  }
}

function show(message, duration, gravity, offset, param) {
  if (gravity !== undefined) {
    var gravity$1 = gravity;
    if (offset !== undefined) {
      var match = offset;
      ReactNative.ToastAndroid.showWithGravityAndOffset(message, duration ? ReactNative.ToastAndroid.SHORT : ReactNative.ToastAndroid.LONG, getGravity(gravity$1), match[0], match[1]);
      return /* () */0;
    } else {
      ReactNative.ToastAndroid.showWithGravity(message, duration ? ReactNative.ToastAndroid.SHORT : ReactNative.ToastAndroid.LONG, getGravity(gravity$1));
      return /* () */0;
    }
  } else if (offset !== undefined) {
    var match$1 = offset;
    ReactNative.ToastAndroid.showWithGravityAndOffset(message, duration ? ReactNative.ToastAndroid.SHORT : ReactNative.ToastAndroid.LONG, ReactNative.ToastAndroid.BOTTOM, match$1[0], match$1[1]);
    return /* () */0;
  } else {
    ReactNative.ToastAndroid.show(message, duration ? ReactNative.ToastAndroid.SHORT : ReactNative.ToastAndroid.LONG);
    return /* () */0;
  }
}

export {
  show ,
  
}
/* react-native Not a pure module */
