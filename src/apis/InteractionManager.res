/*
 https://reactnative.dev/docs/interactionmanager
 */

type interactionHandle

// cancellable "promise" returned by `runAfterInteractions`
type task = {cancel: unit => unit}

@deprecated("InteractionManager is deprecated by React Native.")
@module("react-native")
@scope("InteractionManager")
external runAfterInteractions: (unit => unit) => task = "runAfterInteractions"

@deprecated("InteractionManager is deprecated by React Native.")
@module("react-native")
@scope("InteractionManager")
external createInteractionHandle: unit => interactionHandle = "createInteractionHandle"

@deprecated("InteractionManager is deprecated by React Native.")
@module("react-native")
@scope("InteractionManager")
external clearInteractionHandle: interactionHandle => unit = "clearInteractionHandle"

@deprecated("InteractionManager is deprecated by React Native.")
@module("react-native")
@scope("InteractionManager")
external setDeadline: float => unit = "setDeadline"
