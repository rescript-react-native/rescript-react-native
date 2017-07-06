external view : ReasonReact.reactClass = "RefreshControl" [@@bs.module "react-native"];

let make
    onRefresh::(onRefresh: option (unit => unit))=?
    refreshing::(refreshing: option bool)=?
    colors::(colors: option (array string))=?
    enabled::(enabled: option bool)=?
    progressBackgroundColor::(progressBackgroundColor: option string)=?
    progressViewOffset::(progressViewOffset: option float)=?
    tintColor::(tintColor: option string)=?
    title::(title: option string)=?
    titleColor::(titleColor: option string)=?
    ::accessibilityLabel=?
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
            "onRefresh": from_opt onRefresh,
            "refreshing": from_opt (UtilsRN.optBoolToOptJsBoolean refreshing),
            "colors": from_opt colors,
            "enabled": from_opt (UtilsRN.optBoolToOptJsBoolean enabled),
            "progressBackgroundColor": from_opt progressBackgroundColor,
            "progressViewOffset": from_opt progressViewOffset,
            "tintColor": from_opt tintColor,
            "title": from_opt title,
            "titleColor": from_opt titleColor
          }
        )
        ::?accessibilityLabel
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