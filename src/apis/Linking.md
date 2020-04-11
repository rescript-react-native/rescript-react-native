---
id: apis/Linking
title: Linking
officialDoc: https://reactnative.dev/docs/linking.html
---

Only for projects supporting Native Code. Requires the project to have been
created using `react-native init` or ejected afterwards if created using
`expo init` or `create-react-native-app`.

## Types

### `extra`

To be used with the [`sendIntentWithExtras`](#sendIntentWithExtras) method for
sending text and data. May be created by the constructor of the same name.

```reason
external extra: (~key: string, ~value: 'a) => extra
```

### `url`

```reason
type url = {url: string};
```

## Methods

### `openURL`

To attempt opening a URL. URL should be specified as `string`, and the method
returns `unit` wrapped in a promise. Promise is resolved if the user approves
the request (through the _open dialog_) or the link is opened automatically. If
the user rejects the request or there are no registered applications supporting
the URL, the promise is rejected. It is recommended to use the `canOpenURL`
method beforehand, to verify that the URL can indeed be opened.

```reason
openURL: string => Js.Promise.t(unit)
```

### `canOpenURL`

To determine whether a URL can be opened by registered applications. URL should
be specified as `string`, and the method returns `bool` wrapped in a promise.
The promise will be rejected if it is impossible to check if the URL can be
opened on Android or for iOS 9 and later, an appropriate entry does not exist
for the `LSApplicationQueriesSchemes` key in `Info.plist`.

```reason
canOpenURL: string => Js.Promise.t(bool)
```

### `getInitialURL`

Returns a nullable string wrapped in a promise. If the app was launched to open
a link, that link will be returned as a `Js.Null(string)` value, otherwise
`Js.null` will be returned.

```reason
getInitialURL: unit => Js.Promise.t(Js.Null.t(string))
```

### `openSettings`

_As of React Native 0.60_

Attempts to open the Settings app and display custom settings for the app, if
any. This method returns an unspecified object (type `any`) wrapped in a
promise.

```reason
openSettings: unit => Js.Promise.t('a)
```

### `sendIntent`

_As of React Native 0.59.8_

```reason
sendIntent: string => unit
```

To use `Intent` actions on Android for sending text to other apps. This method
returns `unit`.

### `sendIntentWithExtras`

_As of React Native 0.59.8_

To use `Intent` actions on Android for sending text and data (to be provided as
an array of type `extra` objects) to other apps. This method returns `unit`.

```reason
sendIntentWithExtras: (string, array(extra)) => unit
```

where the type `extra` can be created with the `extra` constructor

```reason
extra: (~key: string, ~value: 'a) => extra
```

### `addEventListener`

To specify a handler for the specified event type. Only the "url" event is
supported, which should be specified using the polymorphic variant `` `url ``.
The handler should be of type [`url`](#url)` => unit`. The URL can be obtained
from the returned object using the `.url` property. This method returns `unit`.

```reason
addEventListener: ([ `url], url => unit) => unit
```

### `removeEventListener`

To remove a handler for the specified event type. Only the "url" event is
supported, which should be specified using the polymorphic variant `` `url ``.
The handler should be of type [`url`](#url)` => unit`. This method returns
`unit`.

```reason
removeEventListener([ `url], url => unit) => unit
```

### Example

```reason
open ReactNative;

let windowHeight = Dimensions.get(`window).height;
let windowWidth = Dimensions.get(`window).width;

let containerStyle =
  Style.(
    style(
      ~width=windowWidth->dp,
      ~height=windowHeight->dp,
      ~justifyContent=`center,
      ~alignItems=`center,
      (),
    )
  );

type state = {url: option(string)};

type action =
  | SetURL(option(string));

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | SetURL(v) => {url: v}
        },
      {url: None},
    );

  let handler = s => {
    s.url->Js.Console.warn;
  };

  let handlePromise = url =>
    Js.Promise.(
      Linking.openURL(url)
      |> then_(() => resolve(dispatch(SetURL(Some(url)))))
      |> catch(err => resolve(err->Js.Console.warn))
      |> ignore
    );

  // Listener will only receive URLs which your app is
  // registered to handle
  // https:// resource below will not be captured here
  React.useEffect0(() => {
    Linking.addEventListener(`url, handler);
    Some(() => Linking.removeEventListener(`url, handler));
  });

  <View style=containerStyle>
    <Text>
      {{Belt.Option.getWithDefault(state.url, "No URL requested")}
       ->React.string}
    </Text>
    <Button
      onPress={_ =>
        handlePromise(
          "https://github.com/reason-react-native/reason-react-native/",
        )
      }
      title="Open Repo"
    />
    // This will only work if you have registered myapp:// as
    // custom URL scheme for your app
    // Otherwise this will throw an error on the Yellow Box
    <Button
      onPress={_ => handlePromise("myapp://screen")}
      title="Internal URL"
    />
  </View>;
};

```
