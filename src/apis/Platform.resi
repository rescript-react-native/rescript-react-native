type os = private string

@module("react-native") @scope("Platform") external os: os = "OS"

@bs.inline("ios")
let ios: os

@bs.inline("android")
let android: os

// react-native-web
@bs.inline("web")
let web: os

external unsafe: string => os = "%identity"
