module Make = (T: {type t;}) => {
  type scrollToLocationParams;
  [@bs.obj]
  external scrollToLocationParams:
    (
      ~animated: bool=?,
      ~itemIndex: int,
      ~sectionIndex: int,
      ~viewOffset: int=?,
      ~viewPosition: float=?,
      unit
    ) =>
    scrollToLocationParams;

  [@bs.send]
  external scrollToLocation: (T.t, scrollToLocationParams) => unit =
    "scrollToLocation";
};
