/*
 https://reactnative.dev/docs/interactionmanager
 */

type interactionHandle

@module("react-native") @scope("InteractionManager")
external /* @todo this returns a cancellable "promise", we need to type return correctly */
runAfterInteractions: (unit => unit) => {.} = "runAfterInteractions"

@module("react-native") @scope("InteractionManager")
external createInteractionHandle: unit => interactionHandle = "createInteractionHandle"

@module("react-native") @scope("InteractionManager")
external clearInteractionHandle: interactionHandle => unit = "clearInteractionHandle"

@module("react-native") @scope("InteractionManager")
external setDeadline: float => unit = "setDeadline"
