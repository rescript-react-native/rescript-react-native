external setOpacityTo : ReasonReact.reactRef => float => int => unit = "scrollTo" [@@bs.send];

let make:
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
  style::StyleRe.t? =>
  onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
  onPress::(unit => unit)? =>
  onPressIn::(unit => unit)? =>
  onPressOut::(unit => unit)? =>
  pressRetentionOffset::TypesRN.insets? =>
  activeOpacity::float? =>
  focusedOpacity::float? =>
  tvParallaxProperties::Js.t {.}? =>
  array ReasonReact.reactElement =>
  ReasonReact.component ReasonReact.stateless;
