

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Js_undefined from "bs-platform/lib/es6/js_undefined.js";
import * as ReactNative from "react-native";

function alert(title, message, buttons, options, type_, param) {
  var msg = Js_undefined.fromOption(message);
  var transformButtons = function (xs) {
    return $$Array.map((function (param) {
                  return {
                          text: Js_undefined.fromOption(param[/* text */0]),
                          onPress: Js_undefined.fromOption(param[/* onPress */1]),
                          style: Js_undefined.fromOption(Belt_Option.map(param[/* style */2], (function (param) {
                                      if (param !== 465819841) {
                                        if (param >= 942927226) {
                                          return "cancel";
                                        } else {
                                          return "destructive";
                                        }
                                      } else {
                                        return "default";
                                      }
                                    })))
                        };
                }), $$Array.of_list(xs));
  };
  var bts = Js_undefined.fromOption(Belt_Option.map(buttons, transformButtons));
  var opts = Js_undefined.fromOption(Belt_Option.map(options, (function (param) {
              return {
                      cancelable: Js_undefined.fromOption(param[/* cancelable */0]),
                      onDismiss: Js_undefined.fromOption(param[/* onDismiss */1])
                    };
            })));
  var t_ = Js_undefined.fromOption(Belt_Option.map(type_, (function (param) {
              if (param >= 780034244) {
                if (param >= 904380375) {
                  return "plain-text";
                } else {
                  return "secure-text";
                }
              } else if (param >= 465819841) {
                return "default";
              } else {
                return "login-password";
              }
            })));
  ReactNative.Alert.alert(title, msg, bts, opts, t_);
  return /* () */0;
}

export {
  alert ,
  
}
/* react-native Not a pure module */
