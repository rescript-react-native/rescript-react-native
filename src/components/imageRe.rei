module type ImageComponent = {
  type imageURISource;
  let imageURISource:
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
  type imageSource =
    | URI imageURISource
    | Required PackagerRe.required
    | Multiple (list imageURISource);
  type defaultURISource;
  let defaultURISource:
    uri::string => scale::float? => width::float => height::float => defaultURISource;
  type defaultSource =
    | URI defaultURISource
    | Required PackagerRe.required;
  module Event: {type error; type progress = {loaded: float, total: float};};
  let createElement:
    onError::(Event.error => unit)? =>
    onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
    onLoad::(unit => unit)? =>
    onLoadEnd::(unit => unit)? =>
    onLoadStart::(unit => unit)? =>
    resizeMode::[< | `center | `contain | `cover | `repeat | `stretch]? =>
    source::imageSource? =>
    style::StyleRe.t? =>
    testID::string? =>
    resizeMethod::[< | `auto | `resize | `scale]? =>
    accessibilityLabel::string? =>
    accessible::bool? =>
    blurRadius::float? =>
    capInsets::Types.insets? =>
    defaultSource::defaultSource? =>
    onPartialLoad::(unit => unit)? =>
    onProgress::(Event.progress => unit)? =>
    children::list ReactRe.reactElement =>
    ref::(ReactRe.reactRef => unit)? =>
    key::string? =>
    unit =>
    ReactRe.reactElement;
};

module CreateComponent: (Impl: ViewRe.Impl) => ImageComponent;

module Image: ImageComponent;
