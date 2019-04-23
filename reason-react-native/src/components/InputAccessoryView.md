---
id: components/InputAccessoryView
title: InputAccessoryView
wip: true
---

```reason
[@react.component] [@bs.module "react-native"]
external make:
  (
    ~backgroundColor: Style.color=?,
    ~nativeID: string=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~children: React.element=?
  ) =>
  React.element =
  "InputAccessoryView";

```