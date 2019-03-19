[@bs.module "react-native"] external view: ReasonReact.reactClass = "Slider";

type rawImageSourceJS;

external rawImageSourceJS: 'a => rawImageSourceJS = "%identity";

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
      ~accessibilityRole=?,
      ~accessibilityStates=?,
      ~accessibilityHint=?,
      ~accessibilityIgnoresInvertColors=?,
      ~accessibilityViewIsModal=?,
      ~shouldRasterizeIOS=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props=
      ViewProps.extend(
        {
          "disabled": disabled,
          "maximumTrackTintColor": maximumTrackTintColor,
          "maximumValue": maximumValue,
          "minimumTrackTintColor": minimumTrackTintColor,
          "minimumValue": minimumValue,
          "onSlidingComplete": onSlidingComplete,
          "onValueChange": onValueChange,
          "step": step,
          "value": value,
          "thumbTintColor": thumbTintColor,
          "maximumTrackImage":
            maximumTrackImage->Belt.Option.map(convertImageSource),
          "minimumTrackImage":
            minimumTrackImage->Belt.Option.map(convertImageSource),
          "thumbImage": thumbImage->Belt.Option.map(convertImageSource),
          "trackImage": trackImage->Belt.Option.map(convertImageSource),
        },
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
        ~accessibilityRole?,
        ~accessibilityStates?,
        ~accessibilityHint?,
        ~accessibilityIgnoresInvertColors?,
        ~accessibilityViewIsModal?,
        ~shouldRasterizeIOS?,
      ),
  );
