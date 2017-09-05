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
        render: fun () =>
          <ImageBackground
            style=(
              style [flex 1., justifyContent `center, alignItems `center, height 400., width 300.]
            )
            imageStyle=(style [flex 1.])
            source=(
              URI ImageBackground.(
                    imageURISource
                      uri::"https://lorempixel.com/output/abstract-h-c-250-400-8.jpg" ()
                  )
            )>
            <View style=(style [backgroundColor "#FFFFFF", padding 5.])>
              <Text> (ReasonReact.stringToElement "Much image such background!") </Text>
            </View>
          </ImageBackground>
      }
    |]
  );
