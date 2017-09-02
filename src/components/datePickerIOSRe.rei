let make:
  date::Js.Date.t? =>
  onDateChange::(Js.Date.t => unit)? =>
  maximumDate::Js.Date.t? =>
  minimumDate::Js.Date.t? =>
  mode::[ | `date | `datetime | `time]? =>
  minuteInterval::int? =>
  timeZoneOffsetInMinutes::int? =>
  accessibilityLabel::ReasonReact.reactElement? =>
  accessible::bool? =>
  hitSlop::TypesRN.insets? =>
  onAccessibilityTap::(unit => unit)? =>
  onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
  onMagicTap::(unit => unit)? =>
  responderHandlers::Props.touchResponderHandlers? =>
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
  ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps unit;
