@module("react-native") @scope("Clipboard")
external getString: unit => Js.Promise.t<string> = "getString"

@module("react-native") @scope("Clipboard")
external setString: string => unit = "setString"
