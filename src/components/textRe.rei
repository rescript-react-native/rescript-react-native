module type TextComponent = {
  let createElement:
    accessible::bool? =>
    allowFontScaling::bool? =>
    ellipsizeMode::[ | `clip | `head | `middle | `tail]? =>
    numberOfLines::int? =>
    onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
    onLongPress::(unit => unit)? =>
    onPress::(unit => unit)? =>
    pressRetentionOffset::Types.insets? =>
    selectable::bool? =>
    style::StyleRe.t? =>
    testID::string? =>
    selectionColor::string? =>
    textBreakStrategy::[ | `balanced | `highQuality | `simple]? =>
    adjustsFontSizeToFit::bool? =>
    minimumFontScale::float? =>
    suppressHighlighting::bool? =>
    value::string? =>
    children::list ReactRe.reactElement =>
    ref::(ReactRe.reactRef => unit)? =>
    key::string? =>
    unit =>
    ReactRe.reactElement;
};

module CreateComponent: (Impl: ViewRe.Impl) => TextComponent;

module Text: TextComponent;
