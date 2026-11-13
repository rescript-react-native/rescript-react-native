// the whole module is deprecated, its own uses of `requestID` must not warn
@@warning("-3")

@deprecated("Use `Global.animationFrameId` instead.") @notUndefined
type requestID

@deprecated("Use `Global.requestAnimationFrame` instead.") @val
external request: (unit => unit) => requestID = "requestAnimationFrame"

@deprecated("Use `Global.cancelAnimationFrame` instead.") @val
external cancel: requestID => unit = "cancelAnimationFrame"
