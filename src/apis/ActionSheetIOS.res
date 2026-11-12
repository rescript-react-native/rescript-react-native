type options = {
  options: array<string>,
  cancelButtonIndex?: int,
  destructiveButtonIndex?: array<int>,
  disabledButtonIndices?: array<int>,
  title?: string,
  message?: string,
  anchor?: int,
  tintColor?: Color.t,
  cancelButtonTintColor?: Color.t,
  userInterfaceStyle?: Appearance.t,
  disabledButtonTintColor?: Color.t,
}

@module("react-native") @scope("ActionSheetIOS")
external showActionSheetWithOptions: (options, int => unit) => unit = "showActionSheetWithOptions"

type shareOptions = {
  url?: string,
  message?: string,
  subject?: string,
  excludedActivityTypes?: array<string>,
}

// This is only received by the failure callback and not created by the user.
// Therefore prefer option<...> to an optional field for easier matching.
type error = {
  domain: string,
  code: string,
  userInfo: option<{.}>,
  message: string,
}

@module("react-native") @scope("ActionSheetIOS")
external showShareActionSheetWithOptions: (
  shareOptions,
  error => unit,
  // success and the sharing method, `null` when sharing was cancelled
  (bool, nullable<string>) => unit,
) => unit = "showShareActionSheetWithOptions"

@module("react-native") @scope("ActionSheetIOS")
external dismissActionSheet: unit => unit = "dismissActionSheet"
