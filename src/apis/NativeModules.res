// We recommend that you bind your own custom native modules like this:

// @module("react-native") @scope(("NativeModules", "MyCustomModule"))
// external myFunc: unit => unit = "myFunc"

@module("react-native")
external nativeModules: Js.Dict.t<'a> = "NativeModules"

@module("react-native")
external requireNativeComponent: (string, @as(json`null`) _) => React.component<'a> =
  "requireNativeComponent"
