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
      ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
      ~removeClippedSubviews: bool=?,
      ~style: Style.t=?,
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
  external _scrollTo :
    (
      ReasonReact.reactRef,
      {
        .
        "x": int,
        "y": int,
        "animated": Js.boolean,
      }
    ) =>
    unit =
    "scrollTo";
  [@bs.send]
  external _scrollToEnd :
    (ReasonReact.reactRef, {. "animated": Js.boolean}) => unit =
    "scrollToEnd";
  let scrollTo = (ref, ~x, ~y, ~animated) =>
    _scrollTo(
      ref,
      {"x": x, "y": y, "animated": Js.Boolean.to_js_boolean(animated)},
    );
  let scrollToEnd = (ref, ~animated) =>
    _scrollToEnd(ref, {"animated": Js.Boolean.to_js_boolean(animated)});
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
          Js.Undefined.(
            {
              "contentContainerStyle": fromOption(contentContainerStyle),
              "horizontal":
                fromOption(UtilsRN.optBoolToOptJsBoolean(horizontal)),
              "keyboardDismissMode":
                fromOption(
                  UtilsRN.option_map(
                    x =>
                      switch (x) {
                      | `interactive => "interactive"
                      | `none => "none"
                      | `onDrag => "on-drag"
                      },
                    keyboardDismissMode,
                  ),
                ),
              "keyboardShouldPersistTaps":
                fromOption(
                  UtilsRN.option_map(
                    x =>
                      switch (x) {
                      | `always => "always"
                      | `never => "never"
                      | `handled => "handled"
                      },
                    keyboardShouldPersistTaps,
                  ),
                ),
              "onContentSizeChange": fromOption(onContentSizeChange),
              "onScroll": fromOption(onScroll),
              "pagingEnabled":
                fromOption(UtilsRN.optBoolToOptJsBoolean(pagingEnabled)),
              "refreshControl": fromOption(refreshControl),
              "scrollEnabled":
                fromOption(UtilsRN.optBoolToOptJsBoolean(scrollEnabled)),
              "showsHorizontalScrollIndicator":
                fromOption(
                  UtilsRN.optBoolToOptJsBoolean(
                    showsHorizontalScrollIndicator,
                  ),
                ),
              "showsVerticalScrollIndicator":
                fromOption(
                  UtilsRN.optBoolToOptJsBoolean(showsVerticalScrollIndicator),
                ),
              "stickyHeaderIndices":
                fromOption(
                  UtilsRN.option_map(Array.of_list, stickyHeaderIndices),
                ),
              "overScrollMode":
                fromOption(
                  UtilsRN.option_map(
                    x =>
                      switch (x) {
                      | `always => "always"
                      | `never => "never"
                      | `auto => "auto"
                      },
                    overScrollMode,
                  ),
                ),
              "scrollPerfTag": fromOption(scrollPerfTag),
              "alwaysBounceHorizontal":
                fromOption(
                  UtilsRN.optBoolToOptJsBoolean(alwaysBounceHorizontal),
                ),
              "alwaysBounceVertical":
                fromOption(
                  UtilsRN.optBoolToOptJsBoolean(alwaysBounceVertical),
                ),
              "automaticallyAdjustContentInsets":
                fromOption(
                  UtilsRN.optBoolToOptJsBoolean(
                    automaticallyAdjustContentInsets,
                  ),
                ),
              "bounces": fromOption(UtilsRN.optBoolToOptJsBoolean(bounces)),
              "canCancelContentTouches":
                fromOption(
                  UtilsRN.optBoolToOptJsBoolean(canCancelContentTouches),
                ),
              "centerContent":
                fromOption(UtilsRN.optBoolToOptJsBoolean(centerContent)),
              "contentInset": fromOption(contentInset),
              "contentOffset":
                fromOption(
                  UtilsRN.option_map(
                    ({x, y}) => {"x": x, "y": y},
                    contentOffset,
                  ),
                ),
              "decelerationRate":
                fromOption(
                  UtilsRN.option_map(
                    x =>
                      switch (x) {
                      | `fast => "fast"
                      | `normal => "normal"
                      },
                    decelerationRate,
                  ),
                ),
              "directionalLockEnabled":
                fromOption(
                  UtilsRN.optBoolToOptJsBoolean(directionalLockEnabled),
                ),
              "indicatorStyle":
                fromOption(
                  UtilsRN.option_map(
                    x =>
                      switch (x) {
                      | `default => "default"
                      | `black => "black"
                      | `white => "white"
                      },
                    indicatorStyle,
                  ),
                ),
              "maximumZoomScale": fromOption(maximumZoomScale),
              "minimumZoomScale": fromOption(minimumZoomScale),
              "onScrollAnimationEnd": fromOption(onScrollAnimationEnd),
              "scrollEventThrottle": fromOption(scrollEventThrottle),
              "scrollIndicatorInsets": fromOption(scrollIndicatorInsets),
              "scrollsToTop":
                fromOption(UtilsRN.optBoolToOptJsBoolean(scrollsToTop)),
              "snapToAlignment":
                fromOption(
                  UtilsRN.option_map(
                    x =>
                      switch (x) {
                      | `center => "center"
                      | `start => "start"
                      | `end_ => "end"
                      },
                    snapToAlignment,
                  ),
                ),
              "zoomScale": fromOption(zoomScale),
            }
          ),
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

include
  CreateComponent(
    {
      [@bs.module "react-native"]
      external view : ReasonReact.reactClass = "ScrollView";
    },
  );
