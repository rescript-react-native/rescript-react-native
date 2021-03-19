module Make = (
  T: {
    type t
  },
) => {
  @send
  external setOpacityTo: (T.t, ~value: float, ~duration: float) => unit = "setOpacityTo"
}
