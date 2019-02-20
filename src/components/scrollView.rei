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
  reference:
  {4 RNEvent.rei}
  {[
    module NativeScrollEvent: {
      type t;
      type point = {
        x: float,
        y: float
      };
      type size = {
        width: float,
        height: float
      };
      type contentInset = {
        bottom: float,
        top: float,
        left: float,
        right: float
      };
      let contentOffset: t => point;
      let contentSize: t => size;
      let contentInset: t => contentInset;
      let layoutMeasurement: t => size;
    };
  ]}
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
  {4 onScrollAnimationEnd}
  {[
    ~onScrollAnimationEnd: unit => unit=?,
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
      ~accessibilityViewIsModal: bool=?,
      ~shouldRasterizeIOS: bool=?,
      ~contentContainerStyle: Style.t=?,
      ~horizontal: bool=?,
      ~keyboardDismissMode: [ | `interactive | `none | `onDrag]=?,
      ~keyboardShouldPersistTaps: [ | `always | `handled | `never]=?,
      ~onContentSizeChange: ((float, float)) => unit=?,
      ~onScroll: RNEvent.NativeScrollEvent.t => unit=?,
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
      ~onScrollAnimationEnd: unit => unit=?,
      ~scrollEventThrottle: int=?,
      ~scrollIndicatorInsets: Types.insets=?,
      ~scrollsToTop: bool=?,
      ~snapToAlignment: [ | `center | `end_ | `start]=?,
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
