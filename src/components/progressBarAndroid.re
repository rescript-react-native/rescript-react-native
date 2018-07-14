[@bs.module "react-native"]
external component : ReasonReact.reactClass = "ProgressBarAndroid";

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
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=component,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "animating": fromOption(animating),
            "color": fromOption(color),
            "indeterminate": fromOption(indeterminate),
            "progress": fromOption(progress),
            "styleAttr":
              fromOption(UtilsRN.option_map(styleAttribute, styleAttr)),
            "testID": fromOption(testID),
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