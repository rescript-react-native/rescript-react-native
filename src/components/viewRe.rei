module type ViewComponent = {
  let createElement:
    accessibleLeft::ReactRe.reactElement? =>
    accessible::bool? =>
    hitSlop::Types.insets? =>
    onAccessibilityTap::(unit => unit)? =>
    onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
    onMagicTap::(unit => unit)? =>
    onMoveShouldSetResponder::(RNEvent.NativeEvent.t => bool)? =>
    onMoveShouldSetResponderCapture::(RNEvent.NativeEvent.t => bool)? =>
    onResponderGrant::(RNEvent.NativeEvent.t => unit)? =>
    onResponderMove::(RNEvent.NativeEvent.t => unit)? =>
    onResponderReject::(RNEvent.NativeEvent.t => unit)? =>
    onResponderRelease::(RNEvent.NativeEvent.t => unit)? =>
    onResponderTerminate::(RNEvent.NativeEvent.t => unit)? =>
    onResponderTerminationRequest::(RNEvent.NativeEvent.t => unit)? =>
    onStartShouldSetResponder::(RNEvent.NativeEvent.t => bool)? =>
    onStartShouldSetResponderCapture::(RNEvent.NativeEvent.t => bool)? =>
    pointerEvents::[ | `auto | `boxNone | `boxOnly | `none]? =>
    removeClippedSubviews::bool? =>
    style::Style.t? =>
    testID::string? =>
    accessibilityComponentType::
      [ | `button | `none | `radiobutton_checked | `radiobutton_unchecked]? =>
    accessibilityLiveRegion::[ | `assertive | `none | `polite]? =>
    collapsable::bool? =>
    importantForAccessibility::[ | `auto | `no | `noHideDescendants | `yes]? =>
    needsOffscreenAlphaCompositing::bool? =>
    renderToHardwareTextureAndroid::bool? =>
    accessibilityTraits::
      list [
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
      ]? =>
    accessibilityViewIsModal::bool? =>
    shouldRasterizeIOS::bool? =>
    children::list ReactRe.reactElement =>
    ref::(ReactRe.reactRef => unit)? =>
    key::string? =>
    unit =>
    ReactRe.reactElement;
};

module type Impl = {let view: ReactRe.reactClass;};

module CreateComponent: (Impl: Impl) => ViewComponent;

module View: ViewComponent;
