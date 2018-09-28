let make:
  (
    ~maskElement: ReasonReact.reactElement,
    ~accessible: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityComponentType: [
                                   | `button
                                   | `none
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
    ~accessibilityTraits: list(
                            [<
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
    ~onAccessibilityTap: unit => unit=?,
    ~hitSlop: RN_types.insets=?,
    ~onLayout: RN_Event.NativeLayoutEvent.t => unit=?,
    ~onMagicTap: unit => unit=?,
    ~responderHandlers: RN_types.touchResponderHandlers=?,
    ~pointerEvents: [ | `auto | `boxNone | `boxOnly | `none]=?,
    ~removeClippedSubviews: bool=?,
    ~style: RN_style.t=?,
    ~testID: string=?,
    ~accessibilityLiveRegion: [ | `assertive | `none | `polite]=?,
    ~collapsable: bool=?,
    ~importantForAccessibility: [ | `auto | `no | `noHideDescendants | `yes]=?,
    ~needsOffscreenAlphaCompositing: bool=?,
    ~renderToHardwareTextureAndroid: bool=?,
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );