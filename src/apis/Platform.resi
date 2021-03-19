type os = private string

@module("react-native") @scope("Platform") external os: os = "OS"

@inline("ios")
let ios: os

@inline("android")
let android: os

// react-native-web
@inline("web")
let web: os

external unsafe: string => os = "%identity"
