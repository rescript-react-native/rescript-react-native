

import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as ViewProps$BsReactNative from "./ViewProps.bs.js";

function make(progress, progressImage, progressTintColor, progressViewStyle, trackImage, trackTintColor, accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        progress: progress,
        progressImage: progressImage,
        progressTintColor: progressTintColor,
        progressViewStyle: progressViewStyle,
        trackImage: trackImage,
        trackTintColor: trackTintColor
      });
  var partial_arg$1 = ReactNative.ProgressViewIOS;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  make ,
  
}
/* ReasonReact Not a pure module */
