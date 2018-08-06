let setPage: (ReasonReact.reactRef, int) => unit;

let make:
  (
    ~initialPage: int=?,
    ~keyboardDismissMode: [ | `none | `onDrag]=?,
    ~onPageScroll: {
                     .
                     "nativeEvent": {
                       .
                       "position": int,
                       "offset": int,
                     },
                   } =>
                   unit
                     =?,
    ~onPageScrollStateChanged: string => unit=?,
    ~onPageSelected: {. "nativeEvent": {. "position": int}} => unit=?,
    ~pageMargin: int=?,
    ~peekEnabled: bool=?,
    ~scrollEnabled: bool=?,
    /* view props: */
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
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );