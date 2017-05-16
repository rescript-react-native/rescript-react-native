external view : ReactRe.reactClass = "Slider" [@@bs.module "react-native"];

type rawImageSourceJS;

external rawImageSourceJS : 'a => rawImageSourceJS = "%identity";

let convertImageSource src =>
  switch src {
  | ImageRe.Image.Multiple x => rawImageSourceJS (Array.of_list x)
  | ImageRe.Image.URI x => rawImageSourceJS x
  | ImageRe.Image.Required x => rawImageSourceJS x
  };

let createElement
    disabled::(disabled: option bool)=?
    maximumTrackTintColor::(maximumTrackTintColor: option string)=?
    maximumValue::(maximumValue: option string)=?
    minimumTrackTintColor::(minimumTrackTintColor: option string)=?
    minimumValue::(minimumValue: option string)=?
    onSlidingComplete::(onSlidingComplete: option (float => unit))=?
    onValueChange::(onValueChange: option (float => unit))=?
    step::(step: option float)=?
    value::(value: option float)=?
    thumbTintColor::(thumbTintColor: option string)=?
    maximumTrackImage::(maximumTrackImage: option ImageRe.Image.imageSource)=?
    minimumTrackImage::(minimumTrackImage: option ImageRe.Image.imageSource)=?
    thumbImage::(thumbImage: option ImageRe.Image.imageSource)=?
    trackImage::(trackImage: option ImageRe.Image.imageSource)=?
    ::accessibleLeft=?
    ::accessible=?
    ::hitSlop=?
    ::onAccessibilityTap=?
    ::onLayout=?
    ::onMagicTap=?
    ::responderHandlers
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
  ReactRe.wrapPropsShamelessly
    view
    (
      Props.extendView
        Js.Undefined.(
          {
            "disabled": from_opt (UtilsRN.optBoolToOptJsBoolean disabled),
            "maximumTrackTintColor": from_opt maximumTrackTintColor,
            "maximumValue": from_opt maximumValue,
            "minimumTrackTintColor": from_opt minimumTrackTintColor,
            "minimumValue": from_opt minimumValue,
            "onSlidingComplete": from_opt onSlidingComplete,
            "onValueChange": from_opt onValueChange,
            "step": from_opt step,
            "value": from_opt value,
            "thumbTintColor": from_opt thumbTintColor,
            "maximumTrackImage": from_opt (UtilsRN.option_map convertImageSource maximumTrackImage),
            "minimumTrackImage": from_opt (UtilsRN.option_map convertImageSource minimumTrackImage),
            "thumbImage": from_opt (UtilsRN.option_map convertImageSource thumbImage),
            "trackImage": from_opt (UtilsRN.option_map convertImageSource trackImage),
          }
        )
        ::accessibleLeft
        ::accessible
        ::hitSlop
        ::onAccessibilityTap
        ::onLayout
        ::onMagicTap
        ::responderHandlers
        ::pointerEvents
        ::removeClippedSubviews
        ::style
        ::testID
        ::accessibilityComponentType
        ::accessibilityLiveRegion
        ::collapsable
        ::importantForAccessibility
        ::needsOffscreenAlphaCompositing
        ::renderToHardwareTextureAndroid
        ::accessibilityTraits
        ::accessibilityViewIsModal
        ::shouldRasterizeIOS
    );