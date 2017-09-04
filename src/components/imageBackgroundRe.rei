module type ImageBackgroundComponent = {
    type imageURISource;
    let imageURISource:
      uri::string =>
      bundle::string? =>
      method::string? =>
      headers::Js.t 'a? =>
      body::string? =>
      cache::[ | `default | `reload | `forceCache | `onlyIfCached]? =>
      scale::float? =>
      width::float? =>
      height::float? =>
      unit =>
      imageURISource;
    type imageSource =
      | URI imageURISource
      | Required PackagerRe.required
      | Multiple (list imageURISource);
    type defaultURISource;
    let defaultURISource:
      uri::string => scale::float? => width::float? => height::float? => unit => defaultURISource;
    type defaultSource =
      | URI defaultURISource
      | Required PackagerRe.required;
    module Event: {
      type error;
      type progress = {
        loaded: float,
        total: float
      };
    };
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
      defaultSource::defaultSource? =>
      onPartialLoad::(unit => unit)? =>
      onProgress::(Event.progress => unit)? =>
      array ReasonReact.reactElement =>
      ReasonReact.component ReasonReact.stateless ReasonReact.noRetainedProps unit;
  };
  
  module CreateComponent: (Impl: ViewRe.Impl) => ImageBackgroundComponent;
  
  module ImageBackground: ImageBackgroundComponent;
  