module Make = (
  T: {
    type t
  },
) => {
  type scrollToEndOptions = {animated?: bool, duration?: float}

  // multiple externals
  @send external scrollToEnd: T.t => unit = "scrollToEnd"

  // multiple externals
  @send
  external scrollToEndWithOptions: (T.t, scrollToEndOptions) => unit = "scrollToEnd"

  @send
  external flashScrollIndicators: T.t => unit = "flashScrollIndicators"

  @send
  external setNativeProps: (T.t, {..}) => unit = "setNativeProps"
}
