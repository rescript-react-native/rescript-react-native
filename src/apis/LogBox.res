@bs.module("react-native") @bs.scope("LogBox")
external ignoreLogs: array<string> => unit = "ignoreLogs"

@bs.module("react-native") @bs.scope("LogBox")
external ignoreAllLogs: unit => unit = "ignoreAllLogs"
