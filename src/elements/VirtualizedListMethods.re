module Make = (T: {type t;}) => {
  type scrollToIndexParams;
  [@bs.obj]
  external scrollToIndexParams:
    (
      ~viewOffset: float=?,
      ~viewPosition: float=?,
      ~animated: bool=?,
      ~index: int,
      unit
    ) =>
    scrollToIndexParams;
  [@bs.send]
  external scrollToIndex: (T.t, scrollToIndexParams) => unit = "scrollToIndex";

  type scrollToItemParams('item);
  [@bs.obj]
  external scrollToItemParams:
    (~viewPosition: float=?, ~animated: bool=?, ~item: 'item, unit) =>
    scrollToIndexParams;
  [@bs.send]
  external scrollToItem: (T.t, scrollToItemParams('item)) => unit =
    "scrollToItem";

  type scrollToOffsetParams;
  [@bs.obj]
  external scrollToOffsetParams:
    (~animated: bool=?, ~offset: float, unit) => scrollToOffsetParams;
  [@bs.send]
  external scrollToOffset: (T.t, scrollToOffsetParams) => unit =
    "scrollToOffset";

  [@bs.send] external recordInteraction: T.t => unit = "recordInteraction";
};
