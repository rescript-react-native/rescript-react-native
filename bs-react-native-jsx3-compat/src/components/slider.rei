/**
  A component used to select a single value from a range of values.
  You can read more on [Slider] component usage in official docs: {{:https://facebook.github.io/react-native/docs/slider}}

  {3 Props}

  {{:\BsReactNative/View-BsReactNative} [View] props}

  {4 disabled}
  {[
    ~disabled: bool=?,
  ]}
  {4 maximumTrackTintColor}
  {[
    ~maximumTrackTintColor: ReactNative.Color.t=?,
  ]}
  {4 maximumValue}
  {[
    ~maximumValue: float=?,
  ]}
  {4 minimumTrackTintColor}
  {[
    ~minimumTrackTintColor: ReactNative.Color.t=?,
  ]}
  {4 minimumValue}
  {[
    ~minimumValue: float=?,
  ]}
  {4 onSlidingComplete}
  {[
    ~onSlidingComplete: float => unit=?,
  ]}
  {4 onValueChange}
  {[
    ~onValueChange: float => unit=?,
  ]}
  {4 step}
  {[
    ~step: float=?,
  ]}
  {4 value}
  {[
    ~value: float=?,
  ]}
  {4 thumbTintColor}
  {[
    ~thumbTintColor: ReactNative.Color.t=?,
  ]}
  {4 maximumTrackImage}
  {[
    ~maximumTrackImage: Image.imageSource=?,
  ]}
  reference:
  {[
    type imageSource =
      | `URI(imageURISource)
      | `Required(Packager.required)
      | `Multiple(list(imageURISource));
  ]}
  {[
    let imageURISource:
    (
      ~uri: string,
      ~bundle: string=?,
      ~method: string=?,
      ~headers: Js.t('a)=?,
      ~body: string=?,
      ~cache: [
        | `default
        | `reload
        | `forceCache
        | `onlyIfCached
      ]=?,
      ~scale: float=?,
      ~width: float=?,
      ~height: float=?,
      unit
    ) =>
    imageURISource;
  ]}
  {4 minimumTrackImage}
  {[
    ~minimumTrackImage: Image.imageSource=?,
  ]}
  {4 thumbImage}
  {[
    ~thumbImage: Image.imageSource=?,
  ]}
  {4 trackImage}
  {[
    ~trackImage: Image.imageSource=?,
  ]}
 */

[@react.component]
let make:
  (
    ~disabled: bool=?,
    ~maximumTrackTintColor: ReactNative.Color.t=?,
    ~maximumValue: float=?,
    ~minimumTrackTintColor: ReactNative.Color.t=?,
    ~minimumValue: float=?,
    ~onSlidingComplete: float => unit=?,
    ~onValueChange: float => unit=?,
    ~step: float=?,
    ~value: float=?,
    ~thumbTintColor: ReactNative.Color.t=?,
    ~maximumTrackImage: Image.imageSource=?,
    ~minimumTrackImage: Image.imageSource=?,
    ~thumbImage: Image.imageSource=?,
    ~trackImage: Image.imageSource=?,
    ~accessibilityLabel: string=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: Types.pointerEvents=?,
    ~removeClippedSubviews: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~accessibilityComponentType: Types.accessibilityComponentType=?,
    ~accessibilityLiveRegion: Types.accessibilityLiveRegion=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: Types.importantForAccessibility=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(Types.accessibilityTrait)=?,
    ~accessibilityRole: Types.accessibilityRole=?,
    ~accessibilityStates: list(Types.accessibilityState)=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    unit
  ) =>
  React.element;
