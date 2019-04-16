

import * as List from "bs-platform/lib/es6/list.js";
import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Types$BsReactNative from "../types.bs.js";

function serializeResponderHandlers(handlers) {
  if (handlers !== undefined) {
    var handlers$1 = handlers;
    return {
            onMoveShouldSetResponder: Belt_Option.map(handlers$1[/* onMoveShouldSetResponder */0], (function (g, x) {
                    return Curry._1(g, x);
                  })),
            onMoveShouldSetResponderCapture: Belt_Option.map(handlers$1[/* onMoveShouldSetResponderCapture */1], (function (g, x) {
                    return Curry._1(g, x);
                  })),
            onResponderGrant: handlers$1[/* onResponderGrant */2],
            onResponderMove: handlers$1[/* onResponderMove */3],
            onResponderReject: handlers$1[/* onResponderReject */4],
            onResponderRelease: handlers$1[/* onResponderRelease */5],
            onResponderTerminate: handlers$1[/* onResponderTerminate */6],
            onResponderTerminationRequest: handlers$1[/* onResponderTerminationRequest */7],
            onStartShouldSetResponder: Belt_Option.map(handlers$1[/* onStartShouldSetResponder */8], (function (g, x) {
                    return Curry._1(g, x);
                  })),
            onStartShouldSetResponderCapture: Belt_Option.map(handlers$1[/* onStartShouldSetResponderCapture */9], (function (g, x) {
                    return Curry._1(g, x);
                  }))
          };
  } else {
    return { };
  }
}

function extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, moreProps) {
  return Object.assign(Object.assign({
                  accessibilityLabel: accessibilityLabel,
                  accessible: accessible,
                  hitSlop: hitSlop,
                  onAccessibilityTap: onAccessibilityTap,
                  onLayout: onLayout,
                  onMagicTap: onMagicTap,
                  removeClippedSubviews: removeClippedSubviews,
                  pointerEvents: Belt_Option.map(pointerEvents, Types$BsReactNative.pointerEventsToJs),
                  style: style,
                  testID: testID,
                  accessibilityComponentType: Belt_Option.map(accessibilityComponentType, Types$BsReactNative.accessibilityComponentTypeToJs),
                  accessibilityLiveRegion: Belt_Option.map(accessibilityLiveRegion, Types$BsReactNative.accessibilityLiveRegionToJs),
                  collapsable: collapsable,
                  importantForAccessibility: Belt_Option.map(importantForAccessibility, Types$BsReactNative.importantForAccessibilityToJs),
                  needsOffscreenAlphaCompositing: needsOffscreenAlphaCompositing,
                  renderToHardwareTextureAndroid: renderToHardwareTextureAndroid,
                  accessibilityTraits: Belt_Option.map(accessibilityTraits, (function (x) {
                          return $$Array.of_list(List.map(Types$BsReactNative.accessibilityTraitToJs, x));
                        })),
                  accessibilityRole: Belt_Option.map(accessibilityRole, Types$BsReactNative.accessibilityRoleToJs),
                  accessibilityStates: Belt_Option.map(accessibilityStates, (function (x) {
                          return $$Array.of_list(List.map(Types$BsReactNative.accessibilityStateToJs, x));
                        })),
                  accessibilityHint: accessibilityHint,
                  accessibilityIgnoresInvertColors: accessibilityIgnoresInvertColors,
                  accessibilityViewIsModal: accessibilityViewIsModal,
                  shouldRasterizeIOS: shouldRasterizeIOS
                }, serializeResponderHandlers(responderHandlers)), moreProps);
}

export {
  extend ,
  
}
/* No side effect */
