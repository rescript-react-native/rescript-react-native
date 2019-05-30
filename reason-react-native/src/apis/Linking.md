---
id: apis/Linking
title: Linking
wip: true
---

```reason
type extra;

[@bs.obj] external extra: (~key: string, ~value: 'a) => extra = "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external openURL: string => Js.Promise.t(unit) = "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external canOpenURL: string => Js.Promise.t(bool) = "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external getInitialURL: unit => Js.Promise.t(Js.Null.t(string)) = "";
```

As of React Native 0.60
```reason
[@bs.scope "Linking"] [@bs.module "react-native"]
external openSettings: unit => Js.Promise.t('a) = "";
```

As of React Native 0.59.8
```reason
[@bs.scope "Linking"] [@bs.module "react-native"]
external sendIntent: string => unit = "";
```

As of React Native 0.59.8
```reason
[@bs.scope "Linking"] [@bs.module "react-native"]
external sendIntentWithExtras: (string, array(extra)) => unit = "sendIntent";
```

[@bs.scope "Linking"] [@bs.module "react-native"]
external addEventListener:
  ([@bs.string] [ | `url], {. "url": string} => unit) => unit =
  "";

[@bs.scope "Linking"] [@bs.module "react-native"]
external removeEventListener:
  ([@bs.string] [ | `url], {. "url": string} => unit) => unit =
  "";

```
