include Image;

[@react.component]
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
      _,
    ) =>
  <ReactNative.Animated.Image
    ?onError
    ?onLayout
    ?onLoad
    ?onLoadEnd
    ?onLoadStart
    ?resizeMode
    source={encodeSource(source)}
    ?style
    ?testID
    ?resizeMethod
    ?accessibilityLabel
    ?accessible
    ?blurRadius
    capInsets=?{Types.toEdgeInsets(capInsets)}
    defaultSource=?{defaultSource->Belt.Option.map(encodeDefaultSource)}
    ?onPartialLoad
    onProgress=?{
      onProgress->Belt.Option.map((cb, e) => cb(Event.progress(e)))
    }
  />;
