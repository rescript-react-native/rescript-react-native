---
id: apis/StyleSheet
title: StyleSheet
wip: true
---

```reason
[@bs.module "react-native"] [@bs.scope "StyleSheet"]
external hairlineWidth: float = "";
[@bs.module "react-native"] [@bs.scope "StyleSheet"]
external absoluteFill: Style.t = "";
[@bs.module "react-native"] [@bs.scope "StyleSheet"]
external absoluteFillObject: Style.t = "";

[@bs.module "react-native"] [@bs.scope "StyleSheet"]
external create: Js.t('a) => Js.t('a) = "";
[@bs.module "react-native"] [@bs.scope "StyleSheet"]
external flatten: array(Style.t) => Style.t = "";

```
