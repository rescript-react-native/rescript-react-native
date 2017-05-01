let createElement:
  accessible::bool? =>
  allowFontScaling::bool? =>
  ellipsizeMode::[ | `clip | `head | `middle | `tail]? =>
  numberOfLines::int? =>
  onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
  onLongPress::(unit => unit)? =>
  onPress::(unit => unit)? =>
  pressRetentionOffset::Js.t {. left : int, right : int, top : int, bottom : int}? =>
  selectable::bool? =>
  style::Style.t? =>
  testID::string? =>
  selectionColor::string? =>
  textBreakStrategy::[ | `simple | `highQuality | `balanced]? =>
  adjustsFontSizeToFit::bool? =>
  minimumFontScale::float? =>
  suppressHighlighting::bool? =>
  children::list ReactRe.reactElement =>
  ref::(ReactRe.reactRef => unit)? =>
  key::string? =>
  unit =>
  ReactRe.reactElement;