module Make = (
  T: {
    type t
  },
) => {
  @send external openDrawer: (T.t, unit) => unit = "openDrawer"
  @send external closeDrawer: (T.t, unit) => unit = "closeDrawer"
}
