---
id: apis/InteractionManager
title: InteractionManager
wip: true
---

```reason
/*
 https://facebook.github.io/react-native/docs/interactionmanager
 */

type interactionHandle;

[@bs.module "react-native"] [@bs.scope "InteractionManager"]
/* @todo this returns a cancellable "promise", we need to type return correctly */
external runAfterInteractions: (unit => unit) => Js.t({.}) = "";

[@bs.module "react-native"] [@bs.scope "InteractionManager"]
external createInteractionHandle: unit => interactionHandle = "";

[@bs.module "react-native"] [@bs.scope "InteractionManager"]
external clearInteractionHandle: interactionHandle => unit = "";

[@bs.module "react-native"] [@bs.scope "InteractionManager"]
external setDeadline: float => unit = "";

```
