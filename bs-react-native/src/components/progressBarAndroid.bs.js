

import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as ViewProps$BsReactNative from "./ViewProps.bs.js";

function styleAttribute(attr) {
  if (attr >= 188904336) {
    if (attr >= 311976103) {
      if (attr >= 912164297) {
        return "SmallInverse";
      } else {
        return "Small";
      }
    } else if (attr >= 208994564) {
      return "Horizontal";
    } else {
      return "Inverse";
    }
  } else if (attr !== -175158955) {
    if (attr >= 48800667) {
      return "Large";
    } else {
      return "Normal";
    }
  } else {
    return "LargeInverse";
  }
}

function make(animating, color, indeterminate, progress, styleAttr, accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        animating: animating,
        color: color,
        indeterminate: indeterminate,
        progress: progress,
        styleAttr: Belt_Option.map(styleAttr, styleAttribute),
        testID: testID
      });
  var partial_arg$1 = ReactNative.ProgressBarAndroid;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  make ,
  
}
/* ReasonReact Not a pure module */
