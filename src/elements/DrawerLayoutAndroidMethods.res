module Make = (
  T: {
    type t
  },
) => {
  @send external openDrawer: T.t => unit = "openDrawer"
  @send external closeDrawer: T.t => unit = "closeDrawer"
}
