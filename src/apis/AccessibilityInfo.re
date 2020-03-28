type announcementResult = {
  announcement: string,
  success: bool,
};

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isBoldTextEnabled: unit => Js.Promise.t(bool) = "isBoldTextEnabled";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isGrayscaleEnabled: unit => Js.Promise.t(bool) =
  "isGrayscaleEnabled";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isInvertColorsEnabled: unit => Js.Promise.t(bool) =
  "isInvertColorsEnabled";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isReduceMotionEnabled: unit => Js.Promise.t(bool) =
  "isReduceMotionEnabled";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isReduceTransparencyEnabled: unit => Js.Promise.t(bool) =
  "isReduceTransparencyEnabled";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isScreenReaderEnabled: unit => Js.Promise.t(bool) =
  "isScreenReaderEnabled";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external setAccessibilityFocus: NativeTypes.nodeHandle => unit =
  "setAccessibilityFocus";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external announceForAccessibility: string => unit = "announceForAccessibility";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external addEventListener:
  (
  [@bs.string]
  [
    | `boldTextChanged(bool => unit)
    | `grayscaleChanged(bool => unit)
    | `invertColorsChanged(bool => unit)
    | `reduceMotionChanged(bool => unit)
    | `screenReaderChanged(bool => unit)
    | `reduceTransparencyChanged(bool => unit)
    | `announcementFinished(announcementResult => unit)
  ]
  ) =>
  unit =
  "addEventListener";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external removeEventListener:
  (
  [@bs.string]
  [
    | `boldTextChanged(bool => unit)
    | `grayscaleChanged(bool => unit)
    | `invertColorsChanged(bool => unit)
    | `reduceMotionChanged(bool => unit)
    | `screenReaderChanged(bool => unit)
    | `reduceTransparencyChanged(bool => unit)
    | `announcementFinished(announcementResult => unit)
  ]
  ) =>
  unit =
  "removeEventListener";
