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

  @deprecated("Directly create record instead") @obj
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
