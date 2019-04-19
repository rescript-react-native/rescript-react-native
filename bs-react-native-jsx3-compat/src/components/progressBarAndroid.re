[@bs.module "react-native"]
external component: ReasonReact.reactClass = "ProgressBarAndroid";

let styleAttribute = attr =>
  switch (attr) {
  | `Horizontal => "Horizontal"
  | `Inverse => "Inverse"
  | `Large => "Large"
  | `LargeInverse => "LargeInverse"
  | `Normal => "Normal"
  | `Small => "Small"
  | `SmallInverse => "SmallInverse"
  };

let make =
    (
      ~animating=?,
      ~color=?,
      ~indeterminate=?,
      ~progress=?,
      ~styleAttr=?,
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
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=component,
    ~props=
      ViewProps.extend(
        {
          "animating": animating,
          "color": color,
          "indeterminate": indeterminate,
          "progress": progress,
          "styleAttr": styleAttr->Belt.Option.map(styleAttribute),
          "testID": testID,
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
