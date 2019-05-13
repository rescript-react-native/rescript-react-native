open ScrollViewProps;

type point = ReactNative.ScrollView.contentOffset;

let scrollTo:
  (ReasonReact.reactRef, ~x: int, ~y: int, ~animated: bool) => unit;

let scrollToEnd: (ReasonReact.reactRef, ~animated: bool) => unit;

[@react.component]
let make:
  (
    ~accessibilityLabel: string=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: Types.pointerEvents=?,
    ~removeClippedSubviews: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~accessibilityComponentType: Types.accessibilityComponentType=?,
    ~accessibilityLiveRegion: Types.accessibilityLiveRegion=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: Types.importantForAccessibility=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(Types.accessibilityTrait)=?,
    ~accessibilityRole: Types.accessibilityRole=?,
    ~accessibilityStates: list(Types.accessibilityState)=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~contentInsetAdjustmentBehavior: contentInsetAdjustmentBehavior=?,
    ~contentContainerStyle: Style.t=?,
    ~horizontal: bool=?,
    ~keyboardDismissMode: [ | `none | `interactive | `onDrag]=?,
    ~keyboardShouldPersistTaps: [ | `always | `never | `handled]=?,
    ~onContentSizeChange: ((float, float)) => unit=?,
    ~onScroll: RNEvent.NativeScrollEvent.t => unit=?,
    ~onScrollBeginDrag: RNEvent.NativeScrollEvent.t => unit=?,
    ~onScrollEndDrag: RNEvent.NativeScrollEvent.t => unit=?,
    ~onMomentumScrollBegin: RNEvent.NativeScrollEvent.t => unit=?,
    ~onMomentumScrollEnd: RNEvent.NativeScrollEvent.t => unit=?,
    ~pagingEnabled: bool=?,
    ~refreshControl: React.element=?,
    ~scrollEnabled: bool=?,
    ~showsHorizontalScrollIndicator: bool=?,
    ~showsVerticalScrollIndicator: bool=?,
    ~stickyHeaderIndices: list(int)=?,
    ~overScrollMode: overScrollMode=?,
    ~scrollPerfTag: string=?,
    ~alwaysBounceHorizontal: bool=?,
    ~alwaysBounceVertical: bool=?,
    ~automaticallyAdjustContentInsets: bool=?,
    ~bounces: bool=?,
    ~canCancelContentTouches: bool=?,
    ~centerContent: bool=?,
    ~contentInset: Types.insets=?,
    ~contentOffset: point=?,
    ~decelerationRate: decelerationRate=?,
    ~directionalLockEnabled: bool=?,
    ~indicatorStyle: indicatorStyle=?,
    ~maximumZoomScale: float=?,
    ~minimumZoomScale: float=?,
    ~scrollEventThrottle: int=?,
    ~scrollIndicatorInsets: Types.insets=?,
    ~scrollsToTop: bool=?,
    ~snapToInterval: float=?,
    ~snapToAlignment: snapToAlignment=?,
    ~zoomScale: float=?,
    ~children: React.element=?,
    unit
  ) =>
  React.element;
