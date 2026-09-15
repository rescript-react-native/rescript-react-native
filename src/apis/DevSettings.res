type handler = unit => unit
type reason = string
type title = string

@scope("DevSettings") @module("react-native")
external addMenuItem: (title, handler) => unit = "addMenuItem"

@scope("DevSettings") @module("react-native")
external reload: (~reason: reason=?) => unit = "reload"
