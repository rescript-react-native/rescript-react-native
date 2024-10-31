type popupAction

@module("react-native") @scope(("UIManager", "PopupMenu"))
external itemSelected: popupAction = "itemSelected"

@module("react-native") @scope(("UIManager", "PopupMenu"))
external dismissed: popupAction = "dismissed"

// Android-only. This function is intended to be removed in the future,
// at which point it would return undefined. Accordingly it is wrapped in
// option.
@module("react-native") @scope("UIManager")
external setLayoutAnimationEnabledExperimental: option<bool => unit> =
  "setLayoutAnimationEnabledExperimental"

@module("react-native") @scope("UIManager")
external setJSResponder: (int, bool) => unit = "setJSResponder"

@module("react-native") @scope("UIManager")
external clearJSResponder: unit => unit = "clearJSResponder"
