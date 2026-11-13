// the stored value, of any JSON type, or `None` when the key is not set
@module("react-native") @scope("Settings") @return(nullable)
external get: string => option<JSON.t> = "get"

@module("react-native") @scope("Settings")
external set: dict<string> => unit = "set"

@notUndefined
type watchToken

@module("react-native") @scope("Settings")
external watchKeys: (array<string>, unit => unit) => watchToken = "watchKeys"

@module("react-native") @scope("Settings")
external clearWatch: watchToken => unit = "clearWatch"
