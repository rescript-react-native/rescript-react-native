@module("react-native") @scope("TurboModuleRegistry")
external get: string => Js.nullable<'t> = "get"

@module("react-native") @scope("TurboModuleRegistry")
external getEnforcing: string => 't = "getEnforcing"
