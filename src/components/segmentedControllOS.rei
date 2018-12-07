/**
  Use SegmentedControlIOS to render a [UISegmentedControl] iOS.
  You can read more on [SegmentedControlIOS] component usage in official docs: {{:https://facebook.github.io/react-native/docs/segmentedcontrolios}}

  {3 Props}

  {{:\BsReactNative/View-BsReactNative} [View] props}

  {4 values}
  {[
    ~values: list(string),
  ]}
  {4 selectedIndex}
  {[
    ~selectedIndex: int=?,
  ]}
  {4 onChange}
  {[
    ~onChange: RNEvent.t => unit=?,
  ]}
  {4 enabled}
  {[
    ~enabled: bool=?,
  ]}
  {4 momentary}
  {[
    ~momentary: bool=?,
  ]}
  {4 tintColor}
  {[
    ~tintColor: string=?,
  ]}
  {4 onValueChange}
  {[
    ~onValueChange: string => unit=?,
  ]}

*/

let make:
  (
    ~values: list(string),
    ~selectedIndex: int=?,
    ~onChange: RNEvent.t => unit=?,
    ~enabled: bool=?,
    ~momentary: bool=?,
    ~tintColor: string=?,
    ~onValueChange: string => unit=?,
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
