type error

@scope("AsyncStorage") @module("react-native")
external getItem: string => Js.Promise.t<Js.Null.t<string>> = "getItem"

@scope("AsyncStorage") @module("react-native")
external setItem: (string, string) => Js.Promise.t<unit> = "setItem"

@scope("AsyncStorage") @module("react-native")
external removeItem: string => Js.Promise.t<unit> = "removeItem"

@scope("AsyncStorage") @module("react-native")
external mergeItem: (string, string) => Js.Promise.t<unit> = "mergeItem"

@scope("AsyncStorage") @module("react-native")
external clear: unit => Js.Promise.t<unit> = "clear"

@scope("AsyncStorage") @module("react-native")
external getAllKeys: unit => Js.Promise.t<Js.Null.t<array<string>>> = "getAllKeys"

@scope("AsyncStorage") @module("react-native")
external flushGetRequests: unit => unit = "flushGetRequests"

@scope("AsyncStorage") @module("react-native")
external multiGet: array<string> => Js.Promise.t<Js.Null.t<array<array<string>>>> = "multiGet"

@scope("AsyncStorage") @module("react-native")
external multiSet: array<(string, string)> => Js.Promise.t<unit> = "multiSet"

@scope("AsyncStorage") @module("react-native")
external multiRemove: array<string> => Js.Promise.t<unit> = "multiRemove"

@scope("AsyncStorage") @module("react-native")
external multiMerge: array<array<string>> => Js.Promise.t<unit> = "multiMerge"
