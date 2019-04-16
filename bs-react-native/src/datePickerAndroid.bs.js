

import * as Pervasives from "bs-platform/lib/es6/pervasives.js";
import * as Js_mapperRt from "bs-platform/lib/es6/js_mapperRt.js";
import * as ReactNative from "react-native";
import * as Js_null_undefined from "bs-platform/lib/es6/js_null_undefined.js";

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -14065986,
    "calendar"
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

function action(resp) {
  if (resp.action === ReactNative.DatePickerAndroid.dateSetAction) {
    return /* Set */[/* record */[
              /* year */resp.year,
              /* month */resp.month,
              /* day */resp.day
            ]];
  } else if (resp.action === ReactNative.DatePickerAndroid.dismissedAction) {
    return /* Dismissed */0;
  } else {
    return Pervasives.failwith("Unknown action received from DatePickerAndroid. Please report this in the bs-react-native repository");
  }
}

function open_(date, minDate, maxDate, $staropt$star, param) {
  var mode = $staropt$star !== undefined ? $staropt$star : /* default */465819841;
  return ReactNative.DatePickerAndroid.open({
                date: date,
                minDate: Js_null_undefined.fromOption(minDate),
                maxDate: Js_null_undefined.fromOption(maxDate),
                mode: Js_mapperRt.binarySearch(3, mode, jsMapperConstantArray)
              }).then((function (resp) {
                return Promise.resolve(action(resp));
              }));
}

export {
  open_ ,
  
}
/* react-native Not a pure module */
