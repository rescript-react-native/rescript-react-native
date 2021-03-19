type message = string
type duration
type gravity

@module("react-native") @scope("ToastAndroid")
external short: duration = "SHORT"

@module("react-native") @scope("ToastAndroid")
external long: duration = "LONG"

@module("react-native") @scope("ToastAndroid")
external top: gravity = "TOP"

@module("react-native") @scope("ToastAndroid")
external bottom: gravity = "BOTTOM"

@module("react-native") @scope("ToastAndroid")
external center: gravity = "CENTER"

@module("react-native") @scope("ToastAndroid")
external show: (message, duration) => unit = "show"

@module("react-native") @scope("ToastAndroid")
external showWithGravity: (message, duration, gravity) => unit = "showWithGravity"

@module("react-native") @scope("ToastAndroid")
external showWithGravityAndOffset: (
  message,
  duration,
  gravity,
  ~xOffset: float,
  ~yOffset: float,
) => unit = "showWithGravityAndOffset"
