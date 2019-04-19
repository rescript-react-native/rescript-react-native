

import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as Belt_Option from "bs-platform/lib/es6/belt_Option.js";
import * as Caml_option from "bs-platform/lib/es6/caml_option.js";
import * as ReasonReact from "reason-react/src/ReasonReact.js";
import * as Js_undefined from "bs-platform/lib/es6/js_undefined.js";
import * as ReactNative from "react-native";
import * as ScrollViewProps$BsReactNative from "./ScrollViewProps.bs.js";

function CreateComponent(Impl) {
  var scrollToEnd = function (ref, animated) {
    ref.scrollToEnd({
          animated: animated
        });
    return /* () */0;
  };
  var scrollToIndex = function (ref, index, animated, viewOffset, viewPosition, param) {
    ref._scrollToIndex({
          index: index,
          viewOffset: Js_undefined.fromOption(viewOffset),
          viewPosition: Js_undefined.fromOption(viewPosition),
          animated: Js_undefined.fromOption(animated)
        });
    return /* () */0;
  };
  var scrollToItem = function (ref, item, animated, viewPosition, param) {
    ref._scrollToIndex({
          item: item,
          viewPosition: Js_undefined.fromOption(viewPosition),
          animated: Js_undefined.fromOption(animated)
        });
    return /* () */0;
  };
  var scrollToOffset = function (ref, offset, animated, param) {
    ref.scrollToOffset({
          offset: Js_undefined.fromOption(offset),
          animated: Js_undefined.fromOption(animated)
        });
    return /* () */0;
  };
  var renderItem = function (reRenderItem, jsRenderBag) {
    return Curry._1(reRenderItem, /* record */[
                /* item */jsRenderBag.item,
                /* index */jsRenderBag.index
              ]);
  };
  var separatorComponent = function (reSeparatorComponent, jsSeparatorProps) {
    return Curry._1(reSeparatorComponent, /* record */[
                /* highlighted */jsSeparatorProps.highlighted,
                /* leadingItem */Caml_option.undefined_to_opt(jsSeparatorProps.leadingItem)
              ]);
  };
  var make = function (data, renderItem, keyExtractor, itemSeparatorComponent, bounces, listEmptyComponent, listFooterComponent, listFooterComponentStyle, listHeaderComponent, listHeaderComponentStyle, columnWrapperStyle, extraData, getItemLayout, horizontal, initialNumToRender, initialScrollIndex, inverted, numColumns, onEndReached, onEndReachedThreshold, onRefresh, onViewableItemsChanged, overScrollMode, pagingEnabled, refreshControl, refreshing, removeClippedSubviews, scrollEnabled, stickyHeaderIndices, showsHorizontalScrollIndicator, showsVerticalScrollIndicator, windowSize, maxToRenderPerBatch, viewabilityConfig, scrollEventThrottle, onScroll, onScrollBeginDrag, onScrollEndDrag, onMomentumScrollBegin, onMomentumScrollEnd, style, contentInsetAdjustmentBehavior) {
    var partial_arg = {
      bounces: bounces,
      ItemSeparatorComponent: itemSeparatorComponent,
      ListEmptyComponent: listEmptyComponent,
      ListFooterComponent: listFooterComponent,
      ListFooterComponentStyle: listFooterComponentStyle,
      ListHeaderComponent: listHeaderComponent,
      ListHeaderComponentStyle: listHeaderComponentStyle,
      columnWrapperStyle: columnWrapperStyle,
      data: data,
      extraData: extraData,
      getItemLayout: Belt_Option.map(getItemLayout, (function (f, data, index) {
              return Curry._2(f, data === undefined ? undefined : Caml_option.some(data), index);
            })),
      horizontal: horizontal,
      initialNumToRender: initialNumToRender,
      initialScrollIndex: initialScrollIndex,
      inverted: inverted,
      keyExtractor: keyExtractor,
      numColumns: numColumns,
      onEndReached: onEndReached,
      onEndReachedThreshold: onEndReachedThreshold,
      onRefresh: onRefresh,
      onViewableItemsChanged: onViewableItemsChanged,
      overScrollMode: Belt_Option.map(overScrollMode, ScrollViewProps$BsReactNative.overScrollModeToJs),
      pagingEnabled: pagingEnabled,
      refreshControl: refreshControl,
      refreshing: refreshing,
      renderItem: renderItem,
      removeClippedSubviews: removeClippedSubviews,
      scrollEnabled: scrollEnabled,
      stickyHeaderIndices: Belt_Option.map(stickyHeaderIndices, $$Array.of_list),
      showsHorizontalScrollIndicator: showsHorizontalScrollIndicator,
      showsVerticalScrollIndicator: showsVerticalScrollIndicator,
      windowSize: windowSize,
      maxToRenderPerBatch: maxToRenderPerBatch,
      viewabilityConfig: viewabilityConfig,
      scrollEventThrottle: scrollEventThrottle,
      onScroll: onScroll,
      onScrollBeginDrag: onScrollBeginDrag,
      onScrollEndDrag: onScrollEndDrag,
      onMomentumScrollBegin: onMomentumScrollBegin,
      onMomentumScrollEnd: onMomentumScrollEnd,
      style: style,
      contentInsetAdjustmentBehavior: Belt_Option.map(contentInsetAdjustmentBehavior, ScrollViewProps$BsReactNative.contentInsetAdjustmentBehaviorToJs)
    };
    var partial_arg$1 = Impl[/* view */0];
    return (function (param) {
        return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
      });
  };
  return /* module */[
          /* scrollToEnd */scrollToEnd,
          /* scrollToIndex */scrollToIndex,
          /* scrollToItem */scrollToItem,
          /* scrollToOffset */scrollToOffset,
          /* renderItem */renderItem,
          /* separatorComponent */separatorComponent,
          /* make */make
        ];
}

