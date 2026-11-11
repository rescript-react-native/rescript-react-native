@module("react-native") @scope("ReactNativeVersion")
external major: int = "major"

@module("react-native") @scope("ReactNativeVersion")
external minor: int = "minor"

@module("react-native") @scope("ReactNativeVersion")
external patch: int = "patch"

@module("react-native") @scope("ReactNativeVersion")
external prerelease: Null.t<string> = "prerelease"

@module("react-native") @scope("ReactNativeVersion")
external getVersionString: unit => string = "getVersionString"
