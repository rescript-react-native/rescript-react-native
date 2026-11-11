type t

@new @module("react-native")
external make: unit => t = "EventEmitter"

@send
external addListener: (t, string, 'a => unit, ~context: 'context=?) => EventSubscription.t =
  "addListener"

@send external emit: (t, string, 'a) => unit = "emit"

@send
external removeAllListeners: (t, ~eventType: string=?) => unit = "removeAllListeners"

@send external listenerCount: (t, string) => int = "listenerCount"
