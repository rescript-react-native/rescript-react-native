open BsReactNative;
open Utils;

let title = "<ImageBackground>";

let exampleType = Multiple;

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
            style={style([
              flex(1.),
              justifyContent(Center),
              alignItems(Center),
              height(Pt(400.)),
              width(Pt(300.)),
            ])}
            imageStyle={style([flex(1.)])}
            source={
                     `URI(
                       Image.(
                         imageURISource(
                           ~uri=
                             "https://lorempixel.com/output/abstract-h-c-250-400-8.jpg",
                           (),
                         )
                       ),
                     )
                   }>
            <View
              style={style([
                backgroundColor(String("#FFFFFF")),
                padding(Pt(5.)),
              ])}>
              <Text> {ReasonReact.string("Nested text")} </Text>
            </View>
          </ImageBackground>,
      },
    |]
  );
