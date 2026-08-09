module ExtraValue = {
  @unboxed
  type t = String(string) | Number(float) | Bool(bool)
}

type extraValue = ExtraValue.t

type extra = {key: string, value: extraValue}

@scope("Linking") @module("react-native")
external openURL: string => promise<unit> = "openURL"

@scope("Linking") @module("react-native")
external canOpenURL: string => promise<bool> = "canOpenURL"

@scope("Linking") @module("react-native")
external getInitialURL: unit => promise<null<string>> = "getInitialURL"

@scope("Linking") @module("react-native")
external openSettings: unit => promise<unit> = "openSettings"

@scope("Linking") @module("react-native")
external sendIntent: (string, ~extras: array<extra>=?) => promise<unit> = "sendIntent"

type url = {url: string}

type eventType = [#url]

@scope("Linking") @module("react-native")
external addEventListener: (eventType, url => unit) => EventSubscription.t = "addEventListener"
