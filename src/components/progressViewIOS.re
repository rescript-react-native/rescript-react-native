[@bs.module "react-native"]
external progressViewIOS : ReasonReact.reactClass = "ProgressViewIOS";

let make =
    (
      ~progress=?,
      ~progressImage=?,
      ~progressTintColor=?,
      ~progressViewStyle=?,
      ~trackImage=?,
      ~trackTintColor=?,
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
    ~reactClass=progressViewIOS,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "progress": fromOption(progress),
            "progressImage": fromOption(progressImage),
            "progressTintColor": fromOption(progressTintColor),
            "progressViewStyle": fromOption(progressViewStyle),
            "trackImage": fromOption(trackImage),
            "trackTintColor": fromOption(trackTintColor),
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