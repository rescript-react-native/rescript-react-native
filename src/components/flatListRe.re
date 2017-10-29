[@bs.module "react-native"] external view : ReasonReact.reactClass = "FlatList";

[@bs.send] external _scrollToEnd : (ReasonReact.reactRef, {. "animated": Js.boolean}) => unit =
  "scrollToEnd";

let scrollToEnd = (ref, ~animated) =>
  _scrollToEnd(ref, {"animated": Js.Boolean.to_js_boolean(animated)});

[@bs.send]
external _scrollToIndex :
  (
    ReasonReact.reactRef,
    {
      .
      "index": int,
      "viewOffset": Js.undefined(int),
      "viewPosition": Js.undefined(int),
      "animated": Js.undefined(Js.boolean)
    }
  ) =>
  unit =
  "_scrollToIndex";

let scrollToIndex = (ref, ~index, ~animated=?, ~viewOffset=?, ~viewPosition=?, ()) =>
  _scrollToIndex(
    ref,
    Js.Undefined.(
      {
        "index": index,
        "viewOffset": from_opt(viewOffset),
        "viewPosition": from_opt(viewPosition),
        "animated": from_opt(animated)
      }
    )
  );

[@bs.send]
external _scrollToItem :
  (
    ReasonReact.reactRef,
    {. "item": 'item, "viewPosition": Js.undefined(int), "animated": Js.undefined(Js.boolean)}
  ) =>
  unit =
  "_scrollToIndex";

let scrollToItem = (ref, ~item, ~animated=?, ~viewPosition=?, ()) =>
  _scrollToItem(
    ref,
    Js.Undefined.(
      {"item": item, "viewPosition": from_opt(viewPosition), "animated": from_opt(animated)}
    )
  );

[@bs.send]
external _scrollToOffset :
  (ReasonReact.reactRef, {. "offset": Js.undefined(int), "animated": Js.undefined(Js.boolean)}) =>
  unit =
  "_scrollToIndex";

let scrollToOffset = (ref, ~offset=?, ~animated=?, ()) =>
  _scrollToOffset(
    ref,
    Js.Undefined.({"offset": from_opt(offset), "animated": from_opt(animated)})
  );

[@bs.send] external recordInteraction : ReasonReact.reactRef => unit = "";

type jsRenderBag('item) = {. "item": 'item, "index": int};

type renderBag('item) = {
  item: 'item,
  index: int
};

type renderItem('item) = jsRenderBag('item) => ReasonReact.reactElement;

let renderItem = (reRenderItem: renderBag('item) => ReasonReact.reactElement) : renderItem('item) =>
  (jsRenderBag: jsRenderBag('item)) =>
    reRenderItem({item: jsRenderBag##item, index: jsRenderBag##index});

type jsSeparatorProps('item) = {. "highlighted": Js.boolean, "leadingItem": Js.Undefined.t('item)};

type separatorProps('item) = {
  highlighted: bool,
  leadingItem: option('item)
};

type separatorComponent('item) = jsSeparatorProps('item) => ReasonReact.reactElement;

let separatorComponent =
    (reSeparatorComponent: separatorProps('item) => ReasonReact.reactElement)
    : separatorComponent('item) =>
  (jsSeparatorProps: jsSeparatorProps('item)) =>
    reSeparatorComponent({
      highlighted: Js.to_bool(jsSeparatorProps##highlighted),
      leadingItem: Js.Undefined.to_opt(jsSeparatorProps##leadingItem)
    });

let make =
    (
      ~data: array('item),
      ~renderItem: renderItem('item),
      ~keyExtractor: ('item, int) => string,
      ~itemSeparatorComponent: option(separatorComponent('item))=?,
      ~bounces=?,
      ~listFooterComponent=?,
      ~listHeaderComponent=?,
      ~columnWrapperStyle=?,
      ~extraData=?,
      ~getItemLayout=?,
      ~horizontal=?,
      ~initialNumToRender=?,
      ~initialScrollIndex=?,
      ~numColumns=?,
      ~onEndReached=?,
      ~onEndReachedThreshold=?,
      ~onRefresh=?,
      ~onViewableItemsChanged=?,
      ~overScrollMode=?,
      ~pagingEnabled=?,
      ~refreshing=?,
      ~removeClippedSubviews=?,
      ~scrollEnabled=?,
      ~showsHorizontalScrollIndicator=?,
      ~showsVerticalScrollIndicator=?,
      ~windowSize=?,
      ~maxToRenderPerBatch=?,
      ~viewabilityConfig=?
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Js.Undefined.(
        {
          "bounces": from_opt(UtilsRN.optBoolToOptJsBoolean(bounces)),
          "ItemSeparatorComponent": from_opt(itemSeparatorComponent),
          "ListFooterComponent": from_opt(listFooterComponent),
          "ListHeaderComponent": from_opt(listHeaderComponent),
          "columnWrapperStyle": from_opt(columnWrapperStyle),
          "data": data,
          "extraData": from_opt(extraData),
          "getItemLayout":
            from_opt(
              UtilsRN.option_map(
                (f, data, index) => f(Js.Undefined.to_opt(data), index),
                getItemLayout
              )
            ),
          "horizontal": from_opt(UtilsRN.optBoolToOptJsBoolean(horizontal)),
          "initialNumToRender": from_opt(initialNumToRender),
          "initialScrollIndex": from_opt(initialScrollIndex),
          "keyExtractor": keyExtractor,
          "numColumns": from_opt(numColumns),
          "onEndReached": from_opt(onEndReached),
          "onEndReachedThreshold": from_opt(onEndReachedThreshold),
          "onRefresh": from_opt(onRefresh),
          "onViewableItemsChanged": from_opt(onViewableItemsChanged),
          "overScrollMode":
            from_opt(
              UtilsRN.option_map(
                (x) =>
                  switch x {
                  | `auto => "auto"
                  | `always => "always"
                  | `never => "never"
                  },
                overScrollMode
              )
            ),
          "pagingEnabled": from_opt(UtilsRN.optBoolToOptJsBoolean(pagingEnabled)),
          "refreshing": from_opt(UtilsRN.optBoolToOptJsBoolean(refreshing)),
          "renderItem": renderItem,
          "removeClippedSubviews": from_opt(UtilsRN.optBoolToOptJsBoolean(removeClippedSubviews)),
          "scrollEnabled": from_opt(UtilsRN.optBoolToOptJsBoolean(scrollEnabled)),
          "showsHorizontalScrollIndicator":
            from_opt(UtilsRN.optBoolToOptJsBoolean(showsHorizontalScrollIndicator)),
          "showsVerticalScrollIndicator":
            from_opt(UtilsRN.optBoolToOptJsBoolean(showsVerticalScrollIndicator)),
          "windowSize": from_opt(windowSize),
          "maxToRenderPerBatch": from_opt(maxToRenderPerBatch),
          "viewabilityConfig": from_opt(viewabilityConfig)
        }
      )
  );
