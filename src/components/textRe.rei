module type TextComponent = {
  let make:
    accessible::bool? =>
    allowFontScaling::bool? =>
    ellipsizeMode::[ | `clip | `head | `middle | `tail]? =>
    numberOfLines::int? =>
    onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
    onLongPress::(unit => unit)? =>
    onPress::(unit => unit)? =>
    pressRetentionOffset::TypesRN.insets? =>
    selectable::bool? =>
    style::StyleRe.t? =>
    testID::string? =>
    selectionColor::string? =>
    textBreakStrategy::[ | `balanced | `highQuality | `simple]? =>
    adjustsFontSizeToFit::bool? =>
    minimumFontScale::float? =>
    suppressHighlighting::bool? =>
    value::string? =>
    array ReasonReact.reactElement =>
    ReasonReact.component ReasonReact.stateless;
};

module CreateComponent: (Impl: ViewRe.Impl) => TextComponent;

module Text: TextComponent;