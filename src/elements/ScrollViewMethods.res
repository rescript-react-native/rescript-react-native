module Make = (
  T: {
    type t
  },
) => {
  type scrollToEndOptions = {animated?: bool, duration?: float}

  @send external scrollToEnd: (T.t, ~options: scrollToEndOptions=?) => unit = "scrollToEnd"

  @send
  external flashScrollIndicators: T.t => unit = "flashScrollIndicators"

  @send
  external setNativeProps: (T.t, {..}) => unit = "setNativeProps"
}
