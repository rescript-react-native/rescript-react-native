module Item = {
  [@react.component]
  let make = (~color=?, ~label, ~value=?, ~testID=?) =>
    <ReactNative.Picker.Item label value ?color ?testID />;
};

[@react.component]
let make =
    (
      ~onValueChange=?,
      ~selectedValue=?,
      ~enabled=?,
      ~mode=?,
      ~prompt=?,
      ~itemStyle=?,
      /* view props */
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
      ~children=?,
      _,
    ) =>
  <ReactNative.Picker
    ?enabled
    onValueChange=?{onValueChange->Belt.Option.map((o, a, _) => o(a))}
    ?selectedValue
    ?itemStyle
    ?prompt
    ?mode
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
  </ReactNative.Picker>;
