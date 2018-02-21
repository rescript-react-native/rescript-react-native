[@bs.module "react-native"]
external view : ReasonReact.reactClass = "SegmentedControlIOS";

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
            "enabled": fromOption @@ UtilsRN.optBoolToOptJsBoolean(enabled),
            "momentary": fromOption @@ UtilsRN.optBoolToOptJsBoolean(momentary),
            "tintColor": fromOption(tintColor),
            "values": Array.of_list(values),
            "selectedIndex": fromOption(selectedIndex),
            "onChange": fromOption(onChange),
            "onValueChange": fromOption(onValueChange)
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
