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
    ~maximumTrackImage: RN_image.imageSource=?,
    ~minimumTrackImage: RN_image.imageSource=?,
    ~thumbImage: RN_image.imageSource=?,
    ~trackImage: RN_image.imageSource=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
    ~accessible: bool=?,
    ~hitSlop: RN_types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RN_Event.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: RN_types.touchResponderHandlers=?,
    ~pointerEvents: [ | `auto | `none | `boxNone | `boxOnly]=?,
    ~removeClippedSubviews: bool=?,
    ~style: RN_style.t=?,
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