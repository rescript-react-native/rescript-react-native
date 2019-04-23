[@react.component]
let make =
    (
      ~accessibilityLabel: option(string)=?,
      ~accessible: option(bool)=?,
      ~hitSlop: option(Types.insets)=?,
      ~onAccessibilityTap: option(unit => unit)=?,
      ~onLayout: option(RNEvent.NativeLayoutEvent.t => unit)=?,
      ~onMagicTap: option(unit => unit)=?,
      ~responderHandlers: option(Types.touchResponderHandlers)=?,
      ~pointerEvents: option(Types.pointerEvents)=?,
      ~removeClippedSubviews: option(bool)=?,
      ~style: option(Style.t)=?,
      ~testID: option(string)=?,
      ~accessibilityComponentType: option(Types.accessibilityComponentType)=?,
      ~accessibilityLiveRegion: option(Types.accessibilityLiveRegion)=?,
      ~importantForAccessibility: option(Types.importantForAccessibility)=?,
      ~needsOffscreenAlphaCompositing: option(bool)=?,
      ~renderToHardwareTextureAndroid: option(bool)=?,
      ~accessibilityTraits: option(list(Types.accessibilityTrait))=?,
      ~accessibilityRole: option(Types.accessibilityRole)=?,
      ~accessibilityStates: option(list(Types.accessibilityState))=?,
      ~accessibilityHint: option(string)=?,
      ~accessibilityIgnoresInvertColors: option(bool)=?,
      ~accessibilityViewIsModal: option(bool)=?,
      ~shouldRasterizeIOS: option(bool)=?,
      ~children: option(React.element)=?,
      unit,
    ) =>
  <ReactNative.Animated.View
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
  </ReactNative.Animated.View>;
