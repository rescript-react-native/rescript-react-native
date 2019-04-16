

import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as ViewProps$BsReactNative from "./ViewProps.bs.js";

function make(selected, badge, icon, onPress, renderAsOriginal, badgeColor, selectedIcon, style, systemIcon, title, isTVSelectable, accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        selected: selected,
        badge: badge,
        icon: icon,
        onPress: onPress,
        renderAsOriginal: renderAsOriginal,
        badgeColor: badgeColor,
        selectedIcon: selectedIcon,
        style: style,
        systemIcon: Belt_Option.map(systemIcon, (function (param) {
                if (param >= 306050430) {
                  if (param >= 560120362) {
                    if (param >= 745984467) {
                      if (param >= 838090415) {
                        return "top-rated";
                      } else {
                        return "contacts";
                      }
                    } else if (param >= 710683512) {
                      return "recents";
                    } else {
                      return "favourites";
                    }
                  } else if (param >= 316108014) {
                    return "featured";
                  } else {
                    return "most-recent";
                  }
                } else if (param >= -487088280) {
                  if (param >= -89798937) {
                    if (param >= -69751829) {
                      return "downloads";
                    } else {
                      return "most-viewed";
                    }
                  } else if (param >= -465095340) {
                    return "history";
                  } else {
                    return "search";
                  }
                } else if (param >= -529952003) {
                  return "bookmarks";
                } else {
                  return "more";
                }
              })),
        title: title,
        isTVSelectable: isTVSelectable
      });
  var partial_arg$1 = ReactNative.TabBarIOS.Item;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

var Item = /* module */[/* make */make];

function make$1(barStyle, barTintColor, itemPositioning, tintColor, translucent, unselectedItemTintColor, unselectedTintColor, accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, testID, style, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS) {
  var partial_arg = ViewProps$BsReactNative.extend(accessibilityLabel, accessible, hitSlop, onAccessibilityTap, onLayout, onMagicTap, responderHandlers, pointerEvents, removeClippedSubviews, style, testID, accessibilityComponentType, accessibilityLiveRegion, collapsable, importantForAccessibility, needsOffscreenAlphaCompositing, renderToHardwareTextureAndroid, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, accessibilityViewIsModal, shouldRasterizeIOS, {
        barStyle: Belt_Option.map(barStyle, (function (param) {
                if (param >= 888264127) {
                  return "black";
                } else {
                  return "default";
                }
              })),
        barTintColor: barTintColor,
        itemPositioning: Belt_Option.map(itemPositioning, (function (param) {
                if (param !== -1011102077) {
                  if (param >= 98248149) {
                    return "center";
                  } else {
                    return "auto";
                  }
                } else {
                  return "fill";
                }
              })),
        tintColor: tintColor,
        translucent: translucent,
        unselectedItemTintColor: unselectedItemTintColor,
        unselectedTintColor: unselectedTintColor
      });
  var partial_arg$1 = ReactNative.TabBarIOS;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  make$1 as make,
  Item ,
  
}
/* ReasonReact Not a pure module */
