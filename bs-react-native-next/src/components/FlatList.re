type element;
type ref = React.Ref.t(Js.nullable(element));

type separatorComponentProps('item) = {
  .
  "highlighted": bool,
  "leadingItem": option('item),
};

[@react.component] [@bs.module "react-native"]
external make:
  (
    ~ref: ref=?,
    // FlatList props
    ~_ItemSeparatorComponent: React.component(separatorComponentProps('item))
                                =?,
    ~columnWrapperStyle: Style.t=?,
    ~data: array('item),
    ~getItemLayout: (array('item), int) => VirtualizedList.itemLayout=?,
    ~numColumns: 'int=?,
    // VirtualizedList props
    // ~_CellRendererComponent: VirtualizedList.cellRendererComponent('item)=?,
    ~_ListEmptyComponent: React.element=?,
    ~_ListFooterComponent: React.element=?,
    ~_ListHeaderComponent: React.element=?,
    ~debug: bool=?,
    // ~data: 'data, // any collection of 'item
    ~disableVirtualization: bool=?, // deprecated
    ~extraData: 'extraData=?,
    // ~getItem: ('data, int) => 'item=?,
    // ~getItemCount: 'data => int=?,
    // ~getItemLayout: ('data, int) => VirtualizedList.itemLayout=?,
    ~initialNumToRender: int=?,
    ~initialScrollIndex: int=?,
    ~inverted: bool=?,
    ~keyExtractor: ('item, int) => string,
    ~maxToRenderPerBatch: int=?,
    ~onEndReached: VirtualizedList.onEndReachedParams => unit=?,
    ~onEndReachedThreshold: float=?,
    ~onRefresh: unit => unit=?,
    ~onScrollToIndexFailed: VirtualizedList.onScrollToIndexFailedParams => unit
                              =?,
    ~onViewableItemsChanged: VirtualizedList.viewableItemsChanged('item) =>
                             unit
                               =?,
    ~progressViewOffset: float=?,
    ~refreshing: bool=?,
    ~renderItem: VirtualizedList.renderItemCallback('item),
    ~renderScrollComponent: unit => React.element=?, // TODO: params?
    ~updateCellsBatchingPeriod: float=?,
    ~viewabilityConfig: VirtualizedList.viewabilityConfig=?,
    ~viewabilityConfigCallbackPairs: VirtualizedList.viewabilityConfigCallbackPairs(
                                       'item,
                                     )
                                       =?,
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
    ~onMomentumScrollBegin: Event.scrollEvent => unit=?,
    ~onMomentumScrollEnd: Event.scrollEvent => unit=?,
    ~onScroll: Event.scrollEvent => unit=?,
    ~onScrollBeginDrag: Event.scrollEvent => unit=?,
    ~onScrollEndDrag: Event.scrollEvent => unit=?,
    ~overScrollMode: [@bs.string] [ | `always | `never | `auto]=?,
    ~pagingEnabled: bool=?,
    ~refreshControl: React.element=?,
    ~scrollEnabled: bool=?,
    ~scrollEventThrottle: int=?,
    ~scrollIndicatorInsets: Types.insets=?,
    ~scrollPerfTag: string=?,
    ~scrollsToTop: bool=?,
    ~scrollToOverflowEnabled: bool=?,
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
    ~accessibilityLabel: string=?,
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
    ~accessibilityStates: array(AccessibilityState.t)=?,
    ~accessibilityTraits: array(AccessibilityTrait.t)=?,
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
    ~onLayout: Event.layoutEvent => unit=?,
    ~onMagicTap: unit => unit=?,
    // Gesture Responder props
    ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
    ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
    ~onResponderGrant: Event.pressEvent => unit=?,
    ~onResponderMove: Event.pressEvent => unit=?,
    ~onResponderReject: Event.pressEvent => unit=?,
    ~onResponderRelease: Event.pressEvent => unit=?,
    ~onResponderTerminate: Event.pressEvent => unit=?,
    ~onResponderTerminationRequest: Event.pressEvent => unit=?,
    ~onStartShouldSetResponder: Event.pressEvent => bool=?,
    ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
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

// VirtualizedList methods
type scrollToEndOptions;
[@bs.obj]
external scrollToEndOptions: (~animated: bool=?, unit) => scrollToEndOptions =
  "";
[@bs.send] external scrollToEnd: element => unit = "scrollToEnd";
[@bs.send]
external scrollToEndWithOptions: (ref, scrollToEndOptions) => unit =
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

[@bs.send] external recordInteraction: element => unit = "";

[@bs.send] external flashScrollIndicators: element => unit = "";
