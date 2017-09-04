module Item: {
  let make:
    title::string? =>
    badgeColor::string? =>
    badge::string? =>
    icon::ImageRe.Image.imageSource? =>
    onPress::(unit => unit)? =>
    renderAsOriginal::bool? =>
    style::StyleRe.t? =>
    selected::bool? =>
    selectedIcon::ImageRe.Image.imageSource? =>
    isTVSelectable::bool? =>
    accessibilityLabel::ReasonReact.reactElement? =>
    accessible::bool? =>
    hitSlop::TypesRN.insets? =>
    onAccessibilityTap::(unit => unit)? =>
    onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
    onMagicTap::(unit => unit)? =>
    responderHandlers::Props.touchResponderHandlers? =>
    pointerEvents::[ | `auto | `none | `boxNone | `boxOnly]? =>
    removeClippedSubviews::bool? =>
    testID::string? =>
    accessibilityComponentType::
      [ | `none | `button | `radiobutton_checked | `radiobutton_unchecked]? =>
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
    ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps unit;
};

let make:
  barTintColor::string? =>
  itemPositioning::[ | `fill | `center | `auto]? =>
  style::StyleRe.t? =>
  tintColor::string? =>
  translucent::bool? =>
  unselectedItemTintColor::string? =>
  unselectedTintColor::string? =>
  accessibilityLabel::ReasonReact.reactElement? =>
  accessible::bool? =>
  hitSlop::TypesRN.insets? =>
  onAccessibilityTap::(unit => unit)? =>
  onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
  onMagicTap::(unit => unit)? =>
  responderHandlers::Props.touchResponderHandlers? =>
  pointerEvents::[ | `auto | `none | `boxNone | `boxOnly]? =>
  removeClippedSubviews::bool? =>
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
  ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps unit;
