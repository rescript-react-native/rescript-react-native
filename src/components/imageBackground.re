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
      ~source=?,
      ~style=?,
      ~imageStyle=?,
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
    ~reactClass=view,
    ~props={
      "onLayout": onLayout,
      "onError": onError,
      "onLoad": onLoad,
      "onLoadEnd": onLoadEnd,
      "onLoadStart": onLoadStart,
      "resizeMode":
        UtilsRN.option_map(
          x =>
            switch (x) {
            | `cover => "cover"
            | `contain => "contain"
            | `stretch => "stretch"
            | `repeat => "repeat"
            | `center => "center"
            },
          resizeMode,
        ),
      "source":
        UtilsRN.option_map(
          (x: Image.imageSource) =>
            switch (x) {
            | `URI(x) => rawImageSourceJS(x)
            | `Required(x) => rawImageSourceJS(x)
            | `Multiple(x) => rawImageSourceJS(Array.of_list(x))
            },
          source,
        ),
      "style": style,
      "imageStyle": imageStyle,
      "testID": testID,
      "resizeMethod":
        UtilsRN.option_map(
          x =>
            switch (x) {
            | `auto => "auto"
            | `resize => "resize"
            | `scale => "scale"
            },
          resizeMethod,
        ),
      "accessibilityLabel": accessibilityLabel,
      "accessible": accessible,
      "blurRadius": blurRadius,
      "capInsets": capInsets,
      "defaultSource":
        UtilsRN.option_map(
          (x: Image.defaultSource) =>
            switch (x) {
            | `URI(x) => rawImageSourceJS(x)
            | `Required(x) => rawImageSourceJS(x)
            },
          defaultSource,
        ),
      "onPartialLoad": onPartialLoad,
      "onProgress":
        UtilsRN.option_map((x, y) => x(Event.progress(y)), onProgress),
    },
  );