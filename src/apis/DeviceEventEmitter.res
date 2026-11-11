@module("react-native") @scope("DeviceEventEmitter")
external addListener: (string, 'a => unit, ~context: 'context=?) => EventSubscription.t =
  "addListener"

@module("react-native") @scope("DeviceEventEmitter")
external emit: (string, 'a) => unit = "emit"

@module("react-native") @scope("DeviceEventEmitter")
external removeAllListeners: (~eventType: string=?) => unit = "removeAllListeners"

@module("react-native") @scope("DeviceEventEmitter")
external listenerCount: string => int = "listenerCount"
