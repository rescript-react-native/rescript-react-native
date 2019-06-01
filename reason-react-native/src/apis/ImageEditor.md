---
id: apis/ImageEditor
title: ImageEditor
officialDoc: https://facebook.github.io/react-native/docs/imageeditor
---

## Methods

### `cropImage`

`cropImage` takes named arguments `uri` (of type `source`), `cropData` (of type
`cropData`), `success` (callback function of type `string => unit`) and
`failure` (callback function of type `(~code: int, ~message: string) => unit`)
and returns `unit`

```reason
cropImage: (
  ~uri: source,
  ~cropData: cropData,
  ~success: string => unit,
  ~failure: (~code: int, ~message: string) => unit
) => unit
```

If the method succeeds, the handler is passed the path of the resulting cropped
image as `string`.

### `fromRequired`

To convert a `Packager.required` object into [`source`](#source).

```reason
fromRequired: Packager.required => source
```

### `fromUriSource`

To convert a URI given as a `string` into [`source`](#source).

```reason
fromUriSource: string => source
```

## Types

### `source`

An abstract type created using the [`fromRequired`](#fromRequired) and
[`fromUriSource`](#fromUriSource) methods.

### `offset`

An abstract type created using the constructor of the same name which takes
named arguments `x` and `y` of type `int`.

```reason
offset: (~x: int, ~y: int) => offset
```

### `size`

An abstract type created using the constructor of the same name which takes
named arguments `width` and `height` of type `int`.

```reason
size: (~width: int, ~height: int) => size
```

### `cropData`

An abstract type created using the constructor of the same name which takes
named arguments `offset` (of type `offset`) and `size` (of type `size`) and
optional arguments `displaySize` (of type `size`) and `resizeMode` (one of
polymorphic variants `` `contain ``, `` `cover ``, `` `stretch ``).

```reason
cropData: (
  ~offset: offset,
  ~size: size,
  ~displaySize: size=?,
  ~resizeMode=[ | `contain | `cover | `stretch]=?,
  unit
) => cropData
```

## Example

```reason
open ReactNative;

// hardcoding actual image dimensions
let imageWidth = 3396.;
let imageHeight = 2388.;

let windowWidth = Dimensions.get(`window)##width;
let windowHeight = Dimensions.get(`window)##height;

let displayWidth = windowWidth *. 0.9;
let displayHeight = windowWidth *. 0.9 *. imageHeight /. imageWidth;

let styles =
  Style.(
    StyleSheet.create({
      "container":
        style(
          ~width=windowWidth->dp,
          ~height=windowHeight->dp,
          ~flexDirection=`column,
          ~alignItems=`center,
          ~justifyContent=`center,
          (),
        ),
      "frame":
        style(
          ~width=displayWidth->dp,
          ~height=displayHeight->dp,
          ~alignItems=`center,
          ~justifyContent=`center,
          ~borderWidth=StyleSheet.hairlineWidth,
          (),
        ),
    })
  );

type state = {
  path: option(string),
  imageLoaded: bool,
};

type action =
  | SetPath(option(string))
  | SetImageLoaded;

let imageUri = "https://images.unsplash.com/photo-1520453803296-c39eabe2dab4";
let uri = ImageEditor.fromUriSource(imageUri);

let handleCropImage = (cropData, send, handler) =>
  ImageEditor.cropImage(
    ~uri,
    ~cropData,
    ~success=successURI => send(handler(successURI)),
    ~failure=(~code, ~message) => message->Js.Console.warn,
  );

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | SetPath(p) => {...state, path: p}
        | SetImageLoaded => {...state, imageLoaded: true}
        },
      {path: None, imageLoaded: false},
    );

  let size =
    ImageEditor.size(
      ~width=(imageWidth *. 0.5)->floor->truncate,
      ~height=(imageHeight *. 0.5)->floor->truncate,
    );

  let cropData = offset =>
    ImageEditor.cropData(
      ~offset,
      ~size,
      ~resizeMode=`cover,
      (),
    );

  <View style=styles##container>
      <Text>
        "Click on a quadrant of the image to crop it."->React.string
      </Text>
      <View style=styles##frame>
        <TouchableOpacity
          onPress={e =>
            handleCropImage(
              ImageEditor.offset(
                ~x=
                  {e##nativeEvent##locationX /. displayWidth < 0.5
                     ? 0 : (0.5 *. imageWidth)->floor->truncate},
                ~y=
                  {e##nativeEvent##locationY /. displayHeight < 0.5
                     ? 0 : (0.5 *. imageHeight)->floor->truncate},
              )
              ->cropData,
              dispatch,
              link =>
              SetPath(Some(link))
            )
          }>
          <Image
            source={Image.Source.fromUriSource(
              Image.uriSource(
                ~uri=
                  Belt.Option.getWithDefault(
                    state.path,
                    imageUri,
                  ),
                ~width=displayWidth,
                ~height=
                  if (state.imageLoaded) {
                    displayHeight;
                  } else {
                    0.;
                  },
                (),
              ),
            )}
            resizeMode=`contain
            onLoadEnd={() => dispatch(SetImageLoaded)}
          />
        </TouchableOpacity>
        {state.imageLoaded
           ? React.null
           : <Text> "Please wait while image is loaded."->React.string </Text>}
      </View>
      <Button title="Reset Image" onPress={_ => dispatch(SetPath(None))} />
    </View>;
};
```
