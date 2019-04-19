

import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";

function make(accessibilityLabel, color, disabled, onPress, testID, title) {
  var partial_arg = {
    accessibilityLabel: accessibilityLabel,
    color: color,
    disabled: disabled,
    onPress: onPress,
    testID: testID,
    title: title
  };
  var partial_arg$1 = ReactNative.Button;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  make ,
  
}
/* ReasonReact Not a pure module */
