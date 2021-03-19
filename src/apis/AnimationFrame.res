type requestID

@val
external request: (unit => unit) => requestID = "requestAnimationFrame"
@val external cancel: requestID => unit = "cancelAnimationFrame"
