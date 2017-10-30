[@bs.module "react-native"] external view : ReasonReact.reactClass = "ActivityIndicator";

let encodeSize = (size) =>
  switch size {
  | `small => Encode.string("small")
  | `large => Encode.string("large")
  | `exact(x) => Encode.int(x)
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
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "animating": from_opt(UtilsRN.optBoolToOptJsBoolean(animating)),
            "color": from_opt(color),
            "size": from_opt(UtilsRN.option_map(encodeSize, size)),
            "hidesWhenStopped": from_opt(UtilsRN.optBoolToOptJsBoolean(hidesWhenStopped))
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
