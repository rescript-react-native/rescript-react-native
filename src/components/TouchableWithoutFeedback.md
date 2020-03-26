---
id: components/TouchableWithoutFeedback
title: TouchableWithoutFeedback
wip: true
---

```reason
include NativeElement;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // TouchableWithoutFeedback props
    ~accessible: bool=?,
    ~accessibilityComponentType: [@bs.string] [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityLabel: string=?,
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
    ~accessibilityTraits: array(AccessibilityTrait.t)=?,
    ~delayLongPress: int=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~disabled: bool=?,
    ~hitSlop: View.edgeInsets=?,
    ~onBlur: Event.targetEvent => unit=?,
    ~onFocus: Event.targetEvent => unit=?,
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
  "TouchableWithoutFeedback";

```
