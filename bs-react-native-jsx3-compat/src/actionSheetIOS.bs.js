

import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as ReactNative from "react-native";
import * as Js_null_undefined from "bs-platform/lib/es6/js_null_undefined.js";

function makeShareActionSheetConfig(options, subject, excludedActivityTypes, param) {
  var obj = {
    subject: Js_null_undefined.fromOption(subject),
    excludedActivityTypes: Js_null_undefined.fromOption(excludedActivityTypes)
  };
  if (options.tag) {
    return Object.assign(obj, {
                url: options[0]
              });
  } else {
    return Object.assign(obj, {
                message: options[0]
              });
  }
}

function showActionSheetWithOptions(options, cancelButtonIndex, destructiveButtonIndex, title, message, tintColor, callback, param) {
  var tmp = {
    options: options
  };
  if (cancelButtonIndex !== undefined) {
    tmp.cancelButtonIndex = Caml_option.valFromOption(cancelButtonIndex);
  }
  if (destructiveButtonIndex !== undefined) {
    tmp.destructiveButtonIndex = Caml_option.valFromOption(destructiveButtonIndex);
  }
  if (title !== undefined) {
    tmp.title = Caml_option.valFromOption(title);
  }
  if (message !== undefined) {
    tmp.message = Caml_option.valFromOption(message);
  }
  if (tintColor !== undefined) {
    tmp.tintColor = Caml_option.valFromOption(tintColor);
  }
  ReactNative.ActionSheetIOS.showActionSheetWithOptions(tmp, callback);
  return /* () */0;
}

function showShareActionSheetWithOptions(options, subject, excludedActivityTypes, failureCallback, successCallback, param) {
  ReactNative.ActionSheetIOS.showShareActionSheetWithOptions(makeShareActionSheetConfig(options, subject, excludedActivityTypes, /* () */0), failureCallback, successCallback);
  return /* () */0;
}

export {
  showActionSheetWithOptions ,
  showShareActionSheetWithOptions ,
  
}
/* react-native Not a pure module */
