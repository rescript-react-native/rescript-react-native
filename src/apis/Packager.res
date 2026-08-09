// Metro resolves `require("./image.png")` to a numeric asset id.
type required = float

@val external require: string => required = "require"
