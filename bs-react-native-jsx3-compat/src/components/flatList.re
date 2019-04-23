[@bs.send]
external _scrollToEnd: (ReasonReact.reactRef, {. "animated": bool}) => unit =
  "scrollToEnd";

let scrollToEnd = (ref, ~animated) =>
  _scrollToEnd(ref, {"animated": animated});

[@bs.send]
external _scrollToIndex:
  (
    ReasonReact.reactRef,
    {
      .
      "index": int,
      "viewOffset": Js.undefined(int),
      "viewPosition": Js.undefined(int),
      "animated": Js.undefined(bool),
    }
  ) =>
  unit =
  "_scrollToIndex";

let scrollToIndex =
    (ref, ~index, ~animated=?, ~viewOffset=?, ~viewPosition=?, ()) =>
  _scrollToIndex(
    ref,
    Js.Undefined.{
      "index": index,
      "viewOffset": fromOption(viewOffset),
      "viewPosition": fromOption(viewPosition),
      "animated": fromOption(animated),
    },
  );

[@bs.send]
external _scrollToItem:
  (
    ReasonReact.reactRef,
    {
      .
      "item": 'item,
      "viewPosition": Js.undefined(int),
      "animated": Js.undefined(bool),
    }
  ) =>
  unit =
  "_scrollToIndex";

let scrollToItem = (ref, ~item, ~animated=?, ~viewPosition=?, ()) =>
  _scrollToItem(
    ref,
    Js.Undefined.{
      "item": item,
      "viewPosition": fromOption(viewPosition),
      "animated": fromOption(animated),
    },
  );

[@bs.send]
external _scrollToOffset:
  (
    ReasonReact.reactRef,
    {
      .
      "offset": Js.undefined(float),
      "animated": Js.undefined(bool),
    }
  ) =>
  unit =
  "scrollToOffset";

let scrollToOffset = (ref, ~offset=?, ~animated=?, ()) =>
  _scrollToOffset(
    ref,
    Js.Undefined.{
      "offset": fromOption(offset),
      "animated": fromOption(animated),
    },
  );

[@bs.send] external recordInteraction: ReasonReact.reactRef => unit = "";

type jsRenderBag('item) = {
  .
  "item": 'item,
  "index": int,
};

type renderBag('item) = {
  item: 'item,
  index: int,
};

type renderItem('item) = jsRenderBag('item) => ReasonReact.reactElement;

let renderItem =
    (reRenderItem: renderBag('item) => ReasonReact.reactElement)
    : renderItem('item) =>
  (jsRenderBag: jsRenderBag('item)) =>
    reRenderItem({item: jsRenderBag##item, index: jsRenderBag##index});

type jsSeparatorProps('item) =
  ReactNative.FlatList.separatorComponentProps('item);

type separatorProps('item) = {
  highlighted: bool,
  leadingItem: option('item),
};

type separatorComponent('item) =
  jsSeparatorProps('item) => ReasonReact.reactElement;

let separatorComponent =
    (reSeparatorComponent: separatorProps('item) => ReasonReact.reactElement)
    : separatorComponent('item) =>
  (jsSeparatorProps: jsSeparatorProps('item)) =>
    reSeparatorComponent({
      highlighted: jsSeparatorProps##highlighted,
      leadingItem: jsSeparatorProps##leadingItem,
    });

type overScrollMode = [ | `always | `never | `auto];

type contentInsetAdjustmentBehavior = [
  | `automatic
  | `scrollableAxes
  | `never
  | `always
];

[@react.component]
let make =
    (
      ~data: array('item),
      ~renderItem: renderItem('item),
      ~keyExtractor: ('item, int) => string,
      ~itemSeparatorComponent: option(separatorComponent('item))=?,
      ~bounces: option(bool)=?,
      ~listEmptyComponent: option(React.element)=?,
      ~listFooterComponent: option(React.element)=?,
      ~listFooterComponentStyle: option(Style.t)=?,
      ~listHeaderComponent: option(React.element)=?,
      ~listHeaderComponentStyle: option(Style.t)=?,
      ~columnWrapperStyle: option(Style.t)=?,
      ~extraData: option('any)=?,
      ~getItemLayout:
         option(
           (array('item), int) => ReactNative.VirtualizedList.itemLayout,
         )=?,
      ~horizontal: option(bool)=?,
      ~initialNumToRender: option(int)=?,
      ~initialScrollIndex: option(int)=?,
      ~inverted: option(bool)=?,
      ~numColumns: option('int)=?,
      ~onEndReached:
         option(ReactNative.VirtualizedList.onEndReachedParams => unit)=?,
      ~onEndReachedThreshold: option(float)=?,
      ~onRefresh: option(unit => unit)=?,
      ~onViewableItemsChanged:
         option(
           ReactNative.VirtualizedList.viewableItemsChanged('item) => unit,
         )=?,
      ~overScrollMode: option(overScrollMode)=?,
      ~pagingEnabled: option(bool)=?,
      ~refreshControl: option(React.element)=?,
      ~refreshing: option(bool)=?,
      ~removeClippedSubviews: option(bool)=?,
      ~scrollEnabled: option(bool)=?,
      ~stickyHeaderIndices: option(list(int))=?,
      ~showsHorizontalScrollIndicator: option(bool)=?,
      ~showsVerticalScrollIndicator: option(bool)=?,
      ~windowSize: option(int)=?,
      ~maxToRenderPerBatch: option(int)=?,
      ~viewabilityConfig: option(Js.t({.}))=?,
      ~scrollEventThrottle: option(int)=?,
      ~onScroll: option(RNEvent.NativeScrollEvent.t => unit)=?,
      ~onScrollBeginDrag: option(RNEvent.NativeScrollEvent.t => unit)=?,
      ~onScrollEndDrag: option(RNEvent.NativeScrollEvent.t => unit)=?,
      ~onMomentumScrollBegin: option(RNEvent.NativeScrollEvent.t => unit)=?,
      ~onMomentumScrollEnd: option(RNEvent.NativeScrollEvent.t => unit)=?,
      ~style: option(Style.t)=?,
      ~contentInsetAdjustmentBehavior: option(contentInsetAdjustmentBehavior)=?,
      _,
    ) =>
  <ReactNative.FlatList
    ?bounces
    _ItemSeparatorComponent=?itemSeparatorComponent
    _ListEmptyComponent=?{listEmptyComponent->Belt.Option.map((x, ()) => x)}
    _ListFooterComponent=?{listFooterComponent->Belt.Option.map((x, ()) => x)}
    _ListFooterComponentStyle=?listFooterComponentStyle
    _ListHeaderComponent=?{listHeaderComponent->Belt.Option.map((x, ()) => x)}
    _ListHeaderComponentStyle=?listHeaderComponentStyle
    ?columnWrapperStyle
    data
    ?extraData
    ?horizontal
    ?initialNumToRender
    ?initialScrollIndex
    ?inverted
    keyExtractor
    ?numColumns
    ?onEndReached
    ?onEndReachedThreshold
    ?onRefresh
    ?onViewableItemsChanged
    ?overScrollMode
    ?pagingEnabled
    ?refreshControl
    ?refreshing
    renderItem
    ?removeClippedSubviews
    ?scrollEnabled
    getItemLayout=?{
      getItemLayout->Belt.Option.map((f, data, index) => f(data, index))
    }
    stickyHeaderIndices=?{stickyHeaderIndices->Belt.Option.map(Array.of_list)}
    ?showsHorizontalScrollIndicator
    ?showsVerticalScrollIndicator
    ?windowSize
    ?maxToRenderPerBatch
    viewabilityConfig=?{viewabilityConfig->Belt.Option.map(Obj.magic)}
    ?scrollEventThrottle
    ?onScroll
    ?onScrollBeginDrag
    ?onScrollEndDrag
    ?onMomentumScrollBegin
    ?onMomentumScrollEnd
    ?style
    ?contentInsetAdjustmentBehavior
  />;
