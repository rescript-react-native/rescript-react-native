

import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as ViewProps$BsReactNative from "./ViewProps.bs.js";

function make(color, label, value, testID) {
  var partial_arg = {
    label: label,
    value: value,
    color: color,
    testID: testID
  };
  var partial_arg$1 = ReactNative.Picker.Item;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

var Item = /* module */[/* make */make];

function encodeMode(param) {
  if (param >= 825427144) {
    return "dialog";
  } else {
    return "dropdown";
  }
}

function make$1(onValueChange, selectedValue, enabled, mode, prompt, itemStyle, accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        enabled: enabled,
        onValueChange: onValueChange,
        selectedValue: selectedValue,
        itemStyle: itemStyle,
        prompt: prompt,
        mode: Belt_Option.map(mode, encodeMode)
      });
  var partial_arg$1 = ReactNative.Picker;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  make$1 as make,
  Item ,
  
}
/* ReasonReact Not a pure module */
