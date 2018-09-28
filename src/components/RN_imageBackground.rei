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
    ~source: RN_image.imageSource=?,
    ~style: RN_style.t=?,
    ~imageStyle: RN_style.t=?,
    ~testID: string=?,
    ~resizeMethod: [< | `auto | `resize | `scale]=?,
    ~accessibilityLabel: string=?,
    ~accessible: bool=?,
    ~blurRadius: float=?,
    ~capInsets: RN_types.insets=?,
    ~defaultSource: RN_image.defaultSource=?,
    ~onPartialLoad: unit => unit=?,
    ~onProgress: Event.progress => unit=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );