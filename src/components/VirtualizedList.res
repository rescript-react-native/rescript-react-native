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

type viewabilityConfig = {
  minimumViewTime?: float,
  viewAreaCoveragePercentThreshold?: float,
  itemVisiblePercentThreshold?: float,
  waitForInteraction?: bool,
}

type viewabilityConfigCallbackPair<'item> = {
  viewabilityConfig: viewabilityConfig,
  onViewableItemsChanged: viewableItemsChanged<'item> => unit,
}

@obj
external // @deprecated("Directly create record instead")
viewabilityConfigCallbackPair: (
  ~viewabilityConfig: viewabilityConfig,
  ~onViewableItemsChanged: viewableItemsChanged<'item> => unit,
) => viewabilityConfigCallbackPair<'item> = ""

type viewabilityConfigCallbackPairs<'item> = array<viewabilityConfigCallbackPair<'item>>

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // VirtualizedList props
  ~\"CellRendererComponent": cellRendererComponent<'item>=?,
  ~\"ListEmptyComponent": unit => React.element=?,
  ~\"ListFooterComponent": unit => React.element=?,
  ~\"ListFooterComponentStyle": Style.t=?,
  ~\"ListHeaderComponent": unit => React.element=?,
  ~\"ListHeaderComponentStyle": Style.t=?,
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
  // ScrollView props
  ~alwaysBounceHorizontal: bool=?,
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
  ~keyboardDismissMode: ScrollView.keyboardDismissMode=?,
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
  ~stickyHeaderHiddenOnScroll: bool=?,
  ~stickyHeaderIndices: array<int>=?,
  ~zoomScale: float=?,
  // rescript-react-native 0.69 View props
  ~accessibilityActions: array<Accessibility.actionInfo>=?,
  ~accessibilityElementsHidden: bool=?,
  ~accessibilityHint: string=?,
  ~accessibilityIgnoresInvertColors: bool=?,
  ~accessibilityLabel: string=?,
  ~accessibilityLabelledBy: array<string>=?,
  ~accessibilityLanguage: string=?,
  ~accessibilityLiveRegion: Accessibility.liveRegion=?,
  ~accessibilityRole: Accessibility.role=?,
  ~accessibilityState: Accessibility.state=?,
  ~accessibilityValue: Accessibility.value=?,
  ~accessibilityViewIsModal: bool=?,
  ~accessible: bool=?,
  ~collapsable: bool=?,
  ~hitSlop: View.edgeInsets=?,
  ~importantForAccessibility: View.importantForAccessibility=?,
  ~nativeID: string=?,
  ~needsOffscreenAlphaCompositing: bool=?,
  ~onAccessibilityAction: Accessibility.actionEvent => unit=?,
  ~onAccessibilityEscape: unit => unit=?,
  ~onAccessibilityTap: unit => unit=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onMagicTap: unit => unit=?,
  // Gesture Responder props
  ~onMoveShouldSetResponder: Event.pressEvent => bool=?,
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
  ~pointerEvents: View.pointerEvents=?,
  ~removeClippedSubviews: bool=?,
  ~renderToHardwareTextureAndroid: bool=?,
  ~shouldRasterizeIOS: bool=?,
  ~style: Style.t=?,
  ~testID: string=?,
  ~children: React.element=?,
  // react-native-web 0.17 View props
  ~href: string=?,
  ~hrefAttrs: Web.hrefAttrs=?,
  // react-native-web 0.17 View props, ClickProps
  ~onClick: option<ReactEvent.Mouse.t => unit>=?,
  ~onClickCapture: option<ReactEvent.Mouse.t => unit>=?,
  ~onContextMenu: option<ReactEvent.Mouse.t => unit>=?,
  // react-native-web 0.17 View props, FocusProps
  ~onFocus: option<ReactEvent.Focus.t => unit>=?,
  ~onBlur: option<ReactEvent.Focus.t => unit>=?,
  // react-native-web 0.17 View props, KeyboardProps
  ~onKeyDown: option<ReactEvent.Keyboard.t => unit>=?,
  ~onKeyDownCapture: option<ReactEvent.Keyboard.t => unit>=?,
  ~onKeyUp: option<ReactEvent.Keyboard.t => unit>=?,
  ~onKeyUpCapture: option<ReactEvent.Keyboard.t => unit>=?,
  // react-native-web 0.17 View props, Mouse forwarded props
  ~onMouseDown: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseEnter: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseLeave: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseMove: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseOut: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseOver: option<ReactEvent.Mouse.t => unit>=?,
  ~onMouseUp: option<ReactEvent.Mouse.t => unit>=?,
) => React.element = "VirtualizedList"
