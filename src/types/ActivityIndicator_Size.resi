type t

@inline("small")
let small: t

@inline("large")
let large: t

external exact: float => t = "%identity"
