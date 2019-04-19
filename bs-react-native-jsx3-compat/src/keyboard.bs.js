

import * as ReactNative from "react-native";

function keyboardEventToJs(param) {
  switch (param) {
    case 0 : 
        return "keyboardWillShow";
    case 1 : 
        return "keyboardDidShow";
    case 2 : 
        return "keyboardWillHide";
    case 3 : 
        return "keyboardDidHide";
    case 4 : 
        return "keyboardWillChangeFrame";
    case 5 : 
        return "keyboardDidChangeFrame";
    
  }
}

function addListener(keyboardEvent, listener) {
  return ReactNative.Keyboard.addListener(keyboardEventToJs(keyboardEvent), listener);
}

function removeAllListeners(keyboardEvent) {
  ReactNative.Keyboard.removeAllListeners(keyboardEventToJs(keyboardEvent));
  return /* () */0;
}

function removeListener(keyboardEvent, listener) {
  ReactNative.Keyboard.removeListener(keyboardEventToJs(keyboardEvent), listener);
  return /* () */0;
}

var Subscription = [(function (prim) {
      prim.remove();
      return /* () */0;
    })];

export {
  addListener ,
  removeAllListeners ,
  removeListener ,
  Subscription ,
  
}
/* react-native Not a pure module */
