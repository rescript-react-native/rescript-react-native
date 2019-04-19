

import * as ReactNative from "react-native";

function create(prim) {
  return new ReactNative.NativeEventEmitter(prim);
}

function addListener(prim, prim$1, prim$2) {
  return prim.addListener(prim$1, prim$2);
}

function removeAllListeners(prim, prim$1) {
  prim.removeAllListeners(prim$1);
  return /* () */0;
}

function removeSubscription(prim, prim$1) {
  prim.removeSubscription(prim$1);
  return /* () */0;
}

var Subscription = [(function (prim, prim$1) {
      prim.remove();
      return /* () */0;
    })];

export {
  create ,
  addListener ,
  removeAllListeners ,
  removeSubscription ,
  Subscription ,
  
}
/* react-native Not a pure module */
