[@bs.module "react-native"] external view : ReasonReact.reactClass = "Slider";

type rawImageSourceJS;

external rawImageSourceJS : 'a => rawImageSourceJS = "%identity";

let convertImageSource = src =>
  switch (src) {
  | `Multiple(x) => rawImageSourceJS(Array.of_list(x))
  | `URI(x) => rawImageSourceJS(x)
  | `Required(x) => rawImageSourceJS(x)
  };

let make =
    (
      ~disabled: option(bool)=?,
      ~maximumTrackTintColor: option(string)=?,
      ~maximumValue: option(float)=?,
      ~minimumTrackTintColor: option(string)=?,
      ~minimumValue: option(float)=?,
      ~onSlidingComplete: option(float => unit)=?,
      ~onValueChange: option(float => unit)=?,
      ~step: option(float)=?,
      ~value: option(float)=?,
      ~thumbTintColor: option(string)=?,
      ~maximumTrackImage: option(Image.imageSource)=?,
      ~minimumTrackImage: option(Image.imageSource)=?,
      ~thumbImage: option(Image.imageSource)=?,
      ~trackImage: option(Image.imageSource)=?,
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
    ~reactClass=view,
    ~props=
      Props.extendView(
        Js.Undefined.(
          {
            "disabled": fromOption(UtilsRN.optBoolToOptJsBoolean(disabled)),
            "maximumTrackTintColor": fromOption(maximumTrackTintColor),
            "maximumValue": fromOption(maximumValue),
            "minimumTrackTintColor": fromOption(minimumTrackTintColor),
            "minimumValue": fromOption(minimumValue),
            "onSlidingComplete": fromOption(onSlidingComplete),
            "onValueChange": fromOption(onValueChange),
            "step": fromOption(step),
            "value": fromOption(value),
            "thumbTintColor": fromOption(thumbTintColor),
            "maximumTrackImage":
              fromOption(
                UtilsRN.option_map(convertImageSource, maximumTrackImage),
              ),
            "minimumTrackImage":
              fromOption(
                UtilsRN.option_map(convertImageSource, minimumTrackImage),
              ),
            "thumbImage":
              fromOption(UtilsRN.option_map(convertImageSource, thumbImage)),
            "trackImage":
              fromOption(UtilsRN.option_map(convertImageSource, trackImage)),
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
