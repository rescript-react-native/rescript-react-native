

import * as ReactNative from "react-native";

function currentState(param) {
  var currState = ReactNative.AppState.currentState;
  switch (currState) {
    case "active" : 
        return /* Active */0;
    case "background" : 
        return /* Background */1;
    default:
      return /* Inactive */2;
  }
}

export {
  currentState ,
  
}
/* react-native Not a pure module */
