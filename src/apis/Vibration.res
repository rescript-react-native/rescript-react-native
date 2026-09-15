@unboxed type pattern = Number(int) | Array(array<int>)

@scope("Vibration") @module("react-native")
external vibrate: (~pattern: pattern=?, ~repeat: bool=?) => unit = "vibrate"

@scope("Vibration") @module("react-native")
external cancel: unit => unit = "cancel"
