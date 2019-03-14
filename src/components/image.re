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

module CreateComponent = (Impl: View.Impl) : ImageComponent => {
  let encode_pt_only: Style.pt_only => float =
    value =>
      switch (value) {
      | Style.Pt(value) => value
      };

  type _imageURISource;
  [@bs.obj]
  external _imageURISource:
    (
      ~uri: string,
      ~bundle: string=?,
      ~method: string=?,
      ~headers: Js.t('a)=?,
      ~body: string=?,
      ~cache: [@bs.string] [
                | `default
                | `reload
                | [@bs.as "force-cache"] `forceCache
                | [@bs.as "only-if-cached"] `onlyIfCached
              ]
                =?,
      ~scale: float=?,
      ~width: option(float)=?,
      ~height: option(float)=?,
      unit
    ) =>
    _imageURISource =
    "";

  type imageURISource;
  let imageURISource =
      (
        ~uri,
        ~bundle=?,
        ~method=?,
        ~headers=?,
        ~body=?,
        ~cache=?,
        ~scale=?,
        ~width=?,
        ~height=?,
        unit,
      ) =>
    _imageURISource(
      ~uri,
      ~bundle?,
      ~method?,
      ~headers?,
      ~body?,
      ~cache?,
      ~scale?,
      ~width=width->Belt.Option.map(encode_pt_only),
      ~height=height->Belt.Option.map(encode_pt_only),
      unit,
    );

  type imageSource = [
    | `URI(_imageURISource)
    | `Required(Packager.required)
    | `Multiple(list(_imageURISource))
  ];

  type _defaultURISource;
  [@bs.obj]
  external _defaultURISource:
    (
      ~uri: string,
      ~scale: float=?,
      ~width: option(float)=?,
      ~height: option(float)=?,
      unit
    ) =>
    _defaultURISource =
    "";

  type defaultURISource;
  let defaultURISource = (~uri, ~scale=?, ~width=?, ~height=?, unit) =>
    _defaultURISource(
      ~uri,
      ~scale?,
      ~width=width->Belt.Option.map(encode_pt_only),
      ~height=height->Belt.Option.map(encode_pt_only),
      unit,
    );

  type defaultSource = [
    | `URI(_defaultURISource)
    | `Required(Packager.required)
  ];
  type rawImageSourceJS;
  external rawImageSourceJS: 'a => rawImageSourceJS = "%identity";
  module Event = {
    type t;
    type error;
    type progress = {
      loaded: float,
      total: float,
    };
    [@bs.get] external progress: t => progress = "nativeEvent";
  };
  let encodeResizeMode =
    fun
    | `cover => "cover"
    | `contain => "contain"
    | `stretch => "stretch"
    | `repeat => "repeat"
    | `center => "center";

  let encodeSource = (x: imageSource) =>
    switch (x) {
    | `URI(x) => rawImageSourceJS(x)
    | `Required(x) => rawImageSourceJS(x)
    | `Multiple(x) => rawImageSourceJS(Array.of_list(x))
    };
  let encodeResizeMethod =
    fun
    | `auto => "auto"
    | `resize => "resize"
    | `scale => "scale";

  let encodeDefaultSource = (x: defaultSource) =>
    switch (x) {
    | `URI(x) => rawImageSourceJS(x)
    | `Required(x) => rawImageSourceJS(x)
    };
  let make =
      (
        ~onError=?,
        ~onLayout=?,
        ~onLoad=?,
        ~onLoadEnd=?,
        ~onLoadStart=?,
        ~resizeMode=?,
        ~source,
        ~style=?,
        ~testID=?,
        ~resizeMethod=?,
        ~accessibilityLabel=?,
        ~accessible=?,
        ~blurRadius=?,
        ~capInsets=?,
        ~defaultSource=?,
        ~onPartialLoad=?,
        ~onProgress=?,
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props={
        "onLayout": onLayout,
        "onError": onError,
        "onLoad": onLoad,
        "onLoadEnd": onLoadEnd,
        "onLoadStart": onLoadStart,
        "resizeMode": resizeMode->Belt.Option.map(encodeResizeMode),
        "source": encodeSource(source),
        "style": style,
        "testID": testID,
        "resizeMethod": resizeMethod->Belt.Option.map(encodeResizeMethod),
        "accessibilityLabel": accessibilityLabel,
        "accessible": accessible,
        "blurRadius": blurRadius,
        "capInsets": capInsets,
        "defaultSource": defaultSource->Belt.Option.map(encodeDefaultSource),
        "onPartialLoad": onPartialLoad,
        "onProgress":
          onProgress->Belt.Option.map((x, y) => x(Event.progress(y))),
      },
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

  [@bs.scope "Image"] [@bs.module "react-native"]
  external resolveAssetSource: assetSource => asset = "";
};

include CreateComponent({
  [@bs.module "react-native"] external view: ReasonReact.reactClass = "Image";
});
