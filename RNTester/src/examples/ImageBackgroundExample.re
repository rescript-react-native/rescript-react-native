open ReactNative;

let title = "<ImageBackground>";

let description = "A very basic ImageBackground component";

let displayName = "ImageBackground";

let examples: array Example.t =
  Style.(
    [|
      {
        title: "Example.com",
        description: None,
        render: fun () => {
          /* let source = WebView.source uri::"https://example.com" (); */
          let source = ImageBackgroundRe.ImageBackground.imageURISource uri::"http://via.placeholder.com/250x400.jpg" ();
        <ImageBackground
            style=(style [height 400., width 250.])
            source>
          <View style=(style [backgroundColor "#527FE4", padding 5.])>
           <Text> (ReasonReact.stringToElement "Hello World!") </Text>
          </View>
        </ImageBackground>
        }
      }
    |]
  );