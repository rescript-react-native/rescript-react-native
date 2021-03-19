module Make = (
  T: {
    type t
  },
) => {
  type scrollToLocationParams
  @obj
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
