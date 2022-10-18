type t = [#dark | #light]

@module("react-native") @scope("Appearance") @return(nullable)
external getColorScheme: unit => option<t> = "getColorScheme"

@module("react-native") @return(nullable)
external useColorScheme: unit => option<t> = "useColorScheme"

@module("react-native") @scope("Appearance")
external addChangeListener: (unit => unit) => EventSubscription.t = "addChangeListener"
