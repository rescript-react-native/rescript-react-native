

import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as ViewProps$BsReactNative from "./ViewProps.bs.js";

function encodeSize(size) {
  if (typeof size === "number") {
    if (size >= -9768761) {
      return "small";
    } else {
      return "large";
    }
  } else {
    var match = ReactNative.Platform.OS;
    if (match === "ios") {
      console.warn("Passing 'exact' to the size prop of activityIndicator is supported only on Android. Because you only provided the 'exact' size, we defaulted it to the small size on iOS");
      return "small";
    } else {
      return size[1];
    }
  }
}

function make(animating, color, size, hidesWhenStopped, accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        animating: animating,
        color: color,
        size: Belt_Option.map(size, encodeSize),
        hidesWhenStopped: hidesWhenStopped
      });
  var partial_arg$1 = ReactNative.ActivityIndicator;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  make ,
  
}
/* ReasonReact Not a pure module */
