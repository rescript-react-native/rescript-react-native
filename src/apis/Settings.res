@module("react-native") @scope("Settings")
external get: string => string = "get"

@module("react-native") @scope("Settings")
external set: dict<string> => unit = "set"

@notUndefined
type watchToken

@module("react-native") @scope("Settings")
external watchKeys: (array<string>, unit => unit) => watchToken = "watchKeys"

@module("react-native") @scope("Settings")
external clearWatch: watchToken => unit = "clearWatch"
