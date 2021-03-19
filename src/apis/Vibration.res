@scope("Vibration") @module("react-native")
external vibrateWithDuration: (int, ~repeat: bool=?, unit) => unit = "vibrate"

@scope("Vibration") @module("react-native")
external vibrateWithPattern: (array<int>, ~repeat: bool=?, unit) => unit = "vibrate"

@scope("Vibration") @module("react-native")
external cancel: unit => unit = "cancel"
