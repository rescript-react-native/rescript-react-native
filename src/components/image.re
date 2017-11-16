module type ImageComponent = {
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
      ~width: float=?,
      ~height: float=?,
      unit
    ) =>
    imageURISource;
  type imageSource =
    | URI(imageURISource)
    | Required(Packager.required)
    | Multiple(list(imageURISource));
  type defaultURISource;
  let defaultURISource:
    (~uri: string, ~scale: float=?, ~width: float=?, ~height: float=?, unit) => defaultURISource;
  type defaultSource =
    | URI(defaultURISource)
    | Required(Packager.required);
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
      ~source: imageSource=?,
      ~style: Style.t=?,
      ~testID: string=?,
      ~resizeMethod: [< | `auto | `resize | `scale]=?,
      ~accessibilityLabel: string=?,
      ~accessible: bool=?,
      ~blurRadius: float=?,
      ~capInsets: TypesRN.insets=?,
      ~defaultSource: defaultSource=?,
      ~onPartialLoad: unit => unit=?,
      ~onProgress: Event.progress => unit=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(ReasonReact.stateless, ReasonReact.noRetainedProps, unit);
};

module CreateComponent = (Impl: View.Impl) : ImageComponent => {
  type imageURISource;
  [@bs.obj]
  external imageURISource :
    (
      ~uri: string,
      ~bundle: string=?,
      ~method: string=?,
      ~headers: Js.t('a)=?,
      ~body: string=?,
      /*
       * Be careful not to refmt this away !!!
       * https://github.com/facebook/reason/issues/821 (resolved, not released yet)
       *
       * This is hot it should look (or to copy it in again ^^)
       *  cache::[ | `default | `reload | `forceCache [@bs.as "force-cache"] | `onlyIfCached  [@bs.as "only-if-cached"]] [@bs.string]? =>
       */
      ~cache: [@bs.string]
              [
                | `default
                | `reload
                [@bs.as "force-cache"] | `forceCache
                [@bs.as "only-if-cached"] | `onlyIfCached
              ]
                =?,
      ~scale: float=?,
      ~width: float=?,
      ~height: float=?,
      unit
    ) =>
    imageURISource =
    "";
  type imageSource =
    | URI(imageURISource)
    | Required(Packager.required)
    | Multiple(list(imageURISource));
  type defaultURISource;
  [@bs.obj]
  external defaultURISource :
    (~uri: string, ~scale: float=?, ~width: float=?, ~height: float=?, unit) => defaultURISource =
    "";
  type defaultSource =
    | URI(defaultURISource)
    | Required(Packager.required);
  type rawImageSourceJS;
  external rawImageSourceJS : 'a => rawImageSourceJS = "%identity";
  module Event = {
    type t;
    type error;
    type progress = {
      loaded: float,
      total: float
    };
    [@bs.get] external progress : t => progress = "nativeEvent";
  };
  let encodeResizeMode = (x) =>
    switch x {
    | `cover => "cover"
    | `contain => "contain"
    | `stretch => "stretch"
    | `repeat => "repeat"
    | `center => "center"
    };
  let encodeSource = (x: imageSource) =>
    switch x {
    | URI(x) => rawImageSourceJS(x)
    | Required(x) => rawImageSourceJS(x)
    | Multiple(x) => rawImageSourceJS(Array.of_list(x))
    };
  let encodeResizeMethod = (x) =>
    switch x {
    | `auto => "auto"
    | `resize => "resize"
    | `scale => "scale"
    };
  let encodeDefaultSource = (x: defaultSource) =>
    switch x {
    | URI(x) => rawImageSourceJS(x)
    | Required(x) => rawImageSourceJS(x)
    };
  let make =
      (
        ~onError=?,
        ~onLayout=?,
        ~onLoad=?,
        ~onLoadEnd=?,
        ~onLoadStart=?,
        ~resizeMode=?,
        ~source=?,
        ~style=?,
        ~testID=?,
        ~resizeMethod=?,
        ~accessibilityLabel=?,
        ~accessible=?,
        ~blurRadius=?,
        ~capInsets=?,
        ~defaultSource=?,
        ~onPartialLoad=?,
        ~onProgress=?
      ) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=Impl.view,
      ~props=
        Js.Undefined.(
          {
            "onLayout": from_opt(onLayout),
            "onError": from_opt(onError),
            "onLoad": from_opt(onLoad),
            "onLoadEnd": from_opt(onLoadEnd),
            "onLoadStart": from_opt(onLoadStart),
            "resizeMode": from_opt(UtilsRN.option_map(encodeResizeMode, resizeMode)),
            "source": from_opt(UtilsRN.option_map(encodeSource, source)),
            "style": from_opt(style),
            "testID": from_opt(testID),
            "resizeMethod": from_opt(UtilsRN.option_map(encodeResizeMethod, resizeMethod)),
            "accessibilityLabel": from_opt(accessibilityLabel),
            "accessible": from_opt(UtilsRN.optBoolToOptJsBoolean(accessible)),
            "blurRadius": from_opt(blurRadius),
            "capInsets": from_opt(capInsets),
            "defaultSource": from_opt(UtilsRN.option_map(encodeDefaultSource, defaultSource)),
            "onPartialLoad": from_opt(onPartialLoad),
            "onProgress": from_opt(UtilsRN.option_map((x, y) => x(Event.progress(y)), onProgress))
          }
        )
    );
};

include
  CreateComponent(
    {
      [@bs.module "react-native"] external view : ReasonReact.reactClass = "Image";
    }
  );
