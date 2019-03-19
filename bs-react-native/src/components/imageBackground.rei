module Event: {
  type error;
  type progress = {
    loaded: float,
    total: float,
  };
};

/**
  [ImageBackground] component has the same props as {{:\BsReactNative/Image-BsReactNative} [Image] component}
  You can read more on ImageBackground component usage in official docs: {{:https://facebook.github.io/react-native/docs/images}}
*/

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
    ~capInsets: Types.insets=?,
    ~defaultSource: Image.defaultSource=?,
    ~onPartialLoad: unit => unit=?,
    ~onProgress: Event.progress => unit=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );
