type t

type subscription

@new @module("react-native")
external make: 'nativeModule => t = "NativeEventEmitter"

@send
external addListener: (t, string, 'a => unit) => subscription = "addListener"

@send
external removeAllListeners: (t, string) => unit = "removeAllListeners"

@send
external removeSubscription: (t, subscription) => unit = "removeSubscription"

@send external listenerCount: (t, string) => unit = "listenerCount"

module Subscription = {
  @send external remove: (subscription, unit) => unit = "remove"
}
