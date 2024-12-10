module ExtraValue = {
  type t

  external fromString: string => t = "%identity"
  external fromInt: int => t = "%identity"
  external fromFloat: float => t = "%identity"
  external fromBool: bool => t = "%identity"
}

type extraValue = ExtraValue.t

type extra = {key: string, value: extraValue}

@scope("Linking") @module("react-native")
external openURL: string => promise<unit> = "openURL"

@scope("Linking") @module("react-native")
external canOpenURL: string => promise<bool> = "canOpenURL"

@scope("Linking") @module("react-native")
external getInitialURL: unit => promise<Js.Null.t<string>> = "getInitialURL"

@scope("Linking") @module("react-native")
external openSettings: unit => promise<'a> = "openSettings"

// multiple externals
@scope("Linking") @module("react-native")
external sendIntent: string => unit = "sendIntent"

// multiple externals
@scope("Linking") @module("react-native")
external sendIntentWithExtras: (string, array<extra>) => unit = "sendIntent"

type url = {url: string}

type eventType = [#url]

@scope("Linking") @module("react-native")
external addEventListener: (eventType, url => unit) => EventSubscription.t = "addEventListener"
