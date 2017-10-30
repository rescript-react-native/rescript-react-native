[@bs.module "react-native"] external view : ReasonReact.reactClass = "Slider";

type rawImageSourceJS;

external rawImageSourceJS : 'a => rawImageSourceJS = "%identity";

let convertImageSource = (src) =>
  switch src {
  | ImageRe.Image.Multiple(x) => rawImageSourceJS(Array.of_list(x))
  | ImageRe.Image.URI(x) => rawImageSourceJS(x)
  | ImageRe.Image.Required(x) => rawImageSourceJS(x)
  };

let make =
    (
      ~disabled: option(bool)=?,
      ~maximumTrackTintColor: option(string)=?,
      ~maximumValue: option(float)=?,
      ~minimumTrackTintColor: option(string)=?,
      ~minimumValue: option(float)=?,
      ~onSlidingComplete: option((float => unit))=?,
      ~onValueChange: option((float => unit))=?,
      ~step: option(float)=?,
      ~value: option(float)=?,
      ~thumbTintColor: option(string)=?,
      ~maximumTrackImage: option(ImageRe.Image.imageSource)=?,
      ~minimumTrackImage: option(ImageRe.Image.imageSource)=?,
      ~thumbImage: option(ImageRe.Image.imageSource)=?,
      ~trackImage: option(ImageRe.Image.imageSource)=?,
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
            "disabled": from_opt(UtilsRN.optBoolToOptJsBoolean(disabled)),
            "maximumTrackTintColor": from_opt(maximumTrackTintColor),
            "maximumValue": from_opt(maximumValue),
            "minimumTrackTintColor": from_opt(minimumTrackTintColor),
            "minimumValue": from_opt(minimumValue),
            "onSlidingComplete": from_opt(onSlidingComplete),
            "onValueChange": from_opt(onValueChange),
            "step": from_opt(step),
            "value": from_opt(value),
            "thumbTintColor": from_opt(thumbTintColor),
            "maximumTrackImage":
              from_opt(UtilsRN.option_map(convertImageSource, maximumTrackImage)),
            "minimumTrackImage":
              from_opt(UtilsRN.option_map(convertImageSource, minimumTrackImage)),
            "thumbImage": from_opt(UtilsRN.option_map(convertImageSource, thumbImage)),
            "trackImage": from_opt(UtilsRN.option_map(convertImageSource, trackImage))
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
