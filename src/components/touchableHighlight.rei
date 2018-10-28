/**
A wrapper for making views respond properly to touches. On press down, the opacity of the wrapped view is decreased, which allows the underlay color to show through, darkening or tinting the view.
You can read more on [TouchableHighlight] component usage in official docs: {{:https://facebook.github.io/react-native/docs/touchablehighlight}}

  {3 Props}

  {{:\BsReactNative/TouchableWithoutFeedback-BsReactNative} [TouchableWithoutFeedback] props}

  {4 activeOpacity}
  {[
    ~activeOpacity: float=?
  ]}
  {4 onHideUnderlay}
  {[
    ~onHideUnderlay: unit => unit=?    
  ]}
  {4 onShowUnderlay}
  {[
    ~onShowUnderlay: unit => unit=?
  ]}
  {4 style}
  {[ 
    ~style: Style.t=?
  ]}
  {4 underlayColor}
  {[
    ~underlayColor: string=?
  ]}
  {4 hasTVPreferredFocus}
  {[
    ~hasTVPreferredFocus: bool=?
  ]}
  {4 tvParallaxProperties}
  {[
    ~tvParallaxProperties: Js.t({.})=?
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
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onPress: unit => unit=?,
    ~onPressIn: unit => unit=?,
    ~onPressOut: unit => unit=?,
    ~pressRetentionOffset: Types.insets=?,
    ~activeOpacity: float=?,
    ~onHideUnderlay: unit => unit=?,
    ~onShowUnderlay: unit => unit=?,
    ~style: Style.t=?,
    ~underlayColor: string=?,
    ~hasTVPreferredFocus: bool=?,
    ~tvParallaxProperties: Js.t({.})=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );
