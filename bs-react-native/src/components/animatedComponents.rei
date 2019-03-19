open ScrollViewProps;

module View: View.ViewComponent;

module Image: Image.ImageComponent;

module Text: Text.TextComponent;

module FlatList: FlatList.FlatListComponent;

module ScrollView: {
  let onScrollUpdater:
    (~x: 'a=?, ~y: 'b=?, ~native: bool=?, unit, RNEvent.NativeScrollEvent.t) =>
    unit;
  type point = {
    x: float,
    y: float,
  };
  let scrollTo:
    (ReasonReact.reactRef, ~x: int, ~y: int, ~animated: bool) => unit;
  let scrollToEnd: (ReasonReact.reactRef, ~animated: bool) => unit;
  let make:
    (
      ~accessibilityLabel: ReasonReact.reactElement=?,
      ~accessible: bool=?,
      ~contentInsetAdjustmentBehavior: contentInsetAdjustmentBehavior=?,
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
      ~contentContainerStyle: Style.t=?,
      ~horizontal: bool=?,
      ~keyboardDismissMode: keyboardDismissMode=?,
      ~keyboardShouldPersistTaps: keyboardShouldPersistTaps=?,
      ~onContentSizeChange: ((float, float)) => unit=?,
      ~onScroll: RNEvent.NativeScrollEvent.t => unit=?,
      ~onScrollBeginDrag: RNEvent.NativeScrollEvent.t => unit=?,
      ~onScrollEndDrag: RNEvent.NativeScrollEvent.t => unit=?,
      ~onMomentumScrollBegin: RNEvent.NativeScrollEvent.t => unit=?,
      ~onMomentumScrollEnd: RNEvent.NativeScrollEvent.t => unit=?,
      ~pagingEnabled: bool=?,
      ~refreshControl: ReasonReact.reactElement=?,
      ~scrollEnabled: bool=?,
      ~showsHorizontalScrollIndicator: bool=?,
      ~showsVerticalScrollIndicator: bool=?,
      ~stickyHeaderIndices: list(int)=?,
      ~overScrollMode: [ | `always | `auto | `never]=?,
      ~scrollPerfTag: string=?,
      ~alwaysBounceHorizontal: bool=?,
      ~alwaysBounceVertical: bool=?,
      ~automaticallyAdjustContentInsets: bool=?,
      ~bounces: bool=?,
      ~canCancelContentTouches: bool=?,
      ~centerContent: bool=?,
      ~contentInset: Types.insets=?,
      ~contentOffset: point=?,
      ~decelerationRate: [ | `fast | `normal]=?,
      ~directionalLockEnabled: bool=?,
      ~indicatorStyle: [ | `black | `default | `white]=?,
      ~maximumZoomScale: float=?,
      ~minimumZoomScale: float=?,
      ~scrollEventThrottle: int=?,
      ~scrollIndicatorInsets: Types.insets=?,
      ~scrollsToTop: bool=?,
      ~snapToInterval: float=?,
      ~snapToAlignment: snapToAlignment=?,
      ~zoomScale: float=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};
