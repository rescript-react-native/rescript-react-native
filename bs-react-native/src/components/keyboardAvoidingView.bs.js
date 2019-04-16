

import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Js_mapperRt from "bs-platform/lib/es6/js_mapperRt.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as ViewProps$BsReactNative from "./ViewProps.bs.js";

var jsMapperConstantArray = /* array */[
  /* tuple */[
    -889544535,
    "position"
  ],
  /* tuple */[
    -797091375,
    "padding"
  ],
  /* tuple */[
    38537191,
    "height"
  ]
];

function behaviorToJs(param) {
  return Js_mapperRt.binarySearch(3, param, jsMapperConstantArray);
}

function make(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, keyboardVerticalOffset, behavior, contentContainerStyle) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        keyboardVerticalOffset: keyboardVerticalOffset,
        behavior: Belt_Option.map(behavior, behaviorToJs),
        contentContainerStyle: contentContainerStyle
      });
  var partial_arg$1 = ReactNative.KeyboardAvoidingView;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  make ,
  
}
/* ReasonReact Not a pure module */
