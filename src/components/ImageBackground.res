include NativeElement

@react.component @module("react-native")
external make: (
  ~ref: ref=?,
  // ImageBackground props
  ~imageRef: Image.ref=?,
  ~imageStyle: Style.t=?,
  // Image props
  ~accessibilityLabel: string=?,
  ~accessible: bool=?,
  ~blurRadius: float=?,
  ~capInsets: Rect.t=?,
  ~defaultSource: Image.Source.t=?,
  ~fadeDuration: float=?,
  ~loadingIndicatorSource: array<Image.Source.t>=?,
  ~onError: Image.errorEvent => unit=?,
  ~onLayout: Event.layoutEvent => unit=?,
  ~onLoad: unit => unit=?,
  ~onLoadEnd: unit => unit=?,
  ~onLoadStart: unit => unit=?,
  ~onPartialLoad: unit => unit=?,
  ~onProgress: Image.progressEvent => unit=?,
  ~progressiveRenderingEnabled: bool=?,
  ~resizeMethod: Image.resizeMethod=?,
  ~resizeMode: Style.resizeMode=?,
  ~source: Image.Source.t,
  ~style: Style.t=?,
  ~testID: string=?,
  ~children: React.element=?,
) => React.element = "ImageBackground"
