module Make = (
  T: {
    type t
  },
) => {
  type scrollToIndexParams = {
    index: int,
    animated?: bool,
    viewOffset?: float,
    viewPosition?: float,
  }

  @obj // @deprecated("Directly create record instead")
  external scrollToIndexParams: (
    ~viewOffset: float=?,
    ~viewPosition: float=?,
    ~animated: bool=?,
    ~index: int,
    unit,
  ) => scrollToIndexParams = ""
  @send
  external scrollToIndex: (T.t, scrollToIndexParams) => unit = "scrollToIndex"

  type scrollToItemParams<'item> = {
    item: 'item,
    viewPosition?: float,
    animated?: bool,
  }

  @obj // @deprecated("Directly create record instead")
  external scrollToItemParams: (
    ~viewPosition: float=?,
    ~animated: bool=?,
    ~item: 'item,
    unit,
  ) => scrollToItemParams<'item> = ""
  @send
  external scrollToItem: (T.t, scrollToItemParams<'item>) => unit = "scrollToItem"

  type scrollToOffsetParams = {
    offset: float,
    animated?: bool,
  }

  @obj // @deprecated("Directly create record instead")
  external scrollToOffsetParams: (~animated: bool=?, ~offset: float, unit) => scrollToOffsetParams =
    ""
  @send
  external scrollToOffset: (T.t, scrollToOffsetParams) => unit = "scrollToOffset"

  @send external recordInteraction: T.t => unit = "recordInteraction"
}
