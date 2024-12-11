@module("react-native") @scope("StyleSheet")
external hairlineWidth: float = "hairlineWidth"
@module("react-native") @scope("StyleSheet")
external absoluteFill: Style.t = "absoluteFill"
@module("react-native") @scope("StyleSheet")
external absoluteFillObject: Style.t = "absoluteFillObject"

@module("react-native") @scope("StyleSheet")
external create: ({..} as 'a) => ({..} as 'a) = "create"
@module("react-native") @scope("StyleSheet")
external flatten: array<Style.t> => Style.t = "flatten"
