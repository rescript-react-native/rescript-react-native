type point = ReactNative.Types.point;

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

[@react.component]
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
      ~accessibilityRole=?,
      ~accessibilityStates=?,
      ~accessibilityHint=?,
      ~accessibilityIgnoresInvertColors=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
      ~contentInsetAdjustmentBehavior=?,
      ~contentContainerStyle=?,
      ~horizontal=?,
      ~keyboardDismissMode=?,
      ~keyboardShouldPersistTaps=?,
      ~onContentSizeChange=?,
      ~onScroll=?,
      ~onScrollBeginDrag=?,
      ~onScrollEndDrag=?,
      ~onMomentumScrollBegin=?,
      ~onMomentumScrollEnd=?,
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
      ~scrollEventThrottle=?,
      ~scrollIndicatorInsets=?,
      ~scrollsToTop=?,
      ~snapToInterval=?,
      ~snapToAlignment=?,
      ~zoomScale=?,
      ~children=?,
      _,
    ) =>
  <ReactNative.ScrollView
    ?contentInsetAdjustmentBehavior
    ?contentContainerStyle
    ?horizontal
    ?keyboardDismissMode
    ?keyboardShouldPersistTaps
    ?onContentSizeChange
    ?onScroll
    ?onScrollBeginDrag
    ?onScrollEndDrag
    ?onMomentumScrollBegin
    ?onMomentumScrollEnd
    ?pagingEnabled
    ?refreshControl
    ?scrollEnabled
    ?showsHorizontalScrollIndicator
    ?showsVerticalScrollIndicator
    stickyHeaderIndices=?{stickyHeaderIndices->Belt.Option.map(Array.of_list)}
    ?overScrollMode
    ?scrollPerfTag
    ?alwaysBounceHorizontal
    ?alwaysBounceVertical
    ?automaticallyAdjustContentInsets
    ?bounces
    ?canCancelContentTouches
    ?centerContent
    ?contentInset
    ?contentOffset
    ?decelerationRate
    ?directionalLockEnabled
    ?indicatorStyle
    ?maximumZoomScale
    ?minimumZoomScale
    ?scrollEventThrottle
    ?scrollIndicatorInsets
    ?scrollsToTop
    ?snapToInterval
    ?snapToAlignment
    ?zoomScale
    ?accessibilityLabel
    ?accessible
    ?hitSlop
    ?onAccessibilityTap
    ?onLayout
    ?onMagicTap
    onMoveShouldSetResponder=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onMoveShouldSetResponder->Belt.Option.map((g, x) => g(x))
        )
      )
    onMoveShouldSetResponderCapture=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onMoveShouldSetResponderCapture
          ->Belt.Option.map((g, x) => g(x))
        )
      )
    onResponderGrant=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderGrant
        )
      )
    onResponderMove=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderMove
        )
      )
    onResponderReject=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderReject
        )
      )
    onResponderRelease=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderRelease
        )
      )
    onResponderTerminate=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderTerminate
        )
      )
    onResponderTerminationRequest=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onResponderTerminationRequest
        )
      )
    onStartShouldSetResponder=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onStartShouldSetResponder->Belt.Option.map((g, x) => g(x))
        )
      )
    onStartShouldSetResponderCapture=?
      Types.(
        responderHandlers->Belt.Option.flatMap(handlers =>
          handlers.onStartShouldSetResponderCapture
          ->Belt.Option.map((g, x) => g(x))
        )
      )
    ?pointerEvents
    ?removeClippedSubviews
    ?style
    ?testID
    ?accessibilityComponentType
    ?accessibilityLiveRegion
    ?collapsable
    ?importantForAccessibility
    ?needsOffscreenAlphaCompositing
    ?renderToHardwareTextureAndroid
    accessibilityTraits=?{
      accessibilityTraits->Belt.Option.map(Belt.List.toArray)
    }
    ?accessibilityRole
    accessibilityStates=?{
      accessibilityStates->Belt.Option.map(Belt.List.toArray)
    }
    ?accessibilityHint
    ?accessibilityIgnoresInvertColors
    ?accessibilityViewIsModal
    ?shouldRasterizeIOS>
    {children->Belt.Option.getWithDefault(React.null)}
  </ReactNative.ScrollView>;
