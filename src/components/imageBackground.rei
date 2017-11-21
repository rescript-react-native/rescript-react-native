module Event: {
  type error;
  type progress = {
    loaded: float,
    total: float
  };
};

let make:
  (
    ~onError: Event.error => unit=?,
    ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
    ~onLoad: unit => unit=?,
    ~onLoadEnd: unit => unit=?,
    ~onLoadStart: unit => unit=?,
    ~resizeMode: [< | `center | `contain | `cover | `repeat | `stretch]=?,
    ~source: Image.imageSource=?,
    ~style: Style.t=?,
    ~imageStyle: Style.t=?,
    ~testID: string=?,
    ~resizeMethod: [< | `auto | `resize | `scale]=?,
    ~accessibilityLabel: string=?,
    ~accessible: bool=?,
    ~blurRadius: float=?,
    ~capInsets: TypesRN.insets=?,
    ~defaultSource: Image.defaultSource=?,
    ~onPartialLoad: unit => unit=?,
    ~onProgress: Event.progress => unit=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps, unit);
