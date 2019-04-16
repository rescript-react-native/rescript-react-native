---
id: components/TouchableOpacity
title: TouchableOpacity
wip: true
---

```reason
type element;
type ref = React.Ref.t(Js.nullable(element));

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // TouchableOpacity props
    ~accessible: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityComponentType: [@bs.string] [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
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
    ~accessibilityStates: array(AccessibilityState.t)=?,
    ~delayLongPress: int=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~disabled: bool=?,
    ~hitSlop: Types.insets=?,
    ~style: Style.t=?,
    ~onLayout: Event.NativeLayoutEvent.t => unit=?,
    ~onLongPress: Event.NativePressEvent.t => unit=?,
    ~onPress: Event.NativePressEvent.t => unit=?,
    ~onPressIn: Event.NativePressEvent.t => unit=?,
    ~onPressOut: Event.NativePressEvent.t => unit=?,
    ~pressRetentionOffset: Types.insets=?,
    ~activeOpacity: float=?,
    ~focusedOpacity: float=?,
    ~testID: string=?,
    // FIXME
    ~tvParallaxProperties: Js.t({.})=?,
    ~children: React.element=?
  ) =>
  React.element =
  "TouchableOpacity";

[@bs.send]
external setOpacityTo: (ref, ~value: float, ~duration: float) => unit =
  "setOpacityTo";
```
