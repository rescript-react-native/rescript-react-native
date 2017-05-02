open Utils;

external view : ReactRe.reactClass = "FlatList" [@@bs.module "react-native"];

external _scrollToEnd : ReactRe.reactRef => Js.t {. animated : Js.boolean} => unit =
  "scrollToEnd" [@@bs.send];

let scrollToEnd ref ::animated => _scrollToEnd ref {"animated": to_js_boolean animated};

external _scrollToIndex :
  ReactRe.reactRef =>
  Js.t {
    .
    index : int,
    viewOffset : Js.undefined int,
    viewPosition : Js.undefined int,
    animated : Js.undefined Js.boolean
  } =>
  unit =
  "_scrollToIndex" [@@bs.send];

let scrollToIndex ref ::index ::animated=? ::viewOffset=? ::viewPosition=? () =>
  _scrollToIndex
    ref
    {
      "index": index,
      "viewOffset": from_opt viewOffset,
      "viewPosition": from_opt viewPosition,
      "animated": from_opt animated
    };

external _scrollToItem :
  ReactRe.reactRef =>
  Js.t {. item : 'item, viewPosition : Js.undefined int, animated : Js.undefined Js.boolean} =>
  unit =
  "_scrollToIndex" [@@bs.send];

let scrollToItem ref ::item ::animated=? ::viewPosition=? () =>
  _scrollToItem
    ref {"item": item, "viewPosition": from_opt viewPosition, "animated": from_opt animated};

external _scrollToOffset :
  ReactRe.reactRef =>
  Js.t {. offset : Js.undefined int, animated : Js.undefined Js.boolean} =>
  unit =
  "_scrollToIndex" [@@bs.send];

let scrollToOffset ref ::offset=? ::animated=? () =>
  _scrollToOffset ref {"offset": from_opt offset, "animated": from_opt animated};

external recordInteraction : ReactRe.reactRef => unit =
  "" [@@bs.send];

let createElement
    ::itemSeparatorComponent=?
    ::listFooterComponent=?
    ::listHeaderComponent=?
    ::columnWrapperStyle=?
    ::data=?
    ::extraData=?
    ::getItemLayout=?
    ::horizontal=?
    ::initialNumToRender=?
    ::initialScrollIndex=?
    ::keyExtractor=?
    ::numColumns=?
    ::onEndReached=?
    ::onEndReachedThreshold=?
    ::onRefresh=?
    ::onViewableItemsChanged=?
    ::refreshing=?
    ::removeClippedSubviews=?
    ::viewabilityConfig=? =>
  ReactRe.wrapPropsShamelessly
    view
    {
      "itemSeparatorComponent": from_opt itemSeparatorComponent,
      "listFooterComponent": from_opt listFooterComponent,
      "listHeaderComponent": from_opt listHeaderComponent,
      "columnWrapperStyle": from_opt columnWrapperStyle,
      "data": from_opt data,
      "extraData": from_opt extraData,
      "getItemLayout":
        from_opt (
          option_map (fun f data index => f (Js.Undefined.to_opt data) index) getItemLayout
        ),
      "horizontal": from_opt (option_map to_js_boolean horizontal),
      "initialNumToRender": from_opt initialNumToRender,
      "initialScrollIndex": from_opt initialScrollIndex,
      "keyExtractor": from_opt keyExtractor,
      "numColumns": from_opt numColumns,
      "onEndReached": from_opt onEndReached,
      "onEndReachedThreshold": from_opt onEndReachedThreshold,
      "onRefresh": from_opt onRefresh,
      "onViewableItemsChanged": from_opt onViewableItemsChanged,
      "refreshing": from_opt (option_map to_js_boolean refreshing),
      "removeClippedSubviews": from_opt (option_map to_js_boolean removeClippedSubviews),
      "viewabilityConfig": from_opt viewabilityConfig
    };