let createElement:
  accessibilityLabel::string? =>
  color::string? =>
  disabled::bool? =>
  onPress::(unit => unit)? =>
  testID::string? =>
  title::string? =>
  children::list ReactRe.reactElement =>
  ref::(ReactRe.reactRef => unit)? =>
  key::string? =>
  unit =>
  ReactRe.reactElement;