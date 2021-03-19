module Make = (
  T: {
    type t
  },
) => {
  @send external setPage: (T.t, int) => unit = "setPage"
  @send
  external setPageWithoutAnimation: (T.t, int) => unit = "setPageWithoutAnimation"
}
