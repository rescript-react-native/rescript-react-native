[@react.component]
let make =
    (
      ~progress: float,
      ~progressImage: option(Image.imageSource)=?,
      ~progressTintColor: option(string)=?,
      ~progressViewStyle: option([ | `default | `bar])=?,
      ~trackImage: option(Image.imageSource)=?,
      ~trackTintColor: option(string)=?,
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
      ~collapsable: option(bool)=?,
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
      _,
    ) =>
  <ReactNative.ProgressViewIOS
    progress
    progressImage=?{progressImage->Belt.Option.map(Image.encodeSource)}
    ?progressTintColor
    ?progressViewStyle
    trackImage=?{trackImage->Belt.Option.map(Image.encodeSource)}
    ?trackTintColor
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
