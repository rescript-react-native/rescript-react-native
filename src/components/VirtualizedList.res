include VirtualizedListElement

type renderItemProps<'item> = {
  item: 'item,
  index: int,
  // separators: TODO
}

type renderItemCallback<'item> = renderItemProps<'item> => React.element

// TODO
type cellRendererComponentProps<'item> = {.}
type cellRendererComponent<'item> = React.component<cellRendererComponentProps<'item>>

type viewableItem<'item> = {
  item: 'item,
  key: string,
  index: Js.undefined<int>,
  isViewable: bool,
  section: {.},
}

type viewableItemsChanged<'item> = {
  viewableItems: array<viewableItem<'item>>,
  changed: array<viewableItem<'item>>,
}

type itemLayout = {
  length: float,
  offset: float,
  index: int,
}

type onEndReachedParams = {distanceFromEnd: float}

type onScrollToIndexFailedInfo = {
  index: int,
  highestMeasuredFrameIndex: int,
  averageItemLength: float,
}

type onScrollToIndexFailedParams = {info: onScrollToIndexFailedInfo}

type viewabilityConfig
@obj
external viewabilityConfig: (
  ~minimumViewTime: float=?,
  ~viewAreaCoveragePercentThreshold: float=?,
  ~itemVisiblePercentThreshold: float=?,
  ~waitForInteraction: bool=?,
  unit,
) => viewabilityConfig = ""

type viewabilityConfigCallbackPair<'item>
@obj
external viewabilityConfigCallbackPair: (
  ~viewabilityConfig: viewabilityConfig,
  ~onViewableItemsChanged: viewableItemsChanged<'item> => unit,
) => viewabilityConfigCallbackPair<'item> = ""

