open ScrollViewProps;

module type ScrollViewComponent = {
  /**
  Component that wraps platform [ScrollView] while providing integration with touch locking "responder" system.
  ScrollView simply renders all its react child components at once. That makes it very easy to understand and use.
  You can read more on [ScrollView] component usage in official docs: {{:https://facebook.github.io/react-native/docs/scrollview}}

  {3 Props}

  {{:\BsReactNative/View-BsReactNative} [View] props}

  {4 contentContainerStyle}
  {[
    ~contentContainerStyle: Style.t=?
  ]}

  {4 contentInsetAdjustmentBehavior}
  {[
    ~contentInsetAdjustmentBehavior: [
      | `automatic
      | `scrollableAxes
      | `never
      | `always
    ]=?,
  ]}

  {4 horizontal}
  {[
    ~horizontal: bool=?,
  ]}
  {4 keyboardDismissMode}
  {[
    ~keyboardDismissMode: [
      | `interactive
      | `none
      | `onDrag
    ]=?,
  ]}
  {4 keyboardShouldPersistTaps}
  {[
    ~keyboardShouldPersistTaps: [
      | `always
      | `handled
      | `never
    ]=?,
  ]}
  {4 onContentSizeChange}
  {[
    ~onContentSizeChange: ((float, float)) => unit=?,
  ]}

  {4 onScroll}
  {[
    ~onScroll: RNEvent.NativeScrollEvent.t => unit=?,
  ]}
  Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeScrollEvent/} [RNEvent.NativeScrollEvent]}

  {4 onScrollBeginDrag}
  {[
    ~onScrollBeginDrag: RNEvent.NativeScrollEvent.t => unit=?,
  ]}
  Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeScrollEvent/} [RNEvent.NativeScrollEvent]}

  {4 onScrollEndDrag}
  {[
    ~onScrollEndDrag: RNEvent.NativeScrollEvent.t => unit=?,
  ]}
  Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeScrollEvent/} [RNEvent.NativeScrollEvent]}

  {4 onMomentumScrollBegin}
  {[
    ~onMomentumScrollBegin: RNEvent.NativeScrollEvent.t => unit=?,
  ]}
  Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeScrollEvent/} [RNEvent.NativeScrollEvent]}

  {4 onMomentumScrollEnd}
  {[
    ~onMomentumScrollEnd: RNEvent.NativeScrollEvent.t => unit=?,
  ]}
  Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeScrollEvent/} [RNEvent.NativeScrollEvent]}

  {4 pagingEnabled}
  {[
    ~pagingEnabled: bool=?,
  ]}
  {4 refreshControl}
  {[
    ~refreshControl: ReasonReact.reactElement=?,
  ]}
  {4 scrollEnabled}
  {[
    ~scrollEnabled: bool=?,
  ]}
  {4 showsHorizontalScrollIndicator}
  {[
    ~showsHorizontalScrollIndicator: bool=?,
  ]}
  {4 stickyHeaderIndices}
  {[
    ~stickyHeaderIndices: list(int)=?,
  ]}
  {4 overScrollMode}
  {[
    ~overScrollMode: [
      | `always
      | `auto
      | `never
    ]=?,
  ]}
  {4 scrollPerfTag}
  {[
    ~scrollPerfTag: string=?,
  ]}
  {4 alwaysBounceHorizontal}
  {[
    ~alwaysBounceHorizontal: bool=?,
  ]}
  {4 alwaysBounceVertical}
  {[
    ~alwaysBounceVertical: bool=?,
  ]}
  {4 automaticallyAdjustContentInsets}
  {[
    ~automaticallyAdjustContentInsets: bool=?,
  ]}
  {4 bounces}
  {[
    ~bounces: bool=?,
  ]}
  {4 canCancelContentTouches}
  {[
    ~canCancelContentTouches: bool=?,
  ]}
  {4 centerContent}
  {[
    ~centerContent: bool=?,
  ]}
  {4 contentInset}
  {[
    ~contentInset: Types.insets=?,
  ]}
  {4 contentOffset}
  {[
    ~contentOffset: point=?,
  ]}
  reference:
  {[
    type point = {
      x: float,
      y: float
    };
  ]}
  {4 decelerationRate}
  {[
    ~decelerationRate: [
      | `fast
      | `normal
    ]=?,
  ]}
  {4 directionalLockEnabled}
  {[
    ~directionalLockEnabled: bool=?,
  ]}
  {4 indicatorStyle}
  {[
    ~indicatorStyle: [ | `black | `default | `white]=?,
  ]}
  {4 maximumZoomScale}
  {[
    ~maximumZoomScale: float=?,
  ]}
  {4 minimumZoomScale}
  {[
    ~minimumZoomScale: float=?,
  ]}
  {4 scrollEventThrottle}
  {[
    ~scrollEventThrottle: int=?,
  ]}
  {4 scrollIndicatorInsets}
  {[
    ~scrollIndicatorInsets: Types.insets=?,
  ]}
  reference:
  {4 Types.rei}
  {[
    type insets = {
      .
      "left": int,
      "right": int,
      "top": int,
      "bottom": int,
    };
  ]}
  {4 scrollsToTop}
  {[
    ~scrollsToTop: bool=?,
  ]}
  {4 snapToInterval}
  {[
    ~snapToInterval: float=?,
  ]}
  {4 snapToAlignment}
  {[
    ~snapToAlignment: [
      | `center
      | `end_
      | `start
    ]=?,
  ]}
  {4 zoomScale }
  {[
    ~zoomScale: float=?,
  ]}

   */

  type point = {
    x: float,
    y: float,
  };

  /**
{3 Methods}

{4 scrollTo}
 */

  let scrollTo:
    (ReasonReact.reactRef, ~x: int, ~y: int, ~animated: bool) => unit;

  /**
    {4 scrollToEnd}
    */
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
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent: (Impl: View.Impl) => ScrollViewComponent;

include ScrollViewComponent;
