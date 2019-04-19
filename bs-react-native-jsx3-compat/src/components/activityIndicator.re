[@bs.module "react-native"]
external view: ReasonReact.reactClass = "ActivityIndicator";

[@bs.module "react-native"] [@bs.scope "Platform"] external _os: string = "OS";

let encodeSize = size =>
  switch (size) {
  | `small => Internals.Encoder.string("small")
  | `large => Internals.Encoder.string("large")
  | `exact(x) =>
    switch (_os) {
    | "ios" =>
      Js.Console.warn(
        "Passing 'exact' to the size prop of activityIndicator is supported only on Android. Because you only provided the 'exact' size, we defaulted it to the small size on iOS",
      );
      Internals.Encoder.string("small");
    | _ => Internals.Encoder.int(x)
    }
  };

let make =
    (
      ~animating=?,
      ~color=?,
      ~size=?,
      ~hidesWhenStopped=?,
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
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      ViewProps.extend(
        {
          "animating": animating,
          "color": color,
          "size": size->Belt.Option.map(encodeSize),
          "hidesWhenStopped": hidesWhenStopped,
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
        ~accessibilityRole?,
        ~accessibilityStates?,
        ~accessibilityHint?,
        ~accessibilityIgnoresInvertColors?,
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?,
      ),
  );
