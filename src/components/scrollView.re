module type ScrollViewComponent = {
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
      ~keyboardDismissMode: [ | `none | `interactive | `onDrag]=?,
      ~keyboardShouldPersistTaps: [ | `always | `never | `handled]=?,
      ~onContentSizeChange: ((float, float)) => unit=?,
      ~onScroll: RNEvent.NativeScrollEvent.t => unit=?,
      ~pagingEnabled: bool=?,
      ~refreshControl: ReasonReact.reactElement=?,
      ~scrollEnabled: bool=?,
      ~showsHorizontalScrollIndicator: bool=?,
      ~showsVerticalScrollIndicator: bool=?,
      ~stickyHeaderIndices: list(int)=?,
      ~overScrollMode: [ | `always | `never | `auto]=?,
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
      ~indicatorStyle: [ | `default | `black | `white]=?,
      ~maximumZoomScale: float=?,
      ~minimumZoomScale: float=?,
      ~onScrollAnimationEnd: unit => unit=?,
      ~scrollEventThrottle: int=?,
      ~scrollIndicatorInsets: Types.insets=?,
      ~scrollsToTop: bool=?,
      ~snapToInterval: float=?,
      ~snapToAlignment: [ | `center | `start | `end_]=?,
      ~zoomScale: float=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent = (Impl: View.Impl) : ScrollViewComponent => {
  type point = {
    x: float,
    y: float,
  };
  [@bs.send]
  external _scrollTo:
    (
      ReasonReact.reactRef,
      {
        .
        "x": int,
        "y": int,
        "animated": bool,
      }
    ) =>
    unit =
    "scrollTo";
  [@bs.send]
  external _scrollToEnd: (ReasonReact.reactRef, {. "animated": bool}) => unit =
    "scrollToEnd";
  let scrollTo = (ref, ~x, ~y, ~animated) =>
    _scrollTo(ref, {"x": x, "y": y, "animated": animated});
  let scrollToEnd = (ref, ~animated) =>
    _scrollToEnd(ref, {"animated": animated});
  let make =
      (
        ~accessibilityLabel=?,
        ~accessible=?,
        ~hitSlop=?,
        ~onAccessibilityTap=?,
        ~onLayout=?,
        ~onMagicTap=?,
        ~responderHandlers=?,
        ~pointerEvents=?,
        ~removeClippedSubviews=?,
        ~style=?,
        ~testID=?,
        ~accessibilityComponentType=?,
        ~accessibilityLiveRegion=?,
        ~collapsable=?,
        ~importantForAccessibility=?,
        ~needsOffscreenAlphaCompositing=?,
        ~renderToHardwareTextureAndroid=?,
        ~accessibilityTraits=?,
        ~accessibilityViewIsModal=?,
        ~shouldRasterizeIOS=?,
        ~contentContainerStyle=?,
        ~horizontal=?,
        ~keyboardDismissMode=?,
        ~keyboardShouldPersistTaps=?,
        ~onContentSizeChange=?,
        ~onScroll=?,
        ~pagingEnabled=?,
        ~refreshControl=?,
        ~scrollEnabled=?,
        ~showsHorizontalScrollIndicator=?,
        ~showsVerticalScrollIndicator=?,
        ~stickyHeaderIndices=?,
        ~overScrollMode=?,
        ~scrollPerfTag=?,
        ~alwaysBounceHorizontal=?,
        ~alwaysBounceVertical=?,
        ~automaticallyAdjustContentInsets=?,
        ~bounces=?,
        ~canCancelContentTouches=?,
        ~centerContent=?,
        ~contentInset=?,
        ~contentOffset=?,
        ~decelerationRate=?,
        ~directionalLockEnabled=?,
        ~indicatorStyle=?,
        ~maximumZoomScale=?,
        ~minimumZoomScale=?,
        ~onScrollAnimationEnd=?,
        ~scrollEventThrottle=?,
        ~scrollIndicatorInsets=?,
        ~scrollsToTop=?,
        ~snapToInterval=?,
        ~snapToAlignment=?,
        ~zoomScale=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props=
        Props.extendView(
          {
            "contentContainerStyle": contentContainerStyle,
            "horizontal": horizontal,
            "keyboardDismissMode":
              keyboardDismissMode
              ->Belt.Option.map(
                  fun
                  | `interactive => "interactive"
                  | `none => "none"
                  | `onDrag => "on-drag",
                ),
            "keyboardShouldPersistTaps":
              keyboardShouldPersistTaps
              ->Belt.Option.map(
                  fun
                  | `always => "always"
                  | `never => "never"
                  | `handled => "handled",
                ),
            "onContentSizeChange": onContentSizeChange,
            "onScroll": onScroll,
            "pagingEnabled": pagingEnabled,
            "refreshControl": refreshControl,
            "scrollEnabled": scrollEnabled,
            "showsHorizontalScrollIndicator": showsHorizontalScrollIndicator,
            "showsVerticalScrollIndicator": showsVerticalScrollIndicator,
            "stickyHeaderIndices":
              stickyHeaderIndices->Belt.Option.map(Belt.List.toArray),
            "overScrollMode":
              overScrollMode
              ->Belt.Option.map(
                  fun
                  | `always => "always"
                  | `never => "never"
                  | `auto => "auto",
                ),
            "scrollPerfTag": scrollPerfTag,
            "alwaysBounceHorizontal": alwaysBounceHorizontal,
            "alwaysBounceVertical": alwaysBounceVertical,
            "automaticallyAdjustContentInsets": automaticallyAdjustContentInsets,
            "bounces": bounces,
            "canCancelContentTouches": canCancelContentTouches,
            "centerContent": centerContent,
            "contentInset": contentInset,
            "contentOffset":
              contentOffset->Belt.Option.map(({x, y}) => {"x": x, "y": y}),
            "decelerationRate":
              decelerationRate
              ->Belt.Option.map(
                  fun
                  | `fast => "fast"
                  | `normal => "normal",
                ),
            "directionalLockEnabled": directionalLockEnabled,
            "indicatorStyle":
              indicatorStyle
              ->Belt.Option.map(
                  fun
                  | `default => "default"
                  | `black => "black"
                  | `white => "white",
                ),
            "maximumZoomScale": maximumZoomScale,
            "minimumZoomScale": minimumZoomScale,
            "onScrollAnimationEnd": onScrollAnimationEnd,
            "scrollEventThrottle": scrollEventThrottle,
            "scrollIndicatorInsets": scrollIndicatorInsets,
            "scrollsToTop": scrollsToTop,
            "snapToInterval": snapToInterval,
            "snapToAlignment":
              snapToAlignment
              ->Belt.Option.map(
                  fun
                  | `center => "center"
                  | `start => "start"
                  | `end_ => "end",
                ),
            "zoomScale": zoomScale,
          },
          ~accessibilityLabel?,
          ~accessible?,
          ~hitSlop?,
          ~onAccessibilityTap?,
          ~onLayout?,
          ~onMagicTap?,
          ~responderHandlers?,
          ~pointerEvents?,
          ~removeClippedSubviews?,
          ~style?,
          ~testID?,
          ~accessibilityComponentType?,
          ~accessibilityLiveRegion?,
          ~collapsable?,
          ~importantForAccessibility?,
          ~needsOffscreenAlphaCompositing?,
          ~renderToHardwareTextureAndroid?,
          ~accessibilityTraits?,
          ~accessibilityViewIsModal?,
          ~shouldRasterizeIOS?,
        ),
    );
};

include CreateComponent({
  [@bs.module "react-native"]
  external view: ReasonReact.reactClass = "ScrollView";
});
