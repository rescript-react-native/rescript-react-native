open BsReactNative;

let title = "<ImageBackground>";

let description = "A very basic ImageBackground component";

let displayName = "ImageBackground";

let examples: array(Example.t) =
  Style.(
    [|
      {
        title: "ImageBackground example",
        description: None,
        render: () =>
          <ImageBackground
            style=(
              style([
                flex(1.),
                justifyContent(`Center),
                alignItems(`Center),
                height(Px(400.)),
                width(Px(300.))
              ])
            )
            imageStyle=(style([flex(1.)]))
            source=(
              URI(
                Image.(
                  imageURISource(
                    ~uri="https://lorempixel.com/output/abstract-h-c-250-400-8.jpg",
                    ()
                  )
                )
              )
            )>
            <View style=(style([backgroundColor("#FFFFFF"), padding(Px(5.))]))>
              <Text> (ReasonReact.stringToElement("Nested text")) </Text>
            </View>
          </ImageBackground>
      }
    |]
  );
