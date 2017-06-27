external view : ReasonReact.reactClass = "Switch" [@@bs.module "react-native"];

let make
    disabled::(disabled: option bool)=?
    onTintColor::(onTintColor: option string)=?
    onValueChange::(onValueChange: option (bool => unit))=?
    thumbTintColor::(thumbTintColor: option string)=?
    tintColor::(tintColor: option string)=?
    value::(value: option bool)=?
    ::accessibleLeft=?
    ::accessible=?
    ::hitSlop=?
    ::onAccessibilityTap=?
    ::onLayout=?
    ::onMagicTap=?
    ::responderHandlers=?
    ::pointerEvents=?
    ::removeClippedSubviews=?
    ::style=?
    ::testID=?
    ::accessibilityComponentType=?
    ::accessibilityLiveRegion=?
    ::collapsable=?
    ::importantForAccessibility=?
    ::needsOffscreenAlphaCompositing=?
    ::renderToHardwareTextureAndroid=?
    ::accessibilityTraits=?
    ::accessibilityViewIsModal=?
    ::shouldRasterizeIOS=? =>
  ReasonReact.wrapJsForReason
    reactClass::view
    props::(
      Props.extendView
        Js.Undefined.(
          {
            "value": from_opt (UtilsRN.optBoolToOptJsBoolean value),
            "disabled": from_opt (UtilsRN.optBoolToOptJsBoolean disabled),
            "onValueChange": from_opt onValueChange,
            "onTintColor": from_opt onTintColor,
            "thumbTintColor": from_opt thumbTintColor,
            "tintColor": from_opt tintColor
          }
        )
        ::?accessibleLeft
        ::?accessible
        ::?hitSlop
        ::?onAccessibilityTap
        ::?onLayout
        ::?onMagicTap
        ::?responderHandlers
        ::?pointerEvents
        ::?removeClippedSubviews
        ::?style
        ::?testID
        ::?accessibilityComponentType
        ::?accessibilityLiveRegion
        ::?collapsable
        ::?importantForAccessibility
        ::?needsOffscreenAlphaCompositing
        ::?renderToHardwareTextureAndroid
        ::?accessibilityTraits
        ::?accessibilityViewIsModal
        ::?shouldRasterizeIOS
    );