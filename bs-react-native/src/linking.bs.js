

import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as ReactNative from "react-native";

function canOpenURL(url) {
  return ReactNative.Linking.canOpenURL(url).then((function (bool) {
                return Promise.resolve(bool);
              }));
}

function getInitialURL(param) {
  return ReactNative.Linking.getInitialURL().then((function (stringOrNull) {
                return Promise.resolve(stringOrNull === null ? undefined : Caml_option.some(stringOrNull));
              }));
}

export {
  canOpenURL ,
  getInitialURL ,
  
}
/* react-native Not a pure module */
