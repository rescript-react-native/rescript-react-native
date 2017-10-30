open ReactNative;

let title = "<WebView>";

let description = "Simple React Native WebView.";

let displayName = "WebViewExample";

let examples: array(Example.t) =
  Style.(
    [|
      {
        title: "Example.com",
        description: None,
        render: () => {
          let source = WebView.source(~uri="https://example.com", ());
          <View style=(style([backgroundColor("#527FE4"), padding(5.)]))>
            <WebView style=(style([height(400.)])) source />
          </View>
        }
      }
    |]
  );
