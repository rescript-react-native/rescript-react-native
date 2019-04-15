---
id: components/Button
title: Button
wip: true
---

```reason
[@react.component] [@bs.module "react-native"]
external make:
  (
    ~accessibilityLabel: string=?,
    ~color: Style.color=?,
    ~disabled: bool=?,
    ~hasTVPreferredFocus: bool=?,
    ~onPress: unit => unit,
    ~testID: string=?,
    ~title: string
  ) =>
  React.element =
  "Button";

```
