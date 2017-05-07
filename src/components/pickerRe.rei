
module Item: {
  let createElement:
    color::string? =>
    label::string? =>
    value::'value? =>
    testID::string? =>
    children::list ReactRe.reactElement =>
    ref::(ReactRe.reactRef => unit)? =>
    key::string? =>
    unit =>
    ReactRe.reactElement;
};



let createElement:
  onValueChange::('value => unit)? =>
  selectedValue::'value? =>
  enabled::bool? =>
  mode::[ | `dialog | `dropdown]? =>
  prompt::string? =>
  itemStyle::StyleRe.t? =>
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
  pointerEvents::[ | `auto | `none | `boxNone | `boxOnly]? =>
  removeClippedSubviews::bool? =>
  style::StyleRe.t? =>
  testID::string? =>
  accessibilityComponentType::[ | `none | `button | `radiobutton_checked | `radiobutton_unchecked]? =>
  accessibilityLiveRegion::[ | `none | `polite | `assertive]? =>
  collapsable::bool? =>
  importantForAccessibility::[ | `auto | `yes | `no | `noHideDescendants]? =>
  needsOffscreenAlphaCompositing::bool? =>
  renderToHardwareTextureAndroid::bool? =>
  accessibilityTraits::
    list [
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
    ]? =>
  accessibilityViewIsModal::bool? =>
  shouldRasterizeIOS::bool? =>
  children::list ReactRe.reactElement =>
  ref::(ReactRe.reactRef => unit)? =>
  key::string? =>
  unit =>
  ReactRe.reactElement;