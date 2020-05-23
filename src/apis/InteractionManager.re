/*
 https://reactnative.dev/docs/interactionmanager
 */

type interactionHandle;

[@bs.module "react-native"] [@bs.scope "InteractionManager"]
/* @todo this returns a cancellable "promise", we need to type return correctly */
external runAfterInteractions: (unit => unit) => Js.t({.}) =
  "runAfterInteractions";

[@bs.module "react-native"] [@bs.scope "InteractionManager"]
external createInteractionHandle: unit => interactionHandle =
  "createInteractionHandle";

[@bs.module "react-native"] [@bs.scope "InteractionManager"]
external clearInteractionHandle: interactionHandle => unit =
  "clearInteractionHandle";

[@bs.module "react-native"] [@bs.scope "InteractionManager"]
external setDeadline: float => unit = "setDeadline";
