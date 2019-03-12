let serializeResponderHandlers =
    (handlers: option(Types.touchResponderHandlers)) =>
  switch (handlers) {
  | None => Js.Obj.empty()
  | Some(handlers) =>
    Types.{
      "onMoveShouldSetResponder":
        handlers.onMoveShouldSetResponder->Belt.Option.map((g, x) => g(x)),
      "onMoveShouldSetResponderCapture":
        handlers.onMoveShouldSetResponderCapture
        ->Belt.Option.map((g, x) => g(x)),
      "onResponderGrant": handlers.onResponderGrant,
      "onResponderMove": handlers.onResponderMove,
      "onResponderReject": handlers.onResponderReject,
      "onResponderRelease": handlers.onResponderRelease,
      "onResponderTerminate": handlers.onResponderTerminate,
      "onResponderTerminationRequest": handlers.onResponderTerminationRequest,
      "onStartShouldSetResponder":
        handlers.onStartShouldSetResponder->Belt.Option.map((g, x) => g(x)),
      "onStartShouldSetResponderCapture":
        handlers.onStartShouldSetResponderCapture
        ->Belt.Option.map((g, x) => g(x)),
    }
  };

let extend =
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
      moreProps,
    ) =>
  {
    "accessibilityLabel": accessibilityLabel,
    "accessible": accessible,
    "hitSlop": hitSlop,
    "onAccessibilityTap": onAccessibilityTap,
    "onLayout": onLayout,
    "onMagicTap": onMagicTap,
    "removeClippedSubviews": removeClippedSubviews,
    "pointerEvents": Belt.Option.map(pointerEvents, Types.pointerEventsToJs),
    "style": style,
    "testID": testID,
    "accessibilityComponentType":
      Belt.Option.map(
        accessibilityComponentType,
        Types.accessibilityComponentTypeToJs,
      ),
    "accessibilityLiveRegion":
      Belt.Option.map(
        accessibilityLiveRegion,
        Types.accessibilityLiveRegionToJs,
      ),
    "collapsable": collapsable,
    "importantForAccessibility":
      Belt.Option.map(
        importantForAccessibility,
        Types.importantForAccessibilityToJs,
      ),
    "needsOffscreenAlphaCompositing": needsOffscreenAlphaCompositing,
    "renderToHardwareTextureAndroid": renderToHardwareTextureAndroid,
    "accessibilityTraits":
      Belt.Option.map(accessibilityTraits, x =>
        x |> List.map(Types.accessibilityTraitToJs) |> Array.of_list
      ),
    "accessibilityRole":
      Belt.Option.map(accessibilityRole, Types.accessibilityRoleToJs),
    "accessibilityStates":
      Belt.Option.map(accessibilityStates, x =>
        x |> List.map(Types.accessibilityStateToJs) |> Array.of_list
      ),
    "accessibilityHint": accessibilityHint,
    "accessibilityIgnoresInvertColors": accessibilityIgnoresInvertColors,
    "accessibilityViewIsModal": accessibilityViewIsModal,
    "shouldRasterizeIOS": shouldRasterizeIOS,
  }
  ->Js.Obj.assign(responderHandlers->serializeResponderHandlers)
  ->Js.Obj.assign(moreProps);
