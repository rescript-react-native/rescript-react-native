/*
 https://reactnative.dev/docs/interactionmanager
 */

type interactionHandle

@bs.module("react-native") @bs.scope("InteractionManager")
external /* @todo this returns a cancellable "promise", we need to type return correctly */
runAfterInteractions: (unit => unit) => {.} = "runAfterInteractions"

@bs.module("react-native") @bs.scope("InteractionManager")
external createInteractionHandle: unit => interactionHandle = "createInteractionHandle"

@bs.module("react-native") @bs.scope("InteractionManager")
external clearInteractionHandle: interactionHandle => unit = "clearInteractionHandle"

@bs.module("react-native") @bs.scope("InteractionManager")
external setDeadline: float => unit = "setDeadline"
