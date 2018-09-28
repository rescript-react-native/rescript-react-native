module type ImageComponent = {
  type _imageURISource;
  let _imageURISource:
    (
      ~uri: string,
      ~bundle: string=?,
      ~method: string=?,
      ~headers: Js.t('a)=?,
      ~body: string=?,
      ~cache: [ | `default | `reload | `forceCache | `onlyIfCached]=?,
      ~scale: float=?,
      ~width: option(float)=?,
      ~height: option(float)=?,
      unit
    ) =>
    _imageURISource;

  type imageURISource;
  let imageURISource:
    (
      ~uri: string,
      ~bundle: string=?,
      ~method: string=?,
      ~headers: Js.t('a)=?,
      ~body: string=?,
      ~cache: [ | `default | `reload | `forceCache | `onlyIfCached]=?,
      ~scale: float=?,
      ~width: RN_style.pt_only=?,
      ~height: RN_style.pt_only=?,
      unit
    ) =>
    _imageURISource;

  type imageSource = [
    | `URI(_imageURISource)
    | `Required(RN_packager.required)
    | `Multiple(list(_imageURISource))
  ];
  type _defaultURISource;
  let _defaultURISource:
    (
      ~uri: string,
      ~scale: float=?,
      ~width: option(float)=?,
      ~height: option(float)=?,
      unit
    ) =>
    _defaultURISource;

  type defaultURISource;
  let defaultURISource:
    (
      ~uri: string,
      ~scale: float=?,
      ~width: RN_style.pt_only=?,
      ~height: RN_style.pt_only=?,
      unit
    ) =>
    _defaultURISource;

  type defaultSource = [
    | `URI(_defaultURISource)
    | `Required(RN_packager.required)
  ];
  module Event: {
    type error;
    type progress = {
      loaded: float,
      total: float,
    };
  };
  let make:
    (
      ~onError: Event.error => unit=?,
      ~onLayout: RN_Event.NativeLayoutEvent.t => unit=?,
      ~onLoad: unit => unit=?,
      ~onLoadEnd: unit => unit=?,
      ~onLoadStart: unit => unit=?,
      ~resizeMode: [< | `center | `contain | `cover | `repeat | `stretch]=?,
      ~source: imageSource,
      ~style: RN_style.t=?,
      ~testID: string=?,
      ~resizeMethod: [< | `auto | `resize | `scale]=?,
      ~accessibilityLabel: string=?,
      ~accessible: bool=?,
      ~blurRadius: float=?,
      ~capInsets: RN_types.insets=?,
      ~defaultSource: defaultSource=?,
      ~onPartialLoad: unit => unit=?,
      ~onProgress: Event.progress => unit=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

module CreateComponent: (Impl: RN_view.Impl) => ImageComponent;

include ImageComponent;