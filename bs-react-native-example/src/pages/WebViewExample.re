open BsReactNative;

open Utils;

let title = "<WebView>";

let exampleType = Multiple;

let description = "Simple React Native WebView.";

let displayName = "WebViewExample";

let examples: array(Example.t) =
  Style.(
    [|
      {
        title: "Example.com",
        description: None,
        render: () => {
          let source = WebView.sourceUri(~uri="https://example.com", ());
          <View
            style={style([
              backgroundColor(String("#527FE4")),
              padding(Pt(5.)),
            ])}>
            <WebView style={style([height(Pt(400.))])} source />
          </View>;
        },
      },
    |]
  );
