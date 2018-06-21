open Utils;

type item = {
  key: string,
  exampleType,
  displayName: string,
  title: string,
  description: string,
  examples: array(Example.t),
};

module type ExampleT = {
  let exampleType: exampleType;
  let displayName: string;
  let title: string;
  let description: string;
  let examples: array(Example.t);
};

module MakeExample = (Example: ExampleT) => {
  let item = key => {
    key,
    exampleType: Example.exampleType,
    displayName: Example.displayName,
    title: Example.title,
    description: Example.description,
    examples: Example.examples,
  };
};

module Button = MakeExample(ButtonExample);

module View = MakeExample(ViewExample);

module WebView = MakeExample(WebViewExample);

module ImageBackground = MakeExample(ImageBackgroundExample);

module NetInfo = MakeExample(NetInfoExample);

module Geolocation = MakeExample(GeolocationExample);

module DrawerLayoutAndroid = MakeExample(DrawerLayoutAndroid);

let components: array(item) = [|
  Button.item("ButtonExample"),
  View.item("ViewExample"),
  WebView.item("WebViewExample"),
  ImageBackground.item("ImageBackground"),
  NetInfo.item("NetInfo"),
  Geolocation.item("Geolocation"),
  DrawerLayoutAndroid.item("DrawerLayoutAndroid"),
|];