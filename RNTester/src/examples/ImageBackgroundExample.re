open ReactNative;

let title = "<ImageBackground>";

let description = "A very basic ImageBackground component";

let displayName = "ImageBackground";

let examples: array Example.t =
Style.(
  [|
    {
      title: "ImageBackground example",
      description: None,
      render: fun () => {
        <ImageBackground
        style=(style [flex 1.,height 400., width 250., borderColor "green", borderWidth 2.])
        imageStyle=(style [flex 1., borderColor "red", borderWidth 2.])
        source=(URI ImageBackground.(
          imageURISource
            uri::(
              "http://lorempixel.com/output/abstract-h-c-250-400-8.jpg"
            )
            ()
        ))
        >
          <View style=(style [backgroundColor "#527FE4", padding 5.])>
            <Text> (ReasonReact.stringToElement "Hello World!") </Text>
          </View>
        </ImageBackground>
      }
    }
  |]
);