type viewabilityConfigCallbackPairs<'item> = array<viewabilityConfigCallbackPair<'item>>

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  ~_CellRendererComponent: // VirtualizedList props
  cellRendererComponent<'item>=?,
  ~_ListEmptyComponent: unit => React.element=?,
  ~_ListFooterComponent: unit => React.element=?,
  ~_ListFooterComponentStyle: Style.t=?,
  ~_ListHeaderComponent: unit => React.element=?,
  ~_ListHeaderComponentStyle: Style.t=?,
  ~debug: bool=?,
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
  ~onViewableItemsChanged: viewableItemsChanged<'item> => unit=?,
  ~progressViewOffset: float=?,
  ~refreshing: bool=?,
  ~renderItem: renderItemCallback<'item>,
  ~renderScrollComponent: unit => React.element=?, // TODO: params?
  ~updateCellsBatchingPeriod: float=?,
  ~viewabilityConfig: viewabilityConfig=?,
  ~viewabilityConfigCallbackPairs: viewabilityConfigCallbackPairs<'item>=?,
  ~windowSize: int=?,
  ~alwaysBounceHorizontal: // ScrollView props
  bool=?,
  ~alwaysBounceVertical: bool=?,
  ~automaticallyAdjustContentInsets: bool=?,
  ~bounces: bool=?,
  ~bouncesZoom: bool=?,
  ~canCancelContentTouches: bool=?,
  ~centerContent: bool=?,
  ~contentContainerStyle: Style.t=?,
  ~contentInset: View.edgeInsets=?,
  ~contentInsetAdjustmentBehavior: ScrollView.contentInsetAdjustmentBehavior=?,
  ~contentOffset: ScrollView.contentOffset=?,
  ~decelerationRate: ScrollView.decelerationRate=?,
  ~directionalLockEnabled: bool=?,
  ~endFillColor: Color.t=?,
  ~fadingEdgeLength: float=?,
  ~horizontal: bool=?,
  ~indicatorStyle: ScrollView.indicatorStyle=?,
  ~keyboardDismissMode: @string
  [
    | #none
    | #interactive
    | @as("on-drag") #onDrag
  ]=?,
  ~keyboardShouldPersistTaps: ScrollView.keyboardShouldPersistTaps=?,
  ~maximumZoomScale: float=?,
  ~minimumZoomScale: float=?,
  ~nestedScrollEnabled: bool=?,
  ~onContentSizeChange: ((float, float)) => unit=?,
  ~onMomentumScrollBegin: Event.scrollEvent => unit=?,
  ~onMomentumScrollEnd: Event.scrollEvent => unit=?,
  ~onScroll: Event.scrollEvent => unit=?,
  ~onScrollBeginDrag: Event.scrollEvent => unit=?,
  ~onScrollEndDrag: Event.scrollEvent => unit=?,
  ~overScrollMode: ScrollView.overScrollMode=?,
  ~pagingEnabled: bool=?,
  ~pinchGestureEnabled: bool=?,
  ~refreshControl: React.element=?,
  ~scrollEnabled: bool=?,
  ~scrollEventThrottle: int=?,
  ~scrollIndicatorInsets: View.edgeInsets=?,
  ~scrollPerfTag: string=?,
  ~scrollsToTop: bool=?,
  ~scrollToOverflowEnabled: bool=?,
  ~showsHorizontalScrollIndicator: bool=?,
  ~showsVerticalScrollIndicator: bool=?,
  ~snapToAlignment: ScrollView.snapToAlignment=?,
  ~snapToEnd: bool=?,
  ~snapToInterval: float=?,
  ~snapToOffsets: array<float>=?,
  ~snapToStart: bool=?,
  ~stickyHeaderIndices: array<int>=?,
  ~zoomScale: float=?,
  ~accessibilityActions: // View props 0.63.0
  array<Accessibility.actionInfo>=?,
  ~accessibilityElementsHidden: bool=?,
  ~accessibilityHint: string=?,
  ~accessibilityIgnoresInvertColors: bool=?,
  ~accessibilityLabel: string=?,
  ~accessibilityLiveRegion: Accessibility.liveRegion=?,
  ~accessibilityRole: Accessibility.role=?,
  ~accessibilityState: Accessibility.state=?,
  ~accessibilityValue: Accessibility.value=?,
  ~accessibilityViewIsModal: bool=?,
  ~accessible: bool=?,
  ~collapsable: bool=?,
  ~hitSlop: View.edgeInsets=?,
  ~importantForAccessibility: @string
  [
    | #auto
    | #yes
    | #no
    | @as("no-hide-descendants") #noHideDescendants
  ]=?,
  ~nativeID: string=?,
  ~needsOffscreenAlphaCompositing: bool=?,
  ~onAccessibilityAction: Accessibility.actionEvent => unit=?,
  ~onAccessibilityEscape: unit => unit=?,
  ~onAccessibilityTap: unit => unit=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onMagicTap: unit => unit=?,
  ~onMoveShouldSetResponder: // Gesture Responder props
  Event.pressEvent => bool=?,
  ~onMoveShouldSetResponderCapture: Event.pressEvent => bool=?,
  ~onResponderEnd: Event.pressEvent => unit=?,
  ~onResponderGrant: Event.pressEvent => unit=?,
  ~onResponderMove: Event.pressEvent => unit=?,
  ~onResponderReject: Event.pressEvent => unit=?,
  ~onResponderRelease: Event.pressEvent => unit=?,
  ~onResponderStart: Event.pressEvent => unit=?,
  ~onResponderTerminate: Event.pressEvent => unit=?,
  ~onResponderTerminationRequest: Event.pressEvent => bool=?,
  ~onStartShouldSetResponder: Event.pressEvent => bool=?,
  ~onStartShouldSetResponderCapture: Event.pressEvent => bool=?,
  ~pointerEvents: @string
  [
    | #auto
    | #none
    | @as("box-none") #boxNone
    | @as("box-only") #boxOnly
  ]=?,
  ~removeClippedSubviews: bool=?,
  ~renderToHardwareTextureAndroid: bool=?,
  ~shouldRasterizeIOS: bool=?,
  ~style: Style.t=?,
  ~testID: string=?,
  ~children: React.element=?,
  ~onMouseDown: // React Native Web Props
  ReactEvent.Mouse.t => unit=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onMouseMove: ReactEvent.Mouse.t => unit=?,
  ~onMouseOver: ReactEvent.Mouse.t => unit=?,
  ~onMouseOut: ReactEvent.Mouse.t => unit=?,
  ~onMouseUp: ReactEvent.Mouse.t => unit=?,
) => React.element = "VirtualizedList"
