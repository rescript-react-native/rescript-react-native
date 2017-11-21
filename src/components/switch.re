[@bs.module "react-native"] external view : ReasonReact.reactClass = "Switch";

let make =
    (
      ~disabled: option(bool)=?,
      ~onTintColor: option(string)=?,
      ~onValueChange: option((bool => unit))=?,
      ~thumbTintColor: option(string)=?,
      ~tintColor: option(string)=?,
      ~value: option(bool)=?,
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
      ~shouldRasterizeIOS=?
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "value": from_opt(UtilsRN.optBoolToOptJsBoolean(value)),
            "disabled": from_opt(UtilsRN.optBoolToOptJsBoolean(disabled)),
            "onValueChange": from_opt(onValueChange),
            "onTintColor": from_opt(onTintColor),
            "thumbTintColor": from_opt(thumbTintColor),
            "tintColor": from_opt(tintColor)
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
        ~shouldRasterizeIOS?
      )
  );
