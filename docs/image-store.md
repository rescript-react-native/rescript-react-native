---
title: ImageStore
---

>**iOS only**

API which allows to use native iOS Image Store.

## Example of use

```re
type action =
  | SetImageUri(string);

type state = {imageUri: option(string)};

let component = ReasonReact.reducerComponent("ImageExample");

let make = _children => {
  ...component,
  initialState: () => {imageUri: None},
  reducer: (action: action, _state: state) =>
    switch (action) {
    | SetImageUri(imageUri) =>
      ReasonReact.Update({imageUri: Some(imageUri)})
    },
  render: self =>
    <View>
      <Button
        onPress=(
          () => {
            ImageStore.addImageFromBase64(
              image,
              uri => self.send(SetImageUri(uri)),
              _ => (),
            );
            ();
          }
        )
        title="Set Image Uri"
      />
      (
        switch (self.state.imageUri) {
        | Some(imageUri) =>
          <Image
            source=(
              URI(
                Image.imageURISource(
                  ~uri=imageUri,
                  ~width=200.,
                  ~height=200.,
                  (),
                ),
              )
            )
          />
        | None => ReasonReact.null
        }
      )
    </View>,
};
```

## Methods

### hasImageForTag
Checks if Image Store contains image for given tag (URI).

```
let hasImageForTag: (string, bool => unit) => unit;
```

#### Arguments
 - First argument - image URI
 - Second argument - callback which takes the boolean result as an argument   

### removeImageForTag
Removes image from Image Store for given tag (URI). Images are stored in memory and must be manually removed when you are finished with them, otherwise they will continue to use up RAM until the app is terminated

```
let removeImageForTag: string => unit;
```

#### Arguments
 - First argument - image URI   

### addImageFromBase64
Adds image to Store.

```
let addImageFromBase64: (string, string => unit, error => unit) => string;
```

#### Arguments
 - First argument - image string in base64
 - Second argument - success callback which gets image URI as an aargument
 - Third argument - failure callback which gets error as an argument   

### getBase64ForTag
Retrieves the base64-encoded image data for given tag (URI).

```
let getBase64ForTag: (string, string => unit, error => unit) => unit;
```

#### Arguments
 - First argument - Image URI in base64
 - Second argument - success callback which gets image string in base64 as an aargument
 - Third argument - failure callback which gets error as an argument