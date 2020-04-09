---
id: components/TouchableNativeFeedback
title: TouchableNativeFeedback
wip: true
---

```reason
include NativeElement;

module Background = {
  type t;

  [@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
  external selectableBackground: unit => t = "SelectableBackground";

  [@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
  external selectableBackgroundBorderless: unit => t =
    "SelectableBackgroundBorderless";

  [@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
  external canUseNativeForeground: unit => t = "CanUseNativeForeground";

  [@bs.module "react-native"] [@bs.scope "TouchableNativeFeedback"]
  external ripple: (string, bool) => t = "Ripple";
};

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // TouchableNativeFeedback props
    ~background: Background.t=?,
    ~useForeground: bool=?,
    // TouchableWithoutFeedback props
    ~accessible: bool=?,
    ~accessibilityComponentType: [@bs.string] [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityElementsHidden: bool=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityLiveRegion: [@bs.string] [ | `none | `polite | `assertive]=?,
    ~accessibilityRole: [@bs.string] [
                          | `none
                          | `button
                          | `link
                          | `search
                          | `image
                          | `keyboardkey
                          | `text
                          | `adjustable
                          | `header
                          | `summary
                          | `imagebutton
                        ]
                          =?,
    ~accessibilityState: Accessibility.state=?,
    ~accessibilityTraits: array(AccessibilityTrait.t)=?,
    ~accessibilityValue: Accessibility.value=?,
    ~accessibilityViewIsModal: bool=?,
    ~delayLongPress: int=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~disabled: bool=?,
    ~hitSlop: View.edgeInsets=?,
    ~importantForAccessibility: [@bs.string] [
                                  | `auto
                                  | `yes
                                  | `no
                                  | [@bs.as "no-hide-descendants"]
                                    `noHideDescendants
                                ]
                                  =?,
    ~onLayout: Event.layoutEvent => unit=?,
    ~onLongPress: Event.pressEvent => unit=?,
    ~onPress: Event.pressEvent => unit=?,
    ~onPressIn: Event.pressEvent => unit=?,
    ~onPressOut: Event.pressEvent => unit=?,
    ~pressRetentionOffset: View.edgeInsets=?,
    ~testID: string=?,
    ~touchSoundDisabled: bool=?,
    ~children: React.element=?
  ) =>
  React.element =
  "TouchableNativeFeedback";

```
