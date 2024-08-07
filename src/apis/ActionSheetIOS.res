type options = {
  options: array<string>,
  cancelButtonIndex?: int,
  destructiveButtonIndex?: array<int>,
  disabledButtonIndices?: int,
  title?: string,
  message?: string,
  tintColor?: Color.t,
  cancelButtonTintColor?: Color.t,
}

@module("react-native") @scope("ActionSheetIOS")
external showActionSheetWithOptions: (options, int => unit) => unit = "showActionSheetWithOptions"

type shareOptions = {
  url?: string,
  message?: string,
  subject?: string,
  excludedActivityTypes?: array<string>,
}

type error = {stack: option<string>}

@module("react-native") @scope("ActionSheetIOS")
external showShareActionSheetWithOptions: (
  shareOptions,
  error => unit,
  (bool, string) => unit,
) => unit = "showShareActionSheetWithOptions"

@module("react-native") @scope("ActionSheetIOS")
external dismissActionSheet: unit => unit = "dismissActionSheet"
