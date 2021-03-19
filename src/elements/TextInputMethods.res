module Make = (
  T: {
    type t
  },
) => {
  @send external isFocused: T.t => bool = "isFocused"
  @send external clear: T.t => unit = "clear"
}
