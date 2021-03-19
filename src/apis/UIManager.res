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

// Android-only
@module("react-native") @scope("UIManager")
external showPopupMenu: (
  int,
  array<string>,
  ~onError: unit => unit,
  ~onSuccess: (popupAction, option<int>) => unit,
) => unit = "showPopupMenu"

// Android-only
@module("react-native") @scope("UIManager")
external dismissPopupMenu: unit => unit = "dismissPopupMenu"

@module("react-native") @scope("UIManager")
external setJSResponder: (int, bool) => unit = "setJSResponder"

@module("react-native") @scope("UIManager")
external clearJSResponder: unit => unit = "clearJSResponder"
