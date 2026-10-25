@deprecated(
  "Clipboard has been extracted from react-native core and will be removed in a future release, use @react-native-clipboard/clipboard instead."
)
@module("react-native")
@scope("Clipboard")
external getString: unit => promise<string> = "getString"

@deprecated(
  "Clipboard has been extracted from react-native core and will be removed in a future release, use @react-native-clipboard/clipboard instead."
)
@module("react-native")
@scope("Clipboard")
external setString: string => unit = "setString"
