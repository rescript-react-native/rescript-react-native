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
        style=(style [height 400., width 250.])
        source=(URI ImageBackground.(
          imageURISource
            uri::(
              "http://via.placeholder.com/250x400.jpg"
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