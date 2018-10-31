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
    ~maximumTrackTintColor: string=?,
  ]}
  {4 maximumValue}
  {[
    ~maximumValue: float=?,
  ]}
  {4 minimumTrackTintColor}
  {[
    ~minimumTrackTintColor: string=?,
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
    ~thumbTintColor: string=?,
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

let make:
  (
    ~disabled: bool=?,
    ~maximumTrackTintColor: string=?,
    ~maximumValue: float=?,
    ~minimumTrackTintColor: string=?,
    ~minimumValue: float=?,
    ~onSlidingComplete: float => unit=?,
    ~onValueChange: float => unit=?,
    ~step: float=?,
    ~value: float=?,
    ~thumbTintColor: string=?,
    ~maximumTrackImage: Image.imageSource=?,
    ~minimumTrackImage: Image.imageSource=?,
    ~thumbImage: Image.imageSource=?,
    ~trackImage: Image.imageSource=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
    ~removeClippedSubviews: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~accessibilityComponentType: [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityLiveRegion: [ | `none | `polite | `assertive]=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: [ | `auto | `yes | `no | `noHideDescendants]=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(
                            [
                              | `none
                              | `button
                              | `link
                              | `header
                              | `search
                              | `image
                              | `selected
                              | `plays
                              | `key
                              | `text
                              | `summary
                              | `disabled
                              | `frequentUpdates
                              | `startsMedia
                              | `adjustable
                              | `allowsDirectInteraction
                              | `pageTurn
                            ],
                          )
                            =?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );
