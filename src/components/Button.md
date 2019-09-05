---
id: components/Button
title: Button
wip: true
---

```reason
include NativeElement;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // Button props
    ~accessibilityLabel: string=?,
    ~color: Color.t=?,
    ~disabled: bool=?,
    ~hasTVPreferredFocus: bool=?,
    ~nextFocusDown: int=?,
    ~nextFocusForward: int=?,
    ~nextFocusLeft: int=?,
    ~nextFocusRight: int=?,
    ~nextFocusUp: int=?,
    ~onPress: Event.pressEvent => unit,
    ~testID: string=?,
    ~title: string
  ) =>
  React.element =
  "Button";

```
