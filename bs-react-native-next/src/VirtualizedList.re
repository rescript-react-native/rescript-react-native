type renderItemProps('item) = {
  .
  "item": 'item,
  "index": int,
  // "separators": TODO
};

type renderItemCallback('item) = renderItemProps('item) => React.element;

// TODO
type cellRendererComponentProps('item) = {.};
type cellRendererComponent('item) =
  React.component(cellRendererComponentProps('item));

type viewableItem('item) = {
  .
  "item": 'item,
  "key": string,
  "index": Js.undefined(int),
  "isViewable": bool,
  "section": Js.t({.}),
};

type viewableItemsChanged('item) = {
  .
  "viewableItems": array(viewableItem('item)),
  "changed": array(viewableItem('item)),
};

type itemLayout = {
  .
  "length": float,
  "offset": float,
  "index": int,
};

type onEndReachedParams = {. "distanceFromEnd": float};

type onScrollToIndexFailedInfo = {
  .
  "index": int,
  "highestMeasuredFrameIndex": int,
  "averageItemLength": float,
};

type onScrollToIndexFailedParams = {. "info": onScrollToIndexFailedInfo};

type viewabilityConfig;
[@bs.obj]
external viewabilityConfig:
  (
    ~minimumViewTime: float=?,
    ~viewAreaCoveragePercentThreshold: float=?,
    ~itemVisiblePercentThreshold: float=?,
    ~waitForInteraction: bool=?,
    unit
  ) =>
  viewabilityConfig =
  "";

type viewabilityConfigCallbackPair('item);
[@bs.obj]
external viewabilityConfigCallbackPair:
  (
    ~viewabilityConfig: viewabilityConfig,
    ~onViewableItemsChanged: viewableItemsChanged('item) => unit
  ) =>
  viewabilityConfigCallbackPair('item) =
  "";

type viewabilityConfigCallbackPairs('item) =
  array(viewabilityConfigCallbackPair('item));

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~_CellRendererComponent: cellRendererComponent('item)=?,
    ~_ListEmptyComponent: React.element=?,
    ~_ListFooterComponent: React.element=?,
    ~_ListHeaderComponent: React.element=?,
    ~data: 'data, // any collection of 'item
    ~disableVirtualization: bool=?, // deprecated
    ~extraData: 'extraData=?,
    ~getItem: ('data, int) => 'item=?,
    ~getItemCount: 'data => int=?,
    ~getItemLayout: ('data, int) => itemLayout=?,
    ~initialNumToRender: int=?,
    ~initialScrollIndex: int=?,
    ~inverted: bool=?,
    ~keyExtractor: ('item, int) => string,
    ~maxToRenderPerBatch: int=?,
    ~onEndReached: onEndReachedParams => unit=?,
    ~onEndReachedThreshold: float=?,
    ~onRefresh: unit => unit=?,
    ~onScrollToIndexFailed: onScrollToIndexFailedParams => unit=?,
    ~onViewableItemsChanged: viewableItemsChanged('item) => unit=?,
    ~progressViewOffset: float=?,
    ~refreshing: bool=?,
    ~renderItem: renderItemCallback('item),
    ~renderScrollComponent: unit => React.element=?, // TODO: params?
    ~updateCellsBatchingPeriod: float=?,
    ~viewabilityConfig: viewabilityConfig=?,
    ~viewabilityConfigCallbackPairs: viewabilityConfigCallbackPairs('item)=?,
    ~windowSize: int=?,
    // ScrollView props
    ~alwaysBounceHorizontal: bool=?,
    ~alwaysBounceVertical: bool=?,
    ~automaticallyAdjustContentInsets: bool=?,
    ~bounces: bool=?,
    ~bouncesZoom: bool=?,
    ~canCancelContentTouches: bool=?,
    ~centerContent: bool=?,
    ~contentContainerStyle: Style.t=?,
    ~contentInset: Types.insets=?,
    ~contentInsetAdjustmentBehavior: [@bs.string] [
                                       | `automatic
                                       | `scrollableAxes
                                       | `never
                                       | `always
                                     ]
                                       =?,
    ~contentOffset: Types.point=?,
    ~decelerationRate: [@bs.string] [ | `fast | `normal]=?,
    ~directionalLockEnabled: bool=?,
    ~endFillColor: Style.color=?,
    ~horizontal: bool=?,
    ~indicatorStyle: [@bs.string] [ | `default | `black | `white]=?,
    ~keyboardDismissMode: [@bs.string] [ | `none | `interactive | `onDrag]=?,
    ~keyboardShouldPersistTaps: [@bs.string] [ | `always | `never | `handled]=?,
    ~maximumZoomScale: float=?,
    ~minimumZoomScale: float=?,
    ~nestedScrollEnabled: bool=?,
    ~onContentSizeChange: ((float, float)) => unit=?,
    ~onMomentumScrollBegin: Event.NativeScrollEvent.t => unit=?,
    ~onMomentumScrollEnd: Event.NativeScrollEvent.t => unit=?,
    ~onScroll: Event.NativeScrollEvent.t => unit=?,
    ~onScrollBeginDrag: Event.NativeScrollEvent.t => unit=?,
    ~onScrollEndDrag: Event.NativeScrollEvent.t => unit=?,
    ~overScrollMode: [@bs.string] [ | `always | `never | `auto]=?,
    ~pagingEnabled: bool=?,
    ~refreshControl: React.element=?,
    ~scrollEnabled: bool=?,
    ~scrollEventThrottle: int=?,
    ~scrollIndicatorInsets: Types.insets=?,
    ~scrollPerfTag: string=?,
    ~scrollsToTop: bool=?,
    ~showsHorizontalScrollIndicator: bool=?,
    ~showsVerticalScrollIndicator: bool=?,
    ~snapToAlignment: [@bs.string] [ | `start | `center | `end_]=?,
    ~snapToEnd: bool=?,
    ~snapToInterval: float=?,
    ~snapToOffsets: array(float)=?,
    ~snapToStart: bool=?,
    ~stickyHeaderIndices: list(int)=?,
    ~zoomScale: float=?,
    // View props
    ~accessibilityComponentType: [@bs.string] [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityElementsHidden: bool=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityLabel: React.element=?,
    ~accessibilityLiveRegion: [@bs.string] [ | `none | `polite | `assertive]=?,
    ~accessibilityRole: [@bs.string] [
                          | `none
                          | `button
                          | `link
                          | `search
                          | `image
                          | `keyboardkey
                          | `text
                          | `adjustable
                          | `header
                          | `summary
                          | `imagebutton
                        ]
                          =?,
    ~accessibilityStates: array(Types.AccessibilityState.t)=?,
    ~accessibilityTraits: array(Types.AccessibilityTrait.t)=?,
    ~accessibilityViewIsModal: bool=?,
    ~accessible: bool=?,
    ~collapsable: bool=?,
    ~hitSlop: Types.insets=?,
    ~importantForAccessibility: [@bs.string] [
                                  | `auto
                                  | `yes
                                  | `no
                                  | [@bs.as "no-hide-descendants"]
                                    `noHideDescendants
                                ]
                                  =?,
    ~nativeID: string=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: Event.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~onMoveShouldSetResponder: Event.NativeEvent.t => bool=?,
    ~onMoveShouldSetResponderCapture: Event.NativeEvent.t => bool=?,
    ~onResponderGrant: Event.NativeEvent.t => unit=?,
    ~onResponderMove: Event.NativeEvent.t => unit=?,
    ~onResponderReject: Event.NativeEvent.t => unit=?,
    ~onResponderRelease: Event.NativeEvent.t => unit=?,
    ~onResponderTerminate: Event.NativeEvent.t => unit=?,
    ~onResponderTerminationRequest: Event.NativeEvent.t => unit=?,
    ~onStartShouldSetResponder: Event.NativeEvent.t => bool=?,
    ~onStartShouldSetResponderCapture: Event.NativeEvent.t => bool=?,
    ~pointerEvents: [@bs.string] [
                      | `auto
                      | `none
                      | [@bs.as "box-none"] `boxNone
                      | [@bs.as "box-only"] `boxOnly
                    ]
                      =?,
    ~removeClippedSubviews: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~style: Style.t=?,
    ~testID: string=?
  ) =>
  React.element =
  "FlatList";

type scrollToEndOptions;
[@bs.obj]
external scrollToEndOptions: (~animated: bool=?, unit) => scrollToEndOptions =
  "";
[@bs.send] external scrollToEnd: React.Ref.domRef => unit = "scrollToEnd";
[@bs.send]
external scrollToEndWithOptions: (React.Ref.domRef, scrollToEndOptions) => unit =
  "scrollToEnd";

type scrollToIndexParams;
[@bs.obj]
external scrollToIndexParams:
  (
    ~viewOffset: float=?,
    ~viewPosition: float=?,
    ~animated: bool=?,
    ~index: int,
    unit
  ) =>
  scrollToIndexParams =
  "";
[@bs.send]
external scrollToIndex: scrollToIndexParams => unit = "scrollToIndex";

type scrollToItemParams('item);
[@bs.obj]
external scrollToItemParams:
  (~viewPosition: float=?, ~animated: bool=?, ~item: 'item, unit) =>
  scrollToIndexParams =
  "";
[@bs.send]
external scrollToItem: scrollToItemParams('item) => unit = "scrollToItem";

type scrollToOffsetParams;
[@bs.obj]
external scrollToOffsetParams:
  (~animated: bool=?, ~offset: float, unit) => scrollToOffsetParams =
  "";
[@bs.send]
external scrollToOffset: scrollToOffsetParams => unit = "scrollToOffset";

[@bs.send] external recordInteraction: React.Ref.domRef => unit = "";

[@bs.send] external flashScrollIndicators: React.Ref.domRef => unit = "";
