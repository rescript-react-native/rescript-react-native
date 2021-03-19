@module("react-native") @scope("Settings")
external get: string => string = "get"

@module("react-native") @scope("Settings")
external set: Js.Dict.t<string> => unit = "set"

type watchToken

@module("react-native") @scope("Settings")
external watchKeys: (list<string>, unit => unit) => watchToken = "watchKeys"

@module("react-native") @scope("Settings")
external clearWatch: watchToken => unit = "clearWatch"
