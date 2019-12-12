module Make = (T: {type t;}) => {
  type scrollToIndexParams = {
    viewOffset: option(float),
    viewPosition: option(float),
    animated: option(bool),
    index: int,
  };
  // [@bs.obj]
  // external scrollToIndexParams:
  //   (
  //     ~viewOffset: float=?,
  //     ~viewPosition: float=?,
  //     ~animated: bool=?,
  //     ~index: int,
  //     unit
  //   ) =>
  //   scrollToIndexParams =
  //   "";
  [@bs.send]
  external scrollToIndex: (T.t, scrollToIndexParams) => unit = "scrollToIndex";

  type scrollToItemParams('item) = {
    viewPosition: option(float),
    animated: option(bool),
    item: 'item,
  };
  // [@bs.obj]
  // external scrollToItemParams:
  //   (~viewPosition: float=?, ~animated: bool=?, ~item: 'item, unit) =>
  //   scrollToIndexParams =
  //   "";
  [@bs.send]
  external scrollToItem: (T.t, scrollToItemParams('item)) => unit =
    "scrollToItem";

  type scrollToOffsetParams = {
    animated: option(bool),
    offset: float,
  };

  [@bs.send]
  external scrollToOffset: (T.t, scrollToOffsetParams) => unit =
    "scrollToOffset";

  [@bs.send] external recordInteraction: T.t => unit = "recordInteraction";

  [@bs.send]
  external flashScrollIndicators: T.t => unit = "flashScrollIndicators";
};