var Impl = /* module */[/* FlatList */ReactNative.FlatList];

function scrollToEnd(ref, animated) {
  ref.scrollToEnd({
        animated: animated
      });
  return /* () */0;
}

function scrollToIndex(ref, index, animated, viewOffset, viewPosition, param) {
  ref._scrollToIndex({
        index: index,
        viewOffset: Js_undefined.fromOption(viewOffset),
        viewPosition: Js_undefined.fromOption(viewPosition),
        animated: Js_undefined.fromOption(animated)
      });
  return /* () */0;
}

function scrollToItem(ref, item, animated, viewPosition, param) {
  ref._scrollToIndex({
        item: item,
        viewPosition: Js_undefined.fromOption(viewPosition),
        animated: Js_undefined.fromOption(animated)
      });
  return /* () */0;
}

function scrollToOffset(ref, offset, animated, param) {
  ref.scrollToOffset({
        offset: Js_undefined.fromOption(offset),
        animated: Js_undefined.fromOption(animated)
      });
  return /* () */0;
}

function renderItem(reRenderItem, jsRenderBag) {
  return Curry._1(reRenderItem, /* record */[
              /* item */jsRenderBag.item,
              /* index */jsRenderBag.index
            ]);
}

function separatorComponent(reSeparatorComponent, jsSeparatorProps) {
  return Curry._1(reSeparatorComponent, /* record */[
              /* highlighted */jsSeparatorProps.highlighted,
              /* leadingItem */Caml_option.undefined_to_opt(jsSeparatorProps.leadingItem)
            ]);
}

function make(data, renderItem, keyExtractor, itemSeparatorComponent, bounces, listEmptyComponent, listFooterComponent, listFooterComponentStyle, listHeaderComponent, listHeaderComponentStyle, columnWrapperStyle, extraData, getItemLayout, horizontal, initialNumToRender, initialScrollIndex, inverted, numColumns, onEndReached, onEndReachedThreshold, onRefresh, onViewableItemsChanged, overScrollMode, pagingEnabled, refreshControl, refreshing, removeClippedSubviews, scrollEnabled, stickyHeaderIndices, showsHorizontalScrollIndicator, showsVerticalScrollIndicator, windowSize, maxToRenderPerBatch, viewabilityConfig, scrollEventThrottle, onScroll, onScrollBeginDrag, onScrollEndDrag, onMomentumScrollBegin, onMomentumScrollEnd, style, contentInsetAdjustmentBehavior) {
  var partial_arg = {
    bounces: bounces,
    ItemSeparatorComponent: itemSeparatorComponent,
    ListEmptyComponent: listEmptyComponent,
    ListFooterComponent: listFooterComponent,
    ListFooterComponentStyle: listFooterComponentStyle,
    ListHeaderComponent: listHeaderComponent,
    ListHeaderComponentStyle: listHeaderComponentStyle,
    columnWrapperStyle: columnWrapperStyle,
    data: data,
    extraData: extraData,
    getItemLayout: Belt_Option.map(getItemLayout, (function (f, data, index) {
            return Curry._2(f, data === undefined ? undefined : Caml_option.some(data), index);
          })),
    horizontal: horizontal,
    initialNumToRender: initialNumToRender,
    initialScrollIndex: initialScrollIndex,
    inverted: inverted,
    keyExtractor: keyExtractor,
    numColumns: numColumns,
    onEndReached: onEndReached,
    onEndReachedThreshold: onEndReachedThreshold,
    onRefresh: onRefresh,
    onViewableItemsChanged: onViewableItemsChanged,
    overScrollMode: Belt_Option.map(overScrollMode, ScrollViewProps$BsReactNative.overScrollModeToJs),
    pagingEnabled: pagingEnabled,
    refreshControl: refreshControl,
    refreshing: refreshing,
    renderItem: renderItem,
    removeClippedSubviews: removeClippedSubviews,
    scrollEnabled: scrollEnabled,
    stickyHeaderIndices: Belt_Option.map(stickyHeaderIndices, $$Array.of_list),
    showsHorizontalScrollIndicator: showsHorizontalScrollIndicator,
    showsVerticalScrollIndicator: showsVerticalScrollIndicator,
    windowSize: windowSize,
    maxToRenderPerBatch: maxToRenderPerBatch,
    viewabilityConfig: viewabilityConfig,
    scrollEventThrottle: scrollEventThrottle,
    onScroll: onScroll,
    onScrollBeginDrag: onScrollBeginDrag,
    onScrollEndDrag: onScrollEndDrag,
    onMomentumScrollBegin: onMomentumScrollBegin,
    onMomentumScrollEnd: onMomentumScrollEnd,
    style: style,
    contentInsetAdjustmentBehavior: Belt_Option.map(contentInsetAdjustmentBehavior, ScrollViewProps$BsReactNative.contentInsetAdjustmentBehaviorToJs)
  };
  var partial_arg$1 = Impl[/* view */0];
  return (function (param) {
      return ReasonReact.wrapJsForReason(partial_arg$1, partial_arg, param);
    });
}

export {
  CreateComponent ,
  scrollToEnd ,
  scrollToIndex ,
  scrollToItem ,
  scrollToOffset ,
  renderItem ,
  separatorComponent ,
  make ,
  
}
/* Impl Not a pure module */
