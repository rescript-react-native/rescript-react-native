---
id: apis/AccessibilityInfo
title: AccessibilityInfo
wip: true
---

```reason
type announcementResult = {
  .
  "announcement": string,
  "success": bool,
};

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isBoldTextEnabled: unit => Js.Promise.t(bool) = "";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isGrayscaleEnabled: unit => Js.Promise.t(bool) = "";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isInvertColorsEnabled: unit => Js.Promise.t(bool) = "";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isReduceMotionEnabled: unit => Js.Promise.t(bool) = "";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isReduceTransparencyEnabled: unit => Js.Promise.t(bool) = "";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external isScreenReaderEnabled: unit => Js.Promise.t(bool) = "";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external setAccessibilityFocus: NativeTypes.nodeHandle => unit = "";

[@bs.scope "AccessibilityInfo"] [@bs.module "react-native"]
external announceForAccessibility: string => unit = "";

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
  "";

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
  "";

```
