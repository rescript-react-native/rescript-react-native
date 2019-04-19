

import * as List from "bs-platform/lib/es6/list.js";
import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as ReactNative from "react-native";
import * as Types$BsReactNative from "../types.bs.js";

function make(accessible, accessibilityLabel, accessibilityComponentType, accessibilityTraits, accessibilityRole, accessibilityStates, accessibilityHint, accessibilityIgnoresInvertColors, delayLongPress, delayPressIn, delayPressOut, disabled, hitSlop, onLayout, onLongPress, onPress, onPressIn, onPressOut, pressRetentionOffset, style, background, useForeground, testID) {
  var partial_arg = {
    accessible: accessible,
    accessibilityLabel: accessibilityLabel,
    delayLongPress: delayLongPress,
    delayPressIn: delayPressIn,
    delayPressOut: delayPressOut,
    disabled: disabled,
    hitSlop: hitSlop,
    onLayout: onLayout,
    onLongPress: onLongPress,
    onPress: onPress,
    background: background,
    onPressIn: onPressIn,
    onPressOut: onPressOut,
    pressRetentionOffset: pressRetentionOffset,
    style: style,
    useForeground: useForeground,
    accessibilityComponentType: Belt_Option.map(accessibilityComponentType, Types$BsReactNative.accessibilityComponentTypeToJs),
    accessibilityTraits: Belt_Option.map(accessibilityTraits, (function (x) {
            return $$Array.of_list(List.map(Types$BsReactNative.accessibilityTraitToJs, x));
          })),
    accessibilityRole: Belt_Option.map(accessibilityRole, Types$BsReactNative.accessibilityRoleToJs),
    accessibilityStates: Belt_Option.map(accessibilityStates, (function (x) {
            return $$Array.of_list(List.map(Types$BsReactNative.accessibilityStateToJs, x));
          })),
    accessibilityHint: accessibilityHint,
    accessibilityIgnoresInvertColors: accessibilityIgnoresInvertColors,
    testID: testID
  };
  var partial_arg$1 = ReactNative.TouchableNativeFeedback;
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

function selectableBackground(prim) {
  return ReactNative.TouchableNativeFeedback.SelectableBackground();
}

function selectableBackgroundBorderless(prim) {
  return ReactNative.TouchableNativeFeedback.SelectableBackgroundBorderless();
}

function canUseNativeForeground(prim) {
  return ReactNative.TouchableNativeFeedback.CanUseNativeForeground();
}

function ripple(prim, prim$1) {
  return ReactNative.TouchableNativeFeedback.Ripple(prim, prim$1);
}

export {
  make ,
  selectableBackground ,
  selectableBackgroundBorderless ,
  canUseNativeForeground ,
  ripple ,
  
}
/* ReasonReact Not a pure module */
