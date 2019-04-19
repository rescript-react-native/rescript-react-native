[@bs.module "react-native"]
external view: ReasonReact.reactClass = "ImageBackground";

module Event = {
  type t;
  type error;
  type progress = {
    loaded: float,
    total: float,
  };
  [@bs.get] external progress: t => progress = "nativeEvent";
};

type rawImageSourceJS;

external rawImageSourceJS: 'a => rawImageSourceJS = "%identity";

let make =
    (
      ~onError=?,
      ~onLayout=?,
      ~onLoad=?,
      ~onLoadEnd=?,
      ~onLoadStart=?,
      ~resizeMode=?,
      ~source: option(Image.imageSource)=?,
      ~style=?,
      ~imageStyle=?,
      ~testID=?,
      ~resizeMethod=?,
      ~accessibilityLabel=?,
      ~accessible=?,
      ~blurRadius=?,
      ~capInsets=?,
      ~defaultSource: option(Image.defaultSource)=?,
      ~onPartialLoad=?,
      ~onProgress=?,
    ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=view,
    ~props={
      "onLayout": onLayout,
      "onError": onError,
      "onLoad": onLoad,
      "onLoadEnd": onLoadEnd,
      "onLoadStart": onLoadStart,
      "resizeMode":
        resizeMode->Belt.Option.map(
          fun
          | `cover => "cover"
          | `contain => "contain"
          | `stretch => "stretch"
          | `repeat => "repeat"
          | `center => "center",
        ),
      "source":
        source->Belt.Option.map(
          fun
          | `URI(x) => rawImageSourceJS(x)
          | `Required(x) => rawImageSourceJS(x)
          | `Multiple(x) => rawImageSourceJS(Array.of_list(x)),
        ),
      "style": style,
      "imageStyle": imageStyle,
      "testID": testID,
      "resizeMethod":
        resizeMethod->Belt.Option.map(
          fun
          | `auto => "auto"
          | `resize => "resize"
          | `scale => "scale",
        ),
      "accessibilityLabel": accessibilityLabel,
      "accessible": accessible,
      "blurRadius": blurRadius,
      "capInsets": capInsets,
      "defaultSource":
        defaultSource->Belt.Option.map(
          fun
          | `URI(x) => rawImageSourceJS(x)
          | `Required(x) => rawImageSourceJS(x),
        ),
      "onPartialLoad": onPartialLoad,
      "onProgress":
        onProgress->Belt.Option.map((x, y) => x(Event.progress(y))),
    },
  );
