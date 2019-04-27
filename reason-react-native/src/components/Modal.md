---
id: components/Modal
title: Modal
wip: true
---

```reason
type element;
type ref = React.Ref.t(Js.nullable(element));

module Orientation = Modal_Orientation;

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // Modal props
    ~animationType: [@bs.string] [ | `none | `slide | `fade]=?,
    ~hardwareAccelerated: bool=?,
    ~onDismiss: unit => unit=?,
    ~onOrientationChange: unit => unit=?,
    ~onRequestClose: unit => unit=?,
    ~onShow: unit => unit=?,
    ~presentationStyle: [@bs.string] [
                          | `fullScreen
                          | `pageSheet
                          | `formSheet
                          | `overFullScreen
                        ]
                          =?,
    ~supportedOrientations: array(Orientation.t)=?,
    ~transparent: bool=?,
    ~visible: bool=?,
    ~children: React.element=?
  ) =>
  React.element =
  "Modal";

```
