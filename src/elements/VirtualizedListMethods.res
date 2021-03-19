module Make = (
  T: {
    type t
  },
) => {
  type scrollToIndexParams
  @obj
  external scrollToIndexParams: (
    ~viewOffset: float=?,
    ~viewPosition: float=?,
    ~animated: bool=?,
    ~index: int,
    unit,
  ) => scrollToIndexParams = ""
  @send
  external scrollToIndex: (T.t, scrollToIndexParams) => unit = "scrollToIndex"

  type scrollToItemParams<'item>
  @obj
  external scrollToItemParams: (
    ~viewPosition: float=?,
    ~animated: bool=?,
    ~item: 'item,
    unit,
  ) => scrollToItemParams<'item> = ""
  @send
  external scrollToItem: (T.t, scrollToItemParams<'item>) => unit = "scrollToItem"

  type scrollToOffsetParams
  @obj
  external scrollToOffsetParams: (~animated: bool=?, ~offset: float, unit) => scrollToOffsetParams =
    ""
  @send
  external scrollToOffset: (T.t, scrollToOffsetParams) => unit = "scrollToOffset"

  @send external recordInteraction: T.t => unit = "recordInteraction"
}
