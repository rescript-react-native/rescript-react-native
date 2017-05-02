type imageURISource;

let imageURISource :
  uri::string =>
  bundle::string? =>
  method::string? =>
  headers::list (string, string)? =>
  body::string? =>
  cache::string? =>
  scale::float? =>
  width::float =>
  height::float =>
  unit =>
  imageURISource;

type imageSource 'a =
  | URI imageURISource
  | Require 'a
  | Multiple (list imageURISource);

type defaultURISource;

let defaultURISource :
  uri::string => scale::float? => width::float => height::float => defaultURISource ;

type defaultSource 'a =
  | URI defaultURISource
  | Require 'a;

module Event: {
  type error;
  type progress = {loaded: float, total: float};
};

let createElement:
  onError::(Event.error => unit)? =>
  onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
  onLoad::(unit => unit)? =>
  onLoadEnd::(unit => unit)? =>
  onLoadStart::(unit => unit)? =>
  resizeMode::[< | `center | `contain | `cover | `repeat | `stretch]? =>
  source::imageSource 'a? =>
  style::Style.t? =>
  testID::string? =>
  resizeMethod::[< | `auto | `resize | `scale]? =>
  accessibilityLabel::string? =>
  accessible::bool? =>
  blurRadius::float? =>
  capInsets::Types.insets? =>
  defaultSource::defaultSource 'a? =>
  onPartialLoad::(unit => unit)? =>
  onProgress::(Event.progress => unit)? =>
  children::list ReactRe.reactElement =>
  ref::(ReactRe.reactRef => unit)? =>
  key::string? =>
  unit =>
  ReactRe.reactElement;
