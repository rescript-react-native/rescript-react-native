// Methods of virtualized list elements (`[> #virtualizedList]`)

type scrollToIndexParams = {
  index: int,
  animated?: bool,
  viewOffset?: float,
  viewPosition?: float,
}

@send
external scrollToIndex: (DOMAPI.element<[> #virtualizedList]>, scrollToIndexParams) => unit =
  "scrollToIndex"

type scrollToItemParams<'item> = {
  item: 'item,
  viewPosition?: float,
  animated?: bool,
}

@send
external scrollToItem: (DOMAPI.element<[> #virtualizedList]>, scrollToItemParams<'item>) => unit =
  "scrollToItem"

type scrollToOffsetParams = {
  offset: float,
  animated?: bool,
}

@send
external scrollToOffset: (DOMAPI.element<[> #virtualizedList]>, scrollToOffsetParams) => unit =
  "scrollToOffset"

@send external recordInteraction: DOMAPI.element<[> #virtualizedList]> => unit = "recordInteraction"
