/**
A component that renders [Switch] component usage in official docs: {{:https://facebook.github.io/react-native/docs/switch}}

This is a controlled component that requires an [onValueChange] callback that updates the [value] prop in order for the component to reflect user actions. If the [value] prop is not updated, the component will continue to render the supplied [value] prop instead of the expected result of any user actions.

As of React Native version 0.57, [tintColor], [onTintColor] and [thumbTintColor] have been deprecated.

  {3 Props}

  {{:\BsReactNative/View-BsReactNative} [View] props}

  {4 disabled}
  {[
    ~disabled: bool=?
  ]}
  {4 trackColorTrue}
  {[
    ~trackColorTrue: string=?
  ]}
  {4 trackColorFalse}
  {[
    ~trackColorFalse: string=?
  ]}
  {4 iosBackgroundColor}
  {[
    ~iosBackgroundColor: string=?
  ]}
  {4 onTintColor}
  {[
    ~onTintColor: string=?
  ]}
  {4 onValueChange}
  {[
    ~onValueChange: bool => unit=?
  ]}
  {4 thumbTintColor}
  {[
    ~thumbTintColor: string=?
  ]}
  {4 thumbColor}
  {[
    ~thumbColor: string=?
  ]}
  {4 tintColor}
  {[
    ~tintColor: string=?
  ]}
  {4 value}
  {[
    ~value: bool=?
  ]}
 */

let make:
  (
    ~disabled: bool=?,
    ~trackColorTrue: string=?,
    ~trackColorFalse: string=?,
    ~iosBackgroundColor: string=?,
    ~onTintColor: string=?,
    ~onValueChange: bool => unit=?,
    ~thumbTintColor: string=?,
    ~thumbColor: string=?,
    ~tintColor: string=?,
    ~value: bool=?,
    ~accessibilityLabel: ReasonReact.reactElement=?,
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
    ~accessibilityViewIsModal: bool=?,
    ~shouldRasterizeIOS: bool=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );
