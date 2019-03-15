open ScrollViewProps;

module type FlatListComponent = {
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
    (
      ReasonReact.reactRef,
      ~item: 'item,
      ~animated: bool=?,
      ~viewPosition: int=?,
      unit
    ) =>
    unit;

  let scrollToOffset:
    (ReasonReact.reactRef, ~offset: float=?, ~animated: bool=?, unit) => unit;

  [@bs.send] external recordInteraction: ReasonReact.reactRef => unit = "";

  type renderBag('item) = {
    item: 'item,
    index: int,
  };

  type renderItem('item);

  let renderItem:
    (renderBag('item) => ReasonReact.reactElement) => renderItem('item);

  type separatorComponent('item);

  type separatorProps('item) = {
    highlighted: bool,
    leadingItem: option('item),
  };

  let separatorComponent:
    (separatorProps('item) => ReasonReact.reactElement) =>
    separatorComponent('item);

  let make:
    (
      ~data: array('item),
      ~renderItem: renderItem('item),
      ~keyExtractor: ('item, int) => string,
      ~itemSeparatorComponent: separatorComponent('item)=?,
      ~bounces: bool=?,
      ~listEmptyComponent: ReasonReact.reactElement=?,
      ~listFooterComponent: ReasonReact.reactElement=?,
      ~listFooterComponentStyle: Style.t=?,
      ~listHeaderComponent: ReasonReact.reactElement=?,
      ~listHeaderComponentStyle: Style.t=?,
      ~columnWrapperStyle: Style.t=?,
      ~extraData: 'any=?,
      ~getItemLayout: (option(array('item)), int) =>
                      {
                        .
                        "length": int,
                        "offset": int,
                        "index": int,
                      }
                        =?,
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
                                   array({
                                     .
                                     "item": 'item,
                                     "key": string,
                                     "index": Js.undefined(int),
                                     "isViewable": bool,
                                     "section": Js.t({.}),
                                   }),
                                 "changed":
                                   array({
                                     .
                                     "item": 'item,
                                     "key": string,
                                     "index": Js.undefined(int),
                                     "isViewable": bool,
                                     "section": Js.t({.}),
                                   }),
                               }
                                 =?,
      ~overScrollMode: overScrollMode=?,
      ~pagingEnabled: bool=?,
      ~refreshControl: ReasonReact.reactElement=?,
      ~refreshing: bool=?,
      ~removeClippedSubviews: bool=?,
      ~scrollEnabled: bool=?,
      ~stickyHeaderIndices: list(int)=?,
      ~showsHorizontalScrollIndicator: bool=?,
      ~showsVerticalScrollIndicator: bool=?,
      ~windowSize: int=?,
      ~maxToRenderPerBatch: int=?,
      ~viewabilityConfig: Js.t({.})=?,
      ~scrollEventThrottle: int=?,
      ~onScroll: RNEvent.NativeScrollEvent.t => unit=?,
      ~onScrollBeginDrag: RNEvent.NativeScrollEvent.t => unit=?,
      ~onScrollEndDrag: RNEvent.NativeScrollEvent.t => unit=?,
      ~onMomentumScrollBegin: RNEvent.NativeScrollEvent.t => unit=?,
      ~onMomentumScrollEnd: RNEvent.NativeScrollEvent.t => unit=?,
      ~style: Style.t=?,
      ~contentInsetAdjustmentBehavior: contentInsetAdjustmentBehavior=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent = (Impl: View.Impl) : FlatListComponent => {
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

  type jsSeparatorProps('item) = {
    .
    "highlighted": bool,
    "leadingItem": Js.Undefined.t('item),
  };

  type separatorProps('item) = {
    highlighted: bool,
    leadingItem: option('item),
  };

  type separatorComponent('item) =
    jsSeparatorProps('item) => ReasonReact.reactElement;

  let separatorComponent =
      (
        reSeparatorComponent:
          separatorProps('item) => ReasonReact.reactElement,
      )
      : separatorComponent('item) =>
    (jsSeparatorProps: jsSeparatorProps('item)) =>
      reSeparatorComponent({
        highlighted: jsSeparatorProps##highlighted,
        leadingItem: Js.Undefined.toOption(jsSeparatorProps##leadingItem),
      });

  let make =
      (
        ~data: array('item),
        ~renderItem: renderItem('item),
        ~keyExtractor: ('item, int) => string,
        ~itemSeparatorComponent: option(separatorComponent('item))=?,
        ~bounces=?,
        ~listEmptyComponent=?,
        ~listFooterComponent=?,
        ~listFooterComponentStyle=?,
        ~listHeaderComponent=?,
        ~listHeaderComponentStyle=?,
        ~columnWrapperStyle=?,
        ~extraData=?,
        ~getItemLayout=?,
        ~horizontal=?,
        ~initialNumToRender=?,
        ~initialScrollIndex=?,
        ~inverted=?,
        ~numColumns=?,
        ~onEndReached=?,
        ~onEndReachedThreshold=?,
        ~onRefresh=?,
        ~onViewableItemsChanged=?,
        ~overScrollMode=?,
        ~pagingEnabled=?,
        ~refreshControl=?,
        ~refreshing=?,
        ~removeClippedSubviews=?,
        ~scrollEnabled=?,
        ~stickyHeaderIndices=?,
        ~showsHorizontalScrollIndicator=?,
        ~showsVerticalScrollIndicator=?,
        ~windowSize=?,
        ~maxToRenderPerBatch=?,
        ~viewabilityConfig=?,
        ~scrollEventThrottle=?,
        ~onScroll=?,
        ~onScrollBeginDrag=?,
        ~onScrollEndDrag=?,
        ~onMomentumScrollBegin=?,
        ~onMomentumScrollEnd=?,
        ~style=?,
        ~contentInsetAdjustmentBehavior=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props={
        "bounces": bounces,
        "ItemSeparatorComponent": itemSeparatorComponent,
        "ListEmptyComponent": listEmptyComponent,
        "ListFooterComponent": listFooterComponent,
        "ListFooterComponentStyle": listFooterComponentStyle,
        "ListHeaderComponent": listHeaderComponent,
        "ListHeaderComponentStyle": listHeaderComponentStyle,
        "columnWrapperStyle": columnWrapperStyle,
        "data": data,
        "extraData": extraData,
        "getItemLayout":
          getItemLayout->Belt.Option.map((f, data, index) =>
            f(Js.Undefined.toOption(data), index)
          ),
        "horizontal": horizontal,
        "initialNumToRender": initialNumToRender,
        "initialScrollIndex": initialScrollIndex,
        "inverted": inverted,
        "keyExtractor": keyExtractor,
        "numColumns": numColumns,
        "onEndReached": onEndReached,
        "onEndReachedThreshold": onEndReachedThreshold,
        "onRefresh": onRefresh,
        "onViewableItemsChanged": onViewableItemsChanged,
        "overScrollMode": overScrollMode->Belt.Option.map(overScrollModeToJs),
        "pagingEnabled": pagingEnabled,
        "refreshControl": refreshControl,
        "refreshing": refreshing,
        "renderItem": renderItem,
        "removeClippedSubviews": removeClippedSubviews,
        "scrollEnabled": scrollEnabled,
        "stickyHeaderIndices":
          stickyHeaderIndices->Belt.Option.map(Array.of_list),
        "showsHorizontalScrollIndicator": showsHorizontalScrollIndicator,
        "showsVerticalScrollIndicator": showsVerticalScrollIndicator,
        "windowSize": windowSize,
        "maxToRenderPerBatch": maxToRenderPerBatch,
        "viewabilityConfig": viewabilityConfig,
        "scrollEventThrottle": scrollEventThrottle,
        "onScroll": onScroll,
        "onScrollBeginDrag": onScrollBeginDrag,
        "onScrollEndDrag": onScrollEndDrag,
        "onMomentumScrollBegin": onMomentumScrollBegin,
        "onMomentumScrollEnd": onMomentumScrollEnd,
        "style": style,
        "contentInsetAdjustmentBehavior":
          contentInsetAdjustmentBehavior->Belt.Option.map(
            contentInsetAdjustmentBehaviorToJs,
          ),
      },
    );
};

include CreateComponent({
  [@bs.module "react-native"]
  external view: ReasonReact.reactClass = "FlatList";
});
