---
id: apis/Alert
title: Alert
wip: true
---

```reason
type options;

[@bs.obj]
external options:
  (~cancelable: bool=?, ~onDismiss: unit => unit=?, unit) => options =
  "";

type button;

[@bs.obj]
external button:
  (
    ~text: string=?,
    ~onPress: unit => unit=?,
    ~style: [@bs.string] [ | `default | `cancel | `destructive]=?,
    unit
  ) =>
  button =
  "";

[@bs.scope "Alert"] [@bs.module "react-native"]
external alert:
  (
    ~title: string,
    ~message: string=?,
    ~buttons: array(button)=?,
    ~options: options=?,
    ~type_: [@bs.string] [
              | `default
              | `plainText
              | `secureText
              | `loginPassword
            ]
              =?,
    unit
  ) =>
  unit =
  "alert";

```
