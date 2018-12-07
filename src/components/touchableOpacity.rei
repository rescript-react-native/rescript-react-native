/**

A wrapper for making views respond properly to touches. On press down, the opacity of the wrapped view is decreased, dimming it.

Opacity is controlled by wrapping the children in an Animated.View, which is added to the view hierarchy. Be aware that this can affect layout.
You can read more on [TouchableOpacity] component usage in official docs: {{:https://facebook.github.io/react-native/docs/touchableopacity}}

  {3 Props}

  {{:\BsReactNative/TouchableWithoutFeedback-BsReactNative} [TouchableWithoutFeedback] props}

  {4 activeOpacity}
  {[
    ~activeOpacity: float=?
  ]}
  {4 focusedOpacity}
  {[
    ~focusedOpacity: float=?
  ]}
  {4 tvParallaxProperties}
  {[
    ~tvParallaxProperties: Js.t({.})=?
  ]}
  {3 Methods}
  {4 setOpacityTo}
  {[
    setOpacityTo: (ReasonReact.reactRef, float, int) => unit
  ]}
  */

let make:
  (
    ~accessible: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityComponentType: [
                                   | `none
                                   | `button
                                   | `radiobutton_checked
                                   | `radiobutton_unchecked
                                 ]
                                   =?,
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
    ~delayLongPress: int=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~disabled: bool=?,
    ~hitSlop: Types.insets=?,
    ~style: Style.t=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onPress: unit => unit=?,
    ~onLongPress: unit => unit=?,
    ~onPressIn: unit => unit=?,
    ~onPressOut: unit => unit=?,
    ~pressRetentionOffset: Types.insets=?,
    ~activeOpacity: float=?,
    ~focusedOpacity: float=?,
    ~testID: string=?,
    ~tvParallaxProperties: Js.t({.})=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );

[@bs.send]
external setOpacityTo: (ReasonReact.reactRef, float, int) => unit =
  "setOpacityTo";
