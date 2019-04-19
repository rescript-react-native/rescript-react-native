

import * as Belt_Array from "bs-platform/lib/es6/belt_Array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";

function encodeAnimationType(param) {
  if (param !== -922086728) {
    if (param >= -20462287) {
      return "slide";
    } else {
      return "fade";
    }
  } else {
    return "none";
  }
}

function encodeSupportedOrientations(xs) {
  return Belt_Array.map(xs, (function (param) {
                if (param !== -55740357) {
                  if (param >= 923863087) {
                    if (param >= 951001435) {
                      return "portrait";
                    } else {
                      return "portrait-upside-down";
                    }
                  } else if (param >= 402056674) {
                    return "landscape-left";
                  } else {
                    return "landscape-right";
                  }
                } else {
                  return "landscape";
                }
              }));
}

function make(animationType, onShow, transparent, visible, hardwareAccelerated, onRequestClose, onOrientationChange, supportedOrientations) {
  var partial_arg = {
    animationType: Belt_Option.map(animationType, encodeAnimationType),
    onShow: onShow,
    transparent: transparent,
    visible: visible,
    hardwareAccelerated: hardwareAccelerated,
    onRequestClose: onRequestClose,
    onOrientationChange: onOrientationChange,
    supportedOrientations: Belt_Option.map(supportedOrientations, encodeSupportedOrientations)
  };
  var partial_arg$1 = ReactNative.Modal;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  make ,
  
}
/* ReasonReact Not a pure module */
