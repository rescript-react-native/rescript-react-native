type pressRetentionOffset = { top: int, left: int, bottom: int, right: int};

let createElement:
  accessible::bool? =>
  allowFontScaling::bool? =>
  ellipsizeMode::[ | `clip | `head | `middle | `tail]? =>
  numberOfLines::int? =>
  onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
  onLongPress::(unit => unit)? =>
  onPress::(unit => unit)? =>
  pressRetentionOffset::pressRetentionOffset? =>
  selectable::bool? =>
  style::Style.t? =>
  testID::string? =>
  selectionColor::string? =>
  textBreakStrategy::[ | `simple | `highQuality | `balanced ]? =>
  adjustsFontSizeToFit::bool? =>
  minimumFontScale::float? =>
  suppressHighlighting::bool? =>
  children::list ReactRe.reactElement =>
  ref::(ReactRe.reactRef => unit)? =>
  key::string? =>
  unit =>
  ReactRe.reactElement;