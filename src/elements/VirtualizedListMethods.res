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

  @send
  external scrollToIndex: (T.t, scrollToIndexParams) => unit = "scrollToIndex"

  type scrollToItemParams<'item> = {
    item: 'item,
    viewPosition?: float,
    animated?: bool,
  }

  @send
  external scrollToItem: (T.t, scrollToItemParams<'item>) => unit = "scrollToItem"

  type scrollToOffsetParams = {
    offset: float,
    animated?: bool,
  }

  @send
  external scrollToOffset: (T.t, scrollToOffsetParams) => unit = "scrollToOffset"

  @send external recordInteraction: T.t => unit = "recordInteraction"
}
