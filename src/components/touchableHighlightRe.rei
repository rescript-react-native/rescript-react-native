let createElement:
  accessible::bool? =>
  accessibilityComponentType::[ | `none | `button | `radiobutton_checked | `radiobutton_unchecked]? =>
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
  delayLongPress::int? =>
  delayPressIn::int? =>
  delayPressOut::int? =>
  disabled::bool? =>
  hitSlop::TypesRN.insets? =>
  onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
  onPress::(unit => unit)? =>
  onPressIn::(unit => unit)? =>
  onPressOut::(unit => unit)? =>
  pressRetentionOffset::TypesRN.insets? =>
  activeOpacity::float? =>
  onHideUnderlay::(unit => unit)? =>
  onShowUnderlay::(unit => unit)? =>
  style::StyleRe.t? =>
  underlayColor::string? =>
  hasTVPreferredFocus::bool? =>
  tvParallaxProperties::(Js.t {.})? =>
  children::list ReactRe.reactElement =>
  ref::(ReactRe.reactRef => unit)? =>
  key::string? =>
  unit =>
  ReactRe.reactElement;