type t = [#dark | #light]

// `#auto` follows the system color scheme
type override = [t | #auto]

@module("react-native") @scope("Appearance") @return(nullable)
external getColorScheme: unit => option<t> = "getColorScheme"

@module("react-native") @scope("Appearance")
external setColorScheme: override => unit = "setColorScheme"

@module("react-native") @return(nullable)
external useColorScheme: unit => option<t> = "useColorScheme"

type preferences = {colorScheme: nullable<t>}

@module("react-native") @scope("Appearance")
external addChangeListener: (preferences => unit) => EventSubscription.t = "addChangeListener"
