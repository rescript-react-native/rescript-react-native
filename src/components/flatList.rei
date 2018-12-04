/************* */
module type FlatListComponent = {
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
    listFooterComponent: ReasonReact.reactElement=?
  ]}
  {4 listHeaderComponent}
  {[
    listHeaderComponent: ReasonReact.reactElement=?
  ]}
  {4 listEmptyComponent}
  {[
    listEmptyComponent: ReasonReact.reactElement=?
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
  {4 showsHorizontalScrollIndicator}
  {[
    showsHorizontalScrollIndicator: bool=?
  ]}
  {4 showsVerticalScrollIndicator}
  {[
    showsVerticalScrollIndicator: bool=?
  ]}
  {4 stickyHeaderIndices}
  {[
    stickyHeaderIndices: list(int)=?
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
  reference:
  {4 RNEvent.rei}
  {[
    module NativeScrollEvent: {
      type t;
      type point = {
        x: float,
        y: float
      };
      type size = {
        width: float,
        height: float
      };
      type contentInset = {
        bottom: float,
        top: float,
        left: float,
        right: float
      };
      let contentOffset: t => point;
      let contentSize: t => size;
      let contentInset: t => contentInset;
      let layoutMeasurement: t => size;
    };
  ]}
  {4 style}
  {[
    style: Style.t=?
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
      ~listFooterComponent: ReasonReact.reactElement=?,
      ~listHeaderComponent: ReasonReact.reactElement=?,
      ~listEmptyComponent: ReasonReact.reactElement=?,
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
      ~overScrollMode: [ | `auto | `always | `never]=?,
      ~pagingEnabled: bool=?,
      ~refreshing: bool=?,
      ~removeClippedSubviews: bool=?,
      ~scrollEnabled: bool=?,
      ~showsHorizontalScrollIndicator: bool=?,
      ~showsVerticalScrollIndicator: bool=?,
      ~stickyHeaderIndices: list(int)=?,
      ~windowSize: int=?,
      ~maxToRenderPerBatch: int=?,
      ~viewabilityConfig: Js.t({.})=?,
      ~onScroll: RNEvent.NativeScrollEvent.t => unit=?,
      ~style: Style.t=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent: (Impl: View.Impl) => FlatListComponent;

include FlatListComponent;