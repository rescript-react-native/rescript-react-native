

import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as ViewProps$BsReactNative from "./ViewProps.bs.js";

function make(initialPage, keyboardDismissMode, onPageScroll, onPageScrollStateChanged, onPageSelected, pageMargin, peekEnabled, scrollEnabled, accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        initialPage: initialPage,
        onPageScroll: onPageScroll,
        onPageScrollStateChanged: onPageScrollStateChanged,
        onPageSelected: onPageSelected,
        pageMargin: pageMargin,
        keyboardDismissMode: Belt_Option.map(keyboardDismissMode, (function (param) {
                if (param >= -453364557) {
                  return "on-drag";
                } else {
                  return "none";
                }
              })),
        peekEnabled: peekEnabled,
        scrollEnabled: scrollEnabled
      });
  var partial_arg$1 = ReactNative.ViewPagerAndroid;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

function setPage(prim, prim$1) {
  prim.setPage(prim$1);
  return /* () */0;
}

export {
  make ,
  setPage ,
  
}
/* ReasonReact Not a pure module */
