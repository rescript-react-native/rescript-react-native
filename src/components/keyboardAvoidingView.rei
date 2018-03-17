let make:
  (
    ~accessibilityLabel: string=?,
    ~accessible: bool=?,
    ~hitSlop: Types.insets=?,
    ~onAccessibilityTap: unit => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: Types.touchResponderHandlers=?,
    ~pointerEvents: [ | `auto | `boxNone | `boxOnly | `none]=?,
    ~removeClippedSubviews: bool=?,
    ~style: Style.t=?,
    ~testID: string=?,
    ~accessibilityComponentType: [
                                   | `button
                                   | `none
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityLiveRegion: [ | `assertive | `none | `polite]=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: [ | `auto | `no | `noHideDescendants | `yes]=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityTraits: list(
                            [
                              | `adjustable
                              | `allowsDirectInteraction
                              | `button
                              | `disabled
                              | `frequentUpdates
                              | `header
                              | `image
                              | `key
                              | `link
                              | `none
                              | `pageTurn
                              | `plays
                              | `search
                              | `selected
                              | `startsMedia
                              | `summary
                              | `text
                            ],
                          )
                            =?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    ~keyboardVerticalOffset: float=?,
    ~behavior: [ | `height | `position | `padding]=?,
    ~contentContainerStyle: Style.t=?,
    ~relativeKeyboardHeight: 'k=?,
    ~onKeyboardChange: 'l=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );
