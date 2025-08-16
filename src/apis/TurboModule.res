type turboModule = {@optional getConstants: option<unit => Js.Dict.t<Js.Json.t>>}
type get<'t> = option<'t>
type getEnforcing<'t> = 't

@module("react-native") @scope("TurboModuleRegistry")
external get: string => get<'t> = "get"

@module("react-native") @scope("TurboModuleRegistry")
external getEnforcing: string => getEnforcing<'t> = "getEnforcing"
