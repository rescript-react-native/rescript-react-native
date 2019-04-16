

import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as Js_undefined from "bs-platform/lib/es6/js_undefined.js";
import * as ReactNative from "react-native";

function setHidden(hidden, animation, param) {
  ReactNative.StatusBar.setHidden(hidden, Js_undefined.fromOption(Belt_Option.map(animation, (function (param) {
                  if (param !== -922086728) {
                    if (param >= -20462287) {
                      return "slide";
                    } else {
                      return "fade";
                    }
                  } else {
                    return "none";
                  }
                }))));
  return /* () */0;
}

function setBarStyle(style, animated, param) {
  ReactNative.StatusBar.setBarStyle(style !== -106329341 ? (
          style >= 465819841 ? "default" : "dark-content"
        ) : "light-content", Js_undefined.fromOption(animated));
  return /* () */0;
}

function setNetworkActivityIndicatorVisible(visible) {
  ReactNative.StatusBar.setNetworkActivityIndicatorVisible(visible);
  return /* () */0;
}

function setBackgroundColor(color, animated, param) {
  ReactNative.StatusBar.setBackgroundColor(color, Js_undefined.fromOption(animated));
  return /* () */0;
}

function setTranslucent(translucent) {
  ReactNative.StatusBar.setTranslucent(translucent);
  return /* () */0;
}

function make(animated, barStyle, hidden, backgroundColor, translucent, networkActivityIndicatorVisible, showHideTransition) {
  var partial_arg = {
    animated: animated,
    barStyle: Belt_Option.map(barStyle, (function (param) {
            if (param !== -106329341) {
              if (param >= 465819841) {
                return "default";
              } else {
                return "dark-content";
              }
            } else {
              return "light-content";
            }
          })),
    backgroundColor: backgroundColor,
    hidden: hidden,
    translucent: translucent,
    networkActivityIndicatorVisible: networkActivityIndicatorVisible,
    showHideTransition: Belt_Option.map(showHideTransition, (function (param) {
            if (param !== -922086728) {
              if (param >= -20462287) {
                return "slide";
              } else {
                return "fade";
              }
            } else {
              return "none";
            }
          }))
  };
  var partial_arg$1 = ReactNative.StatusBar;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  make ,
  setHidden ,
  setBarStyle ,
  setNetworkActivityIndicatorVisible ,
  setBackgroundColor ,
  setTranslucent ,
  
}
/* ReasonReact Not a pure module */
