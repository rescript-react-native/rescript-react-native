open ImageRe;

module Event: {
  type error;
  type progress = {
    loaded: float,
    total: float
  };
};

type imageSource =
  | URI Image.imageURISource
  | Required PackagerRe.required
  | Multiple (list Image.imageURISource);

let make:
  onError::(Event.error => unit)? =>
  onLayout::(RNEvent.NativeLayoutEvent.t => unit)? =>
  onLoad::(unit => unit)? =>
  onLoadEnd::(unit => unit)? =>
  onLoadStart::(unit => unit)? =>
  resizeMode::[< | `center | `contain | `cover | `repeat | `stretch]? =>
  source::imageSource? =>
  style::StyleRe.t? =>
  imageStyle::StyleRe.t? =>
  testID::string? =>
  resizeMethod::[< | `auto | `resize | `scale]? =>
  accessibilityLabel::string? =>
  accessible::bool? =>
  blurRadius::float? =>
  capInsets::TypesRN.insets? =>
  defaultSource::Image.defaultSource? =>
  onPartialLoad::(unit => unit)? =>
  onProgress::(Event.progress => unit)? =>
  array ReasonReact.reactElement =>
  ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps unit;
