include ScrollViewElement

type contentOffset = {x: float, y: float}
@deprecated("Directly create record instead") @obj
external contentOffset: (~x: float, ~y: float) => contentOffset = ""

type contentInsetAdjustmentBehavior = [
  | #automatic
  | #scrollableAxes
  | #never
  | #always
]

type decelerationRate = [#fast | #normal]

type indicatorStyle = [#default | #black | #white]

type keyboardDismissMode = [
  | #none
  | #interactive
  | #"on-drag"
]

type keyboardShouldPersistTaps = [#always | #never | #handled]

type overScrollMode = [#always | #never | #auto]

type snapToAlignment = [#start | #center | #end]

type maintainVisibleContentPosition = {
  autoscrollToTopThreshold?: float,
  minIndexForVisible: int,
}

type iosProps = {
  alwaysBounceHorizontal?: bool,
  alwaysBounceVertical?: bool,
  automaticallyAdjustContentInsets?: bool,
  automaticallyAdjustKeyboardInsets?: bool,
  automaticallyAdjustsScrollIndicatorInsets?: bool,
  bounces?: bool,
  bouncesZoom?: bool,
  canCancelContentTouches?: bool,
  centerContent?: bool,
  contentInset?: Rect.t,
  contentOffset?: contentOffset,
  contentInsetAdjustmentBehavior?: contentInsetAdjustmentBehavior,
  directionalLockEnabled?: bool,
  indicatorStyle?: indicatorStyle,
  maintainVisibleContentPosition?: maintainVisibleContentPosition,
  maximumZoomScale?: float,
  minimumZoomScale?: float,
  onScrollAnimationEnd?: unit => unit,
  pinchGestureEnabled?: bool,
  scrollEventThrottle?: int,
  scrollIndicatorInsets?: Rect.t,
  scrollToOverflowEnabled?: bool,
  scrollsToTop?: bool,
  snapToAlignment?: snapToAlignment,
  onScrollToTop?: Event.scrollEvent => unit,
  zoomScale?: float,
}

type androidProps = {
  endFillColor?: Color.t,
  scrollPerfTag?: string,
  overScrollMode?: overScrollMode,
  nestedScrollEnabled?: bool,
  fadingEdgeLength?: float,
  persistentScrollbar?: bool,
}

type scrollViewProps = {
  ...View.viewProps,
  ...iosProps,
  ...androidProps,
  contentContainerStyle?: Style.t,
  decelerationRate?: decelerationRate,
  horizontal?: bool,
  invertStickyHeaders?: bool,
  keyboardDismissMode?: keyboardDismissMode,
  keyboardShouldPersistTaps?: keyboardShouldPersistTaps,
  onContentSizeChange?: ((float, float)) => unit,
  onScroll?: Event.scrollEvent => unit,
  onScrollBeginDrag?: Event.scrollEvent => unit,
  onScrollEndDrag?: Event.scrollEvent => unit,
  onMomentumScrollEnd?: Event.scrollEvent => unit,
  onMomentumScrollBegin?: Event.scrollEvent => unit,
  pagingEnabled?: bool,
  scrollEnabled?: bool,
  showsHorizontalScrollIndicator?: bool,
  showsVerticalScrollIndicator?: bool,
  stickyHeaderHiddenOnScroll?: bool,
  refreshControl?: React.element,
  snapToInterval?: float,
  snapToOffsets?: array<float>,
  snapToStart?: bool,
  snapToEnd?: bool,
  stickyHeaderIndices?: array<int>,
  disableIntervalMomentum?: bool,
  disableScrollViewPanResponder?: bool,
  \"StickyHeaderComponent"?: React.element,
}

type props = {
  ref?: ref,
  ...scrollViewProps,
}

@module("react-native")
external make: React.component<props> = "ScrollView"
