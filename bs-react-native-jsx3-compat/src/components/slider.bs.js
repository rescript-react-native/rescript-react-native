

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as ViewProps$BsReactNative from "./ViewProps.bs.js";

function convertImageSource(src) {
  if (src[0] >= 4245324) {
    return src[1];
  } else {
    return $$Array.of_list(src[1]);
  }
}

function make(disabled, maximumTrackTintColor, maximumValue, minimumTrackTintColor, minimumValue, onSlidingComplete, onValueChange, step, value, thumbTintColor, maximumTrackImage, minimumTrackImage, thumbImage, trackImage, accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        disabled: disabled,
        maximumTrackTintColor: maximumTrackTintColor,
        maximumValue: maximumValue,
        minimumTrackTintColor: minimumTrackTintColor,
        minimumValue: minimumValue,
        onSlidingComplete: onSlidingComplete,
        onValueChange: onValueChange,
        step: step,
        value: value,
        thumbTintColor: thumbTintColor,
        maximumTrackImage: Belt_Option.map(maximumTrackImage, convertImageSource),
        minimumTrackImage: Belt_Option.map(minimumTrackImage, convertImageSource),
        thumbImage: Belt_Option.map(thumbImage, convertImageSource),
        trackImage: Belt_Option.map(trackImage, convertImageSource)
      });
  var partial_arg$1 = ReactNative.Slider;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  make ,
  
}
/* ReasonReact Not a pure module */
