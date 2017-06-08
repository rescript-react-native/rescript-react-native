external view : ReasonReact.reactClass = "FlatList" [@@bs.module "react-native"];

external _scrollToEnd : ReasonReact.reactRef => Js.t {. animated : Js.boolean} => unit =
  "scrollToEnd" [@@bs.send];

let scrollToEnd ref ::animated => _scrollToEnd ref {"animated": Js.Boolean.to_js_boolean animated};

external _scrollToIndex :
  ReasonReact.reactRef =>
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
    Js.Undefined.(
      {
        "index": index,
        "viewOffset": from_opt viewOffset,
        "viewPosition": from_opt viewPosition,
        "animated": from_opt animated
      }
    );

external _scrollToItem :
  ReasonReact.reactRef =>
  Js.t {. item : 'item, viewPosition : Js.undefined int, animated : Js.undefined Js.boolean} =>
  unit =
  "_scrollToIndex" [@@bs.send];

let scrollToItem ref ::item ::animated=? ::viewPosition=? () =>
  _scrollToItem
    ref
    Js.Undefined.(
      {"item": item, "viewPosition": from_opt viewPosition, "animated": from_opt animated}
    );

external _scrollToOffset :
  ReasonReact.reactRef =>
  Js.t {. offset : Js.undefined int, animated : Js.undefined Js.boolean} =>
  unit =
  "_scrollToIndex" [@@bs.send];

let scrollToOffset ref ::offset=? ::animated=? () =>
  _scrollToOffset ref Js.Undefined.({"offset": from_opt offset, "animated": from_opt animated});

external recordInteraction : ReasonReact.reactRef => unit = "" [@@bs.send];

let make
    ::data
    ::renderItem
    ::itemSeparatorComponent=?
    ::listFooterComponent=?
    ::listHeaderComponent=?
    ::columnWrapperStyle=?
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
  ReasonReact.wrapJsForReason
    reactClass::view
    props::
      Js.Undefined.(
        {
          "itemSeparatorComponent": from_opt itemSeparatorComponent,
          "listFooterComponent": from_opt listFooterComponent,
          "listHeaderComponent": from_opt listHeaderComponent,
          "columnWrapperStyle": from_opt columnWrapperStyle,
          "data": data,
          "extraData": from_opt extraData,
          "getItemLayout":
            from_opt (
              UtilsRN.option_map
                (fun f data index => f (Js.Undefined.to_opt data) index) getItemLayout
            ),
          "horizontal": from_opt (UtilsRN.optBoolToOptJsBoolean horizontal),
          "initialNumToRender": from_opt initialNumToRender,
          "initialScrollIndex": from_opt initialScrollIndex,
          "keyExtractor": from_opt keyExtractor,
          "numColumns": from_opt numColumns,
          "onEndReached": from_opt onEndReached,
          "onEndReachedThreshold": from_opt onEndReachedThreshold,
          "onRefresh": from_opt onRefresh,
          "onViewableItemsChanged": from_opt onViewableItemsChanged,
          "refreshing": from_opt (UtilsRN.optBoolToOptJsBoolean refreshing),
          "renderItem": renderItem,
          "removeClippedSubviews": from_opt (UtilsRN.optBoolToOptJsBoolean removeClippedSubviews),
          "viewabilityConfig": from_opt viewabilityConfig
        }
      );