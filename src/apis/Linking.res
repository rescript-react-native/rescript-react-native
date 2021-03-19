type extra
@obj external extra: (~key: string, ~value: 'a) => extra = ""

@scope("Linking") @module("react-native")
external openURL: string => Js.Promise.t<unit> = "openURL"

@scope("Linking") @module("react-native")
external canOpenURL: string => Js.Promise.t<bool> = "canOpenURL"

@scope("Linking") @module("react-native")
external getInitialURL: unit => Js.Promise.t<Js.Null.t<string>> = "getInitialURL"

@scope("Linking") @module("react-native")
external openSettings: unit => Js.Promise.t<'a> = "openSettings"

// multiple externals
@scope("Linking") @module("react-native")
external sendIntent: string => unit = "sendIntent"

// multiple externals
@scope("Linking") @module("react-native")
external sendIntentWithExtras: (string, array<extra>) => unit = "sendIntent"

type url = {url: string}

type eventType = [#url]

@scope("Linking") @module("react-native")
external addEventListener: (eventType, url => unit) => unit = "addEventListener"

@scope("Linking") @module("react-native")
external removeEventListener: (eventType, url => unit) => unit = "removeEventListener"
