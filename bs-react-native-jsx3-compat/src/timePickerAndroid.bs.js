

import * as Caml_obj from "bs-platform/lib/es6/caml_obj.js";
import * as Pervasives from "bs-platform/lib/es6/pervasives.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as Js_mapperRt from "bs-platform/lib/es6/js_mapperRt.js";
import * as ReactNative from "react-native";
import * as Js_null_undefined from "bs-platform/lib/es6/js_null_undefined.js";

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -933033522,
    "clock"
  ],
  /* tuple */[
    465819841,
    "default"
  ],
  /* tuple */[
    876147673,
    "spinner"
  ]
];

function actionHandler(resp) {
  if (resp.action === ReactNative.TimePickerAndroid.timeSetAction) {
    return /* Set */[/* record */[
              /* hour */resp.hour,
              /* minute */resp.minute
            ]];
  } else if (resp.action === ReactNative.TimePickerAndroid.dismissedAction) {
    return /* Dismissed */0;
  } else {
    return Pervasives.failwith("Unknown action received from TimePickerAndroid. Please report this in the bs-react-native repository");
  }
}

function rangeHandler(valueName, valueFrom, valueTo, value) {
  if (value !== undefined) {
    var v = Caml_option.valFromOption(value);
    if (Caml_obj.caml_lessequal(v, valueTo) && Caml_obj.caml_greaterequal(v, valueFrom)) {
      return Caml_option.some(v);
    } else {
      return Pervasives.failwith("" + (String(valueName) + (" must be a value between " + (String(valueFrom) + (" and " + (String(valueTo) + ""))))));
    }
  }
  
}

function open_(hour, minute, is24Hour, $staropt$star, param) {
  var mode = $staropt$star !== undefined ? $staropt$star : /* default */465819841;
  return ReactNative.TimePickerAndroid.open({
                hour: Js_null_undefined.fromOption(rangeHandler("Hour", 0, 23, hour)),
                minute: Js_null_undefined.fromOption(rangeHandler("Minute", 0, 59, minute)),
                is24Hour: Js_null_undefined.fromOption(is24Hour),
                mode: Js_mapperRt.binarySearch(3, mode, jsMapperConstantArray)
              }).then((function (resp) {
                return Promise.resolve(actionHandler(resp));
              }));
}

export {
  open_ ,
  
}
/* react-native Not a pure module */
