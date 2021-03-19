type os = string

@module("react-native") @scope("Platform") external os: os = "OS"

@inline
let ios = "ios"

@inline
let android = "android"

// react-native-web
@inline
let web = "web"

external unsafe: string => os = "%identity"
