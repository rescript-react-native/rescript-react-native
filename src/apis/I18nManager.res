type constants = {
  isRTL: bool,
  doLeftAndRightSwapInRTL: bool,
  // This is usually only read and not created by the user.
  // Therefore prefer option<...> to an optional field for easier matching.
  localeIdentifier: option<string>,
}

@module("react-native") @scope("I18nManager")
external isRTL: bool = "isRTL"

@module("react-native") @scope("I18nManager")
external doLeftAndRightSwapInRTL: bool = "doLeftAndRightSwapInRTL"

@module("react-native") @scope("I18nManager")
external getConstants: unit => constants = "getConstants"

@module("react-native") @scope("I18nManager")
external allowRTL: bool => unit = "allowRTL"

@module("react-native") @scope("I18nManager")
external forceRTL: bool => unit = "forceRTL"

@module("react-native") @scope("I18nManager")
external swapLeftAndRightInRTL: bool => unit = "swapLeftAndRightInRTL"
