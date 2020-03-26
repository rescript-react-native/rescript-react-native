---
id: components/TouchableHighlight
title: TouchableHighlight
wip: true
---

```reason
include NativeElement;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // TouchableHighlight props
    ~activeOpacity: float=?,
    ~hasTVPreferredFocus: bool=?,
    ~onHideUnderlay: unit => unit=?,
    ~onShowUnderlay: unit => unit=?,
    ~style: Style.t=?,
    ~tvParallaxProperties: TV.parallax=?,
    ~underlayColor: string=?,
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
    ~accessibilityState: Accessibility.state=?,
    ~accessibilityTraits: array(AccessibilityTrait.t)=?,
    ~delayLongPress: int=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~disabled: bool=?,
    ~hitSlop: View.edgeInsets=?,
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
  "TouchableHighlight";

```
