/************* */
/**
    {3 Example of use}
    In order to render a FlatList {{:https://facebook.github.io/react-native/docs/flatlist}} in React Native you need to provide three props:
    - [data]
    - [renderItem]
    - [keyExtractor]

   {4 default}
   {[
      type contact = {
        id: int,
        name: string,
        count: int,
      };
      type myData = array(contact);
      let myData = [|
        {id: 1, name: "Davin Roth", count: 645},
        {id: 2, name: "Milton Walsh", count: 12},
      |];

      let myKeyExtractor = (item, _index) => string_of_int(item.id);

      let renderMyItem =
        FlatList.renderItem((contact: FlatList.renderBag(contact)) =>
          <View> <Text> (ReasonReact.string(contact.item.name)) </Text> </View>
        );

      let component = ReasonReact.statelessComponent("MyComponent");

      let make = _children => {
        ...component,
        render: _self =>
          <FlatList
            data=myData
            keyExtractor=myKeyExtractor
            renderItem=renderMyItem
          />,
      };

   ]}

  {3 Props}
  {4 data}
  {[
    data: array('item)
  ]}
  {4 renderItem}
  {[
    renderItem: renderItem('item)
  ]}
  {4 keyExtractor}
  {[
    keyExtractor: ('item, int) => string
  ]}
  {4 itemSeparatorComponent}
  {[
    itemSeparatorComponent: separatorComponent('item)=?
  ]}
  {{:#val-separatorComponent} separatorComponent reference}
  {4 bounces}
  {[
    bounces: bool=?
  ]}
  {4 listFooterComponent}
  {[
    listFooterComponent: React.element=?
  ]}
  {4 listHeaderComponent}
  {[
    listHeaderComponent: React.element=?
  ]}
  {4 listEmptyComponent}
  {[
    listEmptyComponent: React.element=?
  ]}
  {4 columnWrapperStyle}
  {[
    columnWrapperStyle: Style.t=?
  ]}
  {4 extraData}
  {[
    extraData: 'any=?
  ]}
  {4 getItemLayout}
  {[
    getItemLayout: (option(array('item)), int) => {
      .
      "length": int,
      "offset": int,
      "index": int,
    }=?
  ]}
  {4 horizontal}
  {[
    horizontal: bool=?
  ]}
  {4 initialNumToRender}
  {[
    initialNumToRender: int=?
  ]}
  {4 initialScrollIndex}
  {[
    initialScrollIndex: int=?
  ]}
  {4 inverted}
  {[
    inverted: bool=?
  ]}
  {4 numColumns}
  {[
    numColumns: 'int=?
  ]}
  {4 onEndReached}
  {[
    onEndReached: {. "distanceFromEnd": float} => unit=?
  ]}
  {4 onEndReachedThreshold}
  {[
    onEndReachedThreshold: float=?
  ]}
  {4 onRefresh}
  {[
    onRefresh: unit => unit=?
  ]}
  {4 onViewableItemsChanged}
  {[
    onViewableItemsChanged: {
      .
      "viewableItems":
        array(
          {
            .
            "item": 'item,
            "key": string,
            "index": Js.undefined(int),
            "isViewable": bool,
            "section": Js.t({.}),
          },
        ),
      "changed":
        array(
          {
            .
            "item": 'item,
            "key": string,
            "index": Js.undefined(int),
            "isViewable": bool,
            "section": Js.t({.}),
          },
        ),
    }=?
  ]}
  {4 overScrollMode}
  {[
    overScrollMode: [
      | `auto
      | `always
      | `never
    ]=?
  ]}
  {4 pagingEnabled}
  {[
    pagingEnabled: bool=?
  ]}
  {4 refreshControl}
  {[
    refreshControl: React.element=?
  ]}
  {4 refreshing}
  {[
    refreshing: bool=?
  ]}
  {4 removeClippedSubviews}
  {[
    removeClippedSubviews: bool=?
  ]}
  {4 scrollEnabled}
  {[
    scrollEnabled: bool=?
  ]}
  {4 stickyHeaderIndices}
  {[
    stickyHeaderIndices: list(int)=?
  ]}
  {4 showsHorizontalScrollIndicator}
  {[
    showsHorizontalScrollIndicator: bool=?
  ]}
  {4 showsVerticalScrollIndicator}
  {[
    showsVerticalScrollIndicator: bool=?
  ]}
  {4 windowSize}
  {[
    windowSize: int=?
  ]}
  {4 maxToRenderPerBatch}
  {[
    maxToRenderPerBatch: int=?
  ]}
  {4 viewabilityConfig}
  {[
    viewabilityConfig: Js.t({.})=?
  ]}
  {4 onScroll}
  {[
    onScroll: RNEvent.NativeScrollEvent.t => unit=?
  ]}
  Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeScrollEvent/} [RNEvent.NativeScrollEvent]}

  {4 onScrollBeginDrag}
  {[
    ~onScrollBeginDrag: RNEvent.NativeScrollEvent.t => unit=?,
  ]}
  Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeScrollEvent/} [RNEvent.NativeScrollEvent]}

  {4 onScrollEndDrag}
  {[
    ~onScrollEndDrag: RNEvent.NativeScrollEvent.t => unit=?,
  ]}
  Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeScrollEvent/} [RNEvent.NativeScrollEvent]}

  {4 onMomentumScrollBegin}
  {[
    ~onMomentumScrollBegin: RNEvent.NativeScrollEvent.t => unit=?,
  ]}
  Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeScrollEvent/} [RNEvent.NativeScrollEvent]}

  {4 onMomentumScrollEnd}
  {[
    ~onMomentumScrollEnd: RNEvent.NativeScrollEvent.t => unit=?,
  ]}
  Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeScrollEvent/} [RNEvent.NativeScrollEvent]}

  {4 style}
  {[
    style: Style.t=?
  ]}
  {4 contentInsetAdjustmentBehavior}
  {[
    ~contentInsetAdjustmentBehavior: [
      | `automatic
      | `scrollableAxes
      | `never
      | `always
    ]=?,
  ]}

  */
