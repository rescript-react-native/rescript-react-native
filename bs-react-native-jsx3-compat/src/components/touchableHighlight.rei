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
  {4 testID}
  {[
    ~testID: string=?
  ]}
 */

let make:
  (
    ~accessible: bool=?,
    ~accessibilityLabel: string=?,
    ~accessibilityComponentType: Types.accessibilityComponentType=?,
    ~accessibilityTraits: list(Types.accessibilityTrait)=?,
    ~accessibilityRole: Types.accessibilityRole=?,
    ~accessibilityStates: list(Types.accessibilityState)=?,
    ~accessibilityHint: string=?,
    ~accessibilityIgnoresInvertColors: bool=?,
    ~delayLongPress: int=?,
    ~delayPressIn: int=?,
    ~delayPressOut: int=?,
    ~disabled: bool=?,
    ~hitSlop: Types.insets=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onLongPress: RNEvent.NativePressEvent.t => unit=?,
    ~onPress: RNEvent.NativePressEvent.t => unit=?,
    ~onPressIn: RNEvent.NativePressEvent.t => unit=?,
    ~onPressOut: RNEvent.NativePressEvent.t => unit=?,
    ~pressRetentionOffset: Types.insets=?,
    ~activeOpacity: float=?,
    ~onHideUnderlay: unit => unit=?,
    ~onShowUnderlay: unit => unit=?,
    ~style: Style.t=?,
    ~underlayColor: string=?,
    ~hasTVPreferredFocus: bool=?,
    ~tvParallaxProperties: Js.t({.})=?,
    ~testID: string=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );
