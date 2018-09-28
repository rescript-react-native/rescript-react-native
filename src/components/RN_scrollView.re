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
      ~hitSlop: RN_types.insets=?,
      ~onAccessibilityTap: unit => unit=?,
      ~onLayout: RN_Event.NativeLayoutEvent.t => unit=?,
      ~onMagicTap: unit => unit=?,
      ~responderHandlers: RN_types.touchResponderHandlers=?,
      ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
      ~removeClippedSubviews: bool=?,
      ~style: RN_style.t=?,
      ~testID: string=?,
      ~accessibilityComponentType: [
                                     | `none
                                     | `button
                                     | `radiobutton_checked
                                     | `radiobutton_unchecked
                                   ]
                                     =?,
      ~accessibilityLiveRegion: [ | `none | `polite | `assertive]=?,
      ~collapsable: bool=?,
      ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]
                                    =?,
      ~needsOffscreenAlphaCompositing: bool=?,
      ~renderToHardwareTextureAndroid: bool=?,
      ~accessibilityTraits: list(
                              [
                                | `none
                                | `button
                                | `link
                                | `header
                                | `search
                                | `image
                                | `selected
                                | `plays
                                | `key
                                | `text
                                | `summary
                                | `disabled
                                | `frequentUpdates
                                | `startsMedia
                                | `adjustable
                                | `allowsDirectInteraction
                                | `pageTurn
                              ],
                            )
                              =?,
      ~accessibilityViewIsModal: bool=?,
      ~shouldRasterizeIOS: bool=?,
      ~contentContainerStyle: RN_style.t=?,
      ~horizontal: bool=?,
      ~keyboardDismissMode: [ | `none | `interactive | `onDrag]=?,
      ~keyboardShouldPersistTaps: [ | `always | `never | `handled]=?,
      ~onContentSizeChange: ((float, float)) => unit=?,
      ~onScroll: RN_Event.NativeScrollEvent.t => unit=?,
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
      ~contentInset: RN_types.insets=?,
      ~contentOffset: point=?,
      ~decelerationRate: [ | `fast | `normal]=?,
      ~directionalLockEnabled: bool=?,
      ~indicatorStyle: [ | `default | `black | `white]=?,
      ~maximumZoomScale: float=?,
      ~minimumZoomScale: float=?,
      ~onScrollAnimationEnd: unit => unit=?,
      ~scrollEventThrottle: int=?,
      ~scrollIndicatorInsets: RN_types.insets=?,
      ~scrollsToTop: bool=?,
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

module CreateComponent = (Impl: RN_view.Impl) : ScrollViewComponent => {
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
              UtilsRN.option_map(
                x =>
                  switch (x) {
                  | `interactive => "interactive"
                  | `none => "none"
                  | `onDrag => "on-drag"
                  },
                keyboardDismissMode,
              ),
            "keyboardShouldPersistTaps":
              UtilsRN.option_map(
                x =>
                  switch (x) {
                  | `always => "always"
                  | `never => "never"
                  | `handled => "handled"
                  },
                keyboardShouldPersistTaps,
              ),
            "onContentSizeChange": onContentSizeChange,
            "onScroll": onScroll,
            "pagingEnabled": pagingEnabled,
            "refreshControl": refreshControl,
            "scrollEnabled": scrollEnabled,
            "showsHorizontalScrollIndicator": showsHorizontalScrollIndicator,
            "showsVerticalScrollIndicator": showsVerticalScrollIndicator,
            "stickyHeaderIndices":
              UtilsRN.option_map(Array.of_list, stickyHeaderIndices),
            "overScrollMode":
              UtilsRN.option_map(
                x =>
                  switch (x) {
                  | `always => "always"
                  | `never => "never"
                  | `auto => "auto"
                  },
                overScrollMode,
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
              UtilsRN.option_map(
                ({x, y}) => {"x": x, "y": y},
                contentOffset,
              ),
            "decelerationRate":
              UtilsRN.option_map(
                x =>
                  switch (x) {
                  | `fast => "fast"
                  | `normal => "normal"
                  },
                decelerationRate,
              ),
            "directionalLockEnabled": directionalLockEnabled,
            "indicatorStyle":
              UtilsRN.option_map(
                x =>
                  switch (x) {
                  | `default => "default"
                  | `black => "black"
                  | `white => "white"
                  },
                indicatorStyle,
              ),
            "maximumZoomScale": maximumZoomScale,
            "minimumZoomScale": minimumZoomScale,
            "onScrollAnimationEnd": onScrollAnimationEnd,
            "scrollEventThrottle": scrollEventThrottle,
            "scrollIndicatorInsets": scrollIndicatorInsets,
            "scrollsToTop": scrollsToTop,
            "snapToAlignment":
              UtilsRN.option_map(
                x =>
                  switch (x) {
                  | `center => "center"
                  | `start => "start"
                  | `end_ => "end"
                  },
                snapToAlignment,
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