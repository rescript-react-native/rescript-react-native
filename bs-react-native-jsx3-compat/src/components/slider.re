let encodeSource = (x: Image.imageSource) =>
  switch (x) {
  | `URI(x) => ReactNative.Image.Source.fromUriSource(x)
  | `Required(x) => ReactNative.Image.Source.fromRequired(x)
  | `Multiple(x) => ReactNative.Image.Source.fromUriSources(Array.of_list(x))
  };

[@react.component]
let make =
    (
      ~disabled: option(bool)=?,
      ~maximumTrackTintColor: option(string)=?,
      ~maximumValue: option(float)=?,
      ~minimumTrackTintColor: option(string)=?,
      ~minimumValue: option(float)=?,
      ~onSlidingComplete: option(float => unit)=?,
      ~onValueChange: option(float => unit)=?,
      ~step: option(float)=?,
      ~value: option(float)=?,
      ~thumbTintColor: option(string)=?,
      ~maximumTrackImage: option(Image.imageSource)=?,
      ~minimumTrackImage: option(Image.imageSource)=?,
      ~thumbImage: option(Image.imageSource)=?,
      ~trackImage: option(Image.imageSource)=?,
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
      _,
    ) =>
  <ReactNative.Slider
    ?disabled
    ?maximumTrackTintColor
    ?maximumValue
    ?minimumTrackTintColor
    ?minimumValue
    ?onSlidingComplete
    ?onValueChange
    ?step
    ?value
    ?thumbTintColor
    maximumTrackImage=?{maximumTrackImage->Belt.Option.map(encodeSource)}
    minimumTrackImage=?{minimumTrackImage->Belt.Option.map(encodeSource)}
    thumbImage=?{thumbImage->Belt.Option.map(encodeSource)}
    trackImage=?{trackImage->Belt.Option.map(encodeSource)}
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
    ?shouldRasterizeIOS
  />;
