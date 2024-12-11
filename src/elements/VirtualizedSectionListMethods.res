module Make = (
  T: {
    type t
  },
) => {
  type scrollToLocationParams = {
    itemIndex: int,
    sectionIndex: int,
    animated?: bool,
    viewOffset?: int,
    viewPosition?: float,
  }

  @send
  external scrollToLocation: (T.t, scrollToLocationParams) => unit = "scrollToLocation"
}
