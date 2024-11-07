@module("react-native") @scope("Clipboard")
external getString: unit => promise<string> = "getString"

@module("react-native") @scope("Clipboard")
external setString: string => unit = "setString"
