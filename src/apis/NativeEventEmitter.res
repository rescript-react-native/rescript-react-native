type t

@new @module("react-native")
external make: 'nativeModule => t = "NativeEventEmitter"

@send
external addListener: (t, string, 'a => unit) => EventSubscription.t = "addListener"

@send
external removeAllListeners: (t, string) => unit = "removeAllListeners"

@send external listenerCount: (t, string) => unit = "listenerCount"
