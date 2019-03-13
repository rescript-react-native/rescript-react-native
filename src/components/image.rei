module type ImageComponent = {
  /**
    {3 Example of use}
    [Image] component {{:https://facebook.github.io/react-native/docs/image}} requires the [source] prop, here is the example usage. Note that you also need to specify the width and height, this can be done via [imageURISource] named arguments, or via [style] prop that is passed to [Image] component

    {2 source from URI}
    {[
      let component = ReasonReact.statelessComponent("MyComponent");

      let make = _children => {
        ...component,
        render: _self =>
          <Image
            source=(
              `URI(
                Image.(
                  imageURISource(
                    ~uri="https://bit.ly/2ya4e2o",
                    ~width=Pt(320.),
                    ~height=Pt(480.),
                    (),
                  )
                ),
              )
            )
          />,
      };
    ]}
    {4 source from a file path}
    One thing to remember here is that the path is relative to the compiled code.
    {[
      let component = ReasonReact.statelessComponent("MyComponent");

      let make = _children => {
        ...component,
        render: _self =>
          <Image
            style=Style.(style([width(Pt(320.)), height(Pt(480.))]))
            source=(`Required(Packager.require("./assets/panamera.png")))
          />,
      };
    ]}
    {3 Props}
    {4 onError}
    {[
      onError: Event.error => unit=?
    ]}
    {{:#module-Event} [Event]}
    {4 onLayout}
    {[
      onLayout: RNEvent.NativeLayoutEvent.t => unit=?
    ]}
    Reference {{:/BsReactNative/RNEvent-BsReactNative/NativeLayoutEvent/} [RNEvent.NativeLayoutEvent]}

    {4 onLoad}
    {[
      onLoad: unit => unit=?
    ]}
    {4 onLoadEnd}
    {[
      onLoadEnd: unit => unit=?
    ]}
    {4 onLoadStart}
    {[
      onLoadStart: unit => unit=?
    ]}
    {4 resizeMode}
    {[
      resizeMode: [<
        | `center
        | `contain
        | `cover
        | `repeat
        | `stretch
      ]=?
    ]}
    {4 source}
    {[
      source: imageSource
    ]}
    {{:#type-imageSource} reference:}
    {[
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
    ]}
    {[
      type pt_only =
        | Pt(float);

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
          ~width: Style.pt_only=?,
          ~height: Style.pt_only=?,
          unit
        ) =>
        _imageURISource;
    ]}
    {4 style}
    {[
      style: Style.t=?
    ]}
    {4 testID}
    {[
      testID: string=?
    ]}
    {4 resizeMethod}
    {[
      resizeMethod: [<
        | `auto
        | `resize
        | `scale
      ]=?
    ]}
    {4 accessibilityLabel}
    {[
      accessibilityLabel: string=?
    ]}
    {4 blurRadius}
    {[
      blurRadius: float=?
    ]}
    {4 capInsets}
    {[
      capInsets: Types.insets=?
    ]}
    reference:
    {[
      type insets = {
        .
        "left": int,
        "right": int,
        "top": int,
        "bottom": int,
      };
    ]}
    {4 defaultSource}
    {[
      defaultSource: defaultSource=?
    ]}
    {{:#defaultsource} reference:}
    {[
      type defaultSource = [
        | `URI(_defaultURISource)
        | `Required(Packager.required)
      ];
    ]}
    {[
      let _defaultURISource:
        (
          ~uri: string,
          ~scale: float=?,
          ~width: option(float)=?,
          ~height: option(float)=?,
          unit
        ) =>
        _defaultURISource;
    ]}
    {[
      let defaultURISource:
        (
          ~uri: string,
          ~scale: float=?,
          ~width: Style.pt_only=?,
          ~height: Style.pt_only=?,
          unit
        ) =>
        _defaultURISource;
    ]}
    {[
      type pt_only =
        | Pt(float);
    ]}
    {4 onPartialLoad}
    {[
      onPartialLoad: unit => unit=?
    ]}
    {4 onProgress}
    {[
      onProgress: Event.progress => unit=?
    ]}
    {{:#module-Event} [Event]}

  {2 API reference}
  */
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
      ~width: Style.pt_only=?,
      ~height: Style.pt_only=?,
      unit
    ) =>
    _imageURISource;

  type imageSource = [
    | `URI(_imageURISource)
    | `Required(Packager.required)
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
      ~width: Style.pt_only=?,
      ~height: Style.pt_only=?,
      unit
    ) =>
    _defaultURISource;

  type defaultSource = [
    | `URI(_defaultURISource)
    | `Required(Packager.required)
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
      ~onLayout: RNEvent.NativeLayoutEvent.t => unit=?,
      ~onLoad: unit => unit=?,
      ~onLoadEnd: unit => unit=?,
      ~onLoadStart: unit => unit=?,
      ~resizeMode: [< | `center | `contain | `cover | `repeat | `stretch]=?,
      ~source: imageSource,
      ~style: Style.t=?,
      ~testID: string=?,
      ~resizeMethod: [< | `auto | `resize | `scale]=?,
      ~accessibilityLabel: string=?,
      ~accessible: bool=?,
      ~blurRadius: float=?,
      ~capInsets: Types.insets=?,
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

  type asset = {
    .
    "uri": string,
    "width": int,
    "height": int,
  };

  type assetSource = [
    | `URI(_imageURISource)
    | `Required(Packager.required)
  ];

  let resolveAssetSource: assetSource => asset;
};

module CreateComponent: (Impl: View.Impl) => ImageComponent;

include ImageComponent;
