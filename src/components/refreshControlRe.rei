let make:
  onRefresh::(unit => unit)? =>
  refreshing::bool? =>
  colors::array string? =>
  enabled::bool? =>
  progressBackgroundColor::string? =>
  progressViewOffset::float? =>
  tintColor::string? =>
  title::string? =>
  titleColor::string? =>
  accessibleLeft::ReasonReact.reactElement? =>
  accessible::bool? =>
  hitSlop::TypesRN.insets? =>
  onAccessibilityTap::(unit => unit)? =>
  onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
  onMagicTap::(unit => unit)? =>
  responderHandlers::option Props.touchResponderHandlers =>
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
  array ReasonReact.reactElement =>
  ReasonReact.component ReasonReact.stateless;