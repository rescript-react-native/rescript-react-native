

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";

var $$Event = /* module */[];

function make(onError, onLayout, onLoad, onLoadEnd, onLoadStart, resizeMode, source, style, imageStyle, testID, resizeMethod, accessibilityLabel, accessible, blurRadius, capInsets, defaultSource, onPartialLoad, onProgress) {
  var partial_arg = {
    onLayout: onLayout,
    onError: onError,
    onLoad: onLoad,
    onLoadEnd: onLoadEnd,
    onLoadStart: onLoadStart,
    resizeMode: Belt_Option.map(resizeMode, (function (param) {
            if (param !== -162316795) {
              if (param >= 108828507) {
                if (param >= 427065300) {
                  return "contain";
                } else {
                  return "repeat";
                }
              } else if (param >= 98248149) {
                return "center";
              } else {
                return "cover";
              }
            } else {
              return "stretch";
            }
          })),
    source: Belt_Option.map(source, (function (param) {
            if (param[0] >= 4245324) {
              return param[1];
            } else {
              return $$Array.of_list(param[1]);
            }
          })),
    style: style,
    imageStyle: imageStyle,
    testID: testID,
    resizeMethod: Belt_Option.map(resizeMethod, (function (param) {
            if (param !== -120664438) {
              if (param >= 142301684) {
                return "resize";
              } else {
                return "auto";
              }
            } else {
              return "scale";
            }
          })),
    accessibilityLabel: accessibilityLabel,
    accessible: accessible,
    blurRadius: blurRadius,
    capInsets: capInsets,
    defaultSource: Belt_Option.map(defaultSource, (function (param) {
            return param[1];
          })),
    onPartialLoad: onPartialLoad,
    onProgress: Belt_Option.map(onProgress, (function (x, y) {
            return Curry._1(x, y.nativeEvent);
          }))
  };
  var partial_arg$1 = ReactNative.ImageBackground;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  $$Event ,
  make ,
  
}
/* ReasonReact Not a pure module */
