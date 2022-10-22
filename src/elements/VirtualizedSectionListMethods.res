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

  @obj // @deprecated("Directly create record instead")
  external scrollToLocationParams: (
    ~animated: bool=?,
    ~itemIndex: int,
    ~sectionIndex: int,
    ~viewOffset: int=?,
    ~viewPosition: float=?,
    unit,
  ) => scrollToLocationParams = ""

  @send
  external scrollToLocation: (T.t, scrollToLocationParams) => unit = "scrollToLocation"
}
