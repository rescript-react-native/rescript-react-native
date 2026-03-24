@module("react-native") @scope("LogBox")
external ignoreLogs: array<string> => unit = "ignoreLogs"

@module("react-native") @scope("LogBox")
external ignoreLogsRegex: array<Js.Re.t> => unit = "ignoreLogs"

@module("react-native") @scope("LogBox")
external ignoreAllLogs: (~ignore: bool=?) => unit = "ignoreAllLogs"

@module("react-native") @scope("LogBox")
external install: unit => unit = "install"

@module("react-native") @scope("LogBox")
external uninstall: unit => unit = "uninstall"
