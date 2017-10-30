[@bs.module "react-native"] external view : ReasonReact.reactClass = "SegmentedControlIOS";

let make =
    (
      ~values,
      ~selectedIndex=?,
      ~onChange=?,
      ~enabled=?,
      ~momentary=?,
      ~tintColor=?,
      ~onValueChange=?,
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
            "enabled": from_opt @@ UtilsRN.optBoolToOptJsBoolean(enabled),
            "momentary": from_opt @@ UtilsRN.optBoolToOptJsBoolean(momentary),
            "tintColor": from_opt(tintColor),
            "values": Array.of_list(values),
            "selectedIndex": from_opt(selectedIndex),
            "onChange": from_opt(onChange),
            "onValueChange": from_opt(onValueChange)
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
