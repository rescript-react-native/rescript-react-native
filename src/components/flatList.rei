let scrollToEnd: (ReasonReact.reactRef, ~animated: bool) => unit;

let scrollToIndex:
  (
    ReasonReact.reactRef,
    ~index: int,
    ~animated: bool=?,
    ~viewOffset: int=?,
    ~viewPosition: int=?,
    unit
  ) =>
  unit;

let scrollToItem:
  (ReasonReact.reactRef, ~item: 'item, ~animated: bool=?, ~viewPosition: int=?, unit) => unit;

let scrollToOffset: (ReasonReact.reactRef, ~offset: int=?, ~animated: bool=?, unit) => unit;

[@bs.send] external recordInteraction : ReasonReact.reactRef => unit = "";

type renderBag('item) = {
  item: 'item,
  index: int
};

type renderItem('item);

let renderItem: (renderBag('item) => ReasonReact.reactElement) => renderItem('item);

type separatorComponent('item);

type separatorProps('item) = {
  highlighted: bool,
  leadingItem: option('item)
};

let separatorComponent:
  (separatorProps('item) => ReasonReact.reactElement) => separatorComponent('item);

let make:
  (
    ~data: array('item),
    ~renderItem: renderItem('item),
    ~keyExtractor: ('item, int) => string,
    ~itemSeparatorComponent: separatorComponent('item)=?,
    ~bounces: bool=?,
    ~listFooterComponent: ReasonReact.reactElement=?,
    ~listHeaderComponent: ReasonReact.reactElement=?,
    ~columnWrapperStyle: Style.t=?,
    ~extraData: 'any=?,
    ~getItemLayout: (option(array('item)), int) => {. "length": int, "offset": int, "index": int}=?,
    ~horizontal: bool=?,
    ~initialNumToRender: int=?,
    ~initialScrollIndex: int=?,
    ~inverted: bool=?,
    ~numColumns: 'int=?,
    ~onEndReached: {. "distanceFromEnd": float} => unit=?,
    ~onEndReachedThreshold: float=?,
    ~onRefresh: unit => unit=?,
    ~onViewableItemsChanged: {
                               .
                               "viewableItems":
                                 array(
                                   {
                                     .
                                     "item": 'item,
                                     "key": string,
                                     "index": Js.undefined(int),
                                     "isViewable": bool,
                                     "section": Js.t({.})
                                   }
                                 ),
                               "changed":
                                 array(
                                   {
                                     .
                                     "item": 'item,
                                     "key": string,
                                     "index": Js.undefined(int),
                                     "isViewable": bool,
                                     "section": Js.t({.})
                                   }
                                 )
                             }
                               =?,
    ~overScrollMode: [ | `auto | `always | `never]=?,
    ~pagingEnabled: bool=?,
    ~refreshing: bool=?,
    ~removeClippedSubviews: bool=?,
    ~scrollEnabled: bool=?,
    ~showsHorizontalScrollIndicator: bool=?,
    ~showsVerticalScrollIndicator: bool=?,
    ~windowSize: int=?,
    ~maxToRenderPerBatch: int=?,
    ~viewabilityConfig: Js.t({.})=?,
    ~onScroll: RNEvent.NativeScrollEvent.t => unit=?,
    ~style: Style.t=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps, unit);