/**
    {3 methods }
    {4 scrollToEnd}
  */
let scrollToEnd: (ReasonReact.reactRef, ~animated: bool) => unit;

/**
  {4 scrollToIndex}
  */

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

/**
  {4 scrollToItem}
  */

let scrollToItem:
  (
    ReasonReact.reactRef,
    ~item: 'item,
    ~animated: bool=?,
    ~viewPosition: int=?,
    unit
  ) =>
  unit;

/**
  {4 scrollToOffset}
  */

let scrollToOffset:
  (ReasonReact.reactRef, ~offset: float=?, ~animated: bool=?, unit) => unit;

/**
  {2 API reference}
  */
[@bs.send]
external recordInteraction: ReasonReact.reactRef => unit = "";

type renderBag('item) = {
  item: 'item,
  index: int,
};

type renderItem('item);

let renderItem: (renderBag('item) => React.element) => renderItem('item);

type separatorComponent('item);

type separatorProps('item) = {
  highlighted: bool,
  leadingItem: option('item),
};

let separatorComponent:
  (separatorProps('item) => React.element) => separatorComponent('item);

type overScrollMode = [ | `always | `never | `auto];

type contentInsetAdjustmentBehavior = [
  | `automatic
  | `scrollableAxes
  | `never
  | `always
];

[@react.component]
let make:
  (
    ~data: array('item),
    ~renderItem: renderItem('item),
    ~keyExtractor: ('item, int) => string,
    ~itemSeparatorComponent: React.component(
                               ReactNative.FlatList.separatorComponentProps(
                                 'item,
                               ),
                             )
                               =?,
    ~bounces: bool=?,
    ~listEmptyComponent: React.element=?,
    ~listFooterComponent: React.element=?,
    ~listFooterComponentStyle: Style.t=?,
    ~listHeaderComponent: React.element=?,
    ~listHeaderComponentStyle: Style.t=?,
    ~columnWrapperStyle: Style.t=?,
    ~extraData: 'any=?,
    ~getItemLayout: (array('item), int) =>
                    ReactNative.VirtualizedList.itemLayout
                      =?,
    ~horizontal: bool=?,
    ~initialNumToRender: int=?,
    ~initialScrollIndex: int=?,
    ~inverted: bool=?,
    ~numColumns: 'int=?,
    ~onEndReached: ReactNative.VirtualizedList.onEndReachedParams => unit=?,
    ~onEndReachedThreshold: float=?,
    ~onRefresh: unit => unit=?,
    ~onViewableItemsChanged: ReactNative.VirtualizedList.viewableItemsChanged(
                               'item,
                             ) =>
                             unit
                               =?,
    ~overScrollMode: overScrollMode=?,
    ~pagingEnabled: bool=?,
    ~refreshControl: React.element=?,
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
    unit
  ) =>
  React.element;
