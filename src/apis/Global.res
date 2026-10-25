@val external __DEV__: bool = "__DEV__"

@scope("global") @val
external hermesInternal: option<{..}> = "HermesInternal"

type immediateId

@val external setImmediate: (unit => unit) => immediateId = "setImmediate"
@val external clearImmediate: immediateId => unit = "clearImmediate"

@val external queueMicrotask: (unit => unit) => unit = "queueMicrotask"

type idleCallbackId

type idleDeadline = {
  didTimeout: bool,
  timeRemaining: unit => float,
}

type idleRequestOptions = {timeout?: float}

@val
external requestIdleCallback: (
  idleDeadline => unit,
  ~options: idleRequestOptions=?,
) => idleCallbackId = "requestIdleCallback"
@val external cancelIdleCallback: idleCallbackId => unit = "cancelIdleCallback"
