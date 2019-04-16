

import * as ReactNative from "react-native";
import * as Caml_exceptions from "bs-platform/lib/es6/caml_exceptions.js";
import * as Caml_js_exceptions from "bs-platform/lib/es6/caml_js_exceptions.js";

var UnknownPlatform = Caml_exceptions.create("Platform-BsReactNative.UnknownPlatform");

function os(param) {
  var x = ReactNative.Platform.OS;
  switch (x) {
    case "android" : 
        return /* Android */0;
    case "ios" : 
        var match = ReactNative.Platform.isPad;
        if (match) {
          return /* IOS */[/* Pad */1];
        } else {
          var match$1 = ReactNative.Platform.isTVOS;
          if (match$1) {
            return /* IOS */[/* TV */2];
          } else {
            return /* IOS */[/* Phone */0];
          }
        }
    default:
      throw [
            UnknownPlatform,
            x
          ];
  }
}

function equals(targetOs) {
  var exit = 0;
  var val;
  var val$1;
  try {
    val = os(/* () */0);
    val$1 = targetOs;
    exit = 1;
  }
  catch (raw_exn){
    var exn = Caml_js_exceptions.internalToOCamlException(raw_exn);
    if (exn[0] === UnknownPlatform) {
      return false;
    } else {
      throw exn;
    }
  }
  if (exit === 1) {
    if (val) {
      if (val$1) {
        return true;
      } else {
        return false;
      }
    } else if (val$1) {
      return false;
    } else {
      return true;
    }
  }
  
}

var UnknownVersion = Caml_exceptions.create("Platform-BsReactNative.UnknownVersion");

function version(param) {
  var match = ReactNative.Platform.Version;
  if (match !== undefined) {
    return match;
  } else {
    throw UnknownVersion;
  }
}

function select(options) {
  return ReactNative.Platform.select({
              ios: options[/* ios */0],
              android: options[/* android */1]
            });
}

export {
  UnknownPlatform ,
  os ,
  equals ,
  UnknownVersion ,
  version ,
  select ,
  
}
/* react-native Not a pure module */
