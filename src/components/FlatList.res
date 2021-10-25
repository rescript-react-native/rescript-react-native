// VirtualizedList props data, getItem, getItemCount and getItemLayout
// are not supported on FlatList
// FlatList has its own data prop, specified as array(item)

include VirtualizedListElement

type separatorComponentProps<'item> = {"highlighted": bool, "leadingItem": option<'item>}

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // FlatList props
  ~_ItemSeparatorComponent: React.component<separatorComponentProps<'item>>=?,
  ~columnWrapperStyle: Style.t=?,
  ~data: array<'item>,
  ~getItemLayout: (array<'item>, int) => VirtualizedList.itemLayout=?,
  ~numColumns: 'int=?,
  // VirtualizedList props
  // ~_CellRendererComponent: VirtualizedList.cellRendererComponent('item)=?,
  ~_ListEmptyComponent: unit => React.element=?,
  ~_ListFooterComponent: unit => React.element=?,
  ~_ListFooterComponentStyle: Style.t=?,
  ~_ListHeaderComponent: unit => React.element=?,
  ~_ListHeaderComponentStyle: Style.t=?,
  ~debug: bool=?,
  // ~data: 'data, // any collection of 'item
  ~disableVirtualization: bool=?, // deprecated
  ~extraData: 'extraData=?,
  // ~getItem: ('data, int) => 'item=?,
  // ~getItemCount: 'data => int=?,
  ~initialNumToRender: // ~getItemLayout: ('data, int) => VirtualizedList.itemLayout=?,
  int=?,
  ~initialScrollIndex: int=?,
  ~inverted: bool=?,
  ~keyExtractor: ('item, int) => string,
  ~maxToRenderPerBatch: int=?,
  ~onEndReached: VirtualizedList.onEndReachedParams => unit=?,
  ~onEndReachedThreshold: float=?,
  ~onRefresh: unit => unit=?,
  ~onScrollToIndexFailed: VirtualizedList.onScrollToIndexFailedParams => unit=?,
  ~onViewableItemsChanged: VirtualizedList.viewableItemsChanged<'item> => unit=?,
  ~progressViewOffset: float=?,
  ~refreshing: bool=?,
  ~renderItem: VirtualizedList.renderItemCallback<'item>,
  ~renderScrollComponent: unit => React.element=?, // TODO: params?
  ~updateCellsBatchingPeriod: float=?,
  ~viewabilityConfig: VirtualizedList.viewabilityConfig=?,
  ~viewabilityConfigCallbackPairs: VirtualizedList.viewabilityConfigCallbackPairs<'item>=?,
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
  ~stickyHeaderHiddenOnScroll: bool=?,
  ~stickyHeaderIndices: array<int>=?,
  ~zoomScale: float=?,
  // rescript-react-native 0.64 || 0.65 || 0.66 View props
  ~accessibilityActions: array<Accessibility.actionInfo>=?,
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
  // react-native-web 0.16 View props
  ~href: string=?,
  ~hrefAttrs: Web.hrefAttrs=?,
  ~onMouseDown: ReactEvent.Mouse.t => unit=?,
  ~onMouseEnter: ReactEvent.Mouse.t => unit=?,
  ~onMouseLeave: ReactEvent.Mouse.t => unit=?,
  ~onMouseMove: ReactEvent.Mouse.t => unit=?,
  ~onMouseOver: ReactEvent.Mouse.t => unit=?,
  ~onMouseOut: ReactEvent.Mouse.t => unit=?,
  ~onMouseUp: ReactEvent.Mouse.t => unit=?,
) => React.element = "FlatList"
