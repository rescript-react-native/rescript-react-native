---
id: apis/CameraRoll
title: CameraRoll
---

## Methods

### `saveToCameraRoll`

Allows saving photos and videos to the Camera Roll or Photo Gallery. File to be
saved is specified as a tag (of type `string`) which can be

- on Android, a local image or video URI, such as "file:///sdcard/img.png"
- on iOS, a local video URI or any image URI (local, remote asset-library, or
  base64 data URIs)

Media type (photo or video) will be automatically inferred; any file will be
inferred to be a photo, unless the file extension is `mov` or `mp4`, then it
will be inferred to be a video.

The function will return the URI for the saved file as a string wrapped in a
Promise.

```reason
saveToCameraRoll: string => Js.Promise.t(string)
```

### `saveToCameraRollWithType`

Allows saving photos and videos to the Camera Roll, where the tag will be
specified as above, overriding the automatically determined type by specifying
one of the polymorphic variants `` `photo `` or `` `video ``.

The function will return the URI for the saved file as a string wrapped in a
Promise.

```reason
saveToCameraRollWithType: (string, [ | `photo | `video]) => Js.Promise.t(string)
```

### `getPhotos`

Allows searching for photos or videos matching given parameters.

Takes as argument `getPhotosParams` and returns a `photoIdentifiersPage` object
wrapped in a Promise. `edges` key of the `photoIdentifiersPage` object would be
of type `array(photoIdentifier)`, where each `photoIdentifier` object would
contain details of each photo or video matching parameters provided in the
`getPhotosParam` object.

```reason
getPhotos: getPhotosParams => Js.Promise.t(photoIdentifiersPage)
```

## Types

- `getPhotosParams` can be constructed with the constructor of the same name
  - `first` takes an integer which specifies the number of files for which
    details will be returned. Files will match in reverse order (i.e. most
    recent first)
  - `after` takes a string which should be obtained from `photoIdentifiersPage`
    returned in a previous `getPhotos` call, under the `end_cursor` key
    contained in turn under the `page_info` key.

```reason
getPhotosParams:
  (
    ~first: int,
    ~after: string=?,
    ~groupTypes: [@bs.string] [
                   | `Album
                   | `All
                   | `Event
                   | `Faces
                   | `Library
                   | `PhotoStream
                   | `SavedPhotos
                 ]
                   =?,
    ~groupName: string=?,
    ~assetType: [@bs.string] [ | `All | `Videos | `Photos]=?,
    ~mimeTypes: array(string)=?,
    unit
  ) => getPhotosParams
```

- `photoIdentifiersPage`

```reason
type photoIdentifiersPage = {
  .
  "edges": array(photoIdentifier),
  "page_info": {
    .
    "has_next_page": bool,
    "start_cursor": Js.Nullable.t(string),
    "end_cursor": Js.Nullable.t(string),
  },
};
```

- `photoIdentifier`

```reason
type photoIdentifier = {
  .
  "node": {
    .
    "_type": string,
    "group_name": string,
    "image": {
      .
      "filename": string,
      "uri": string,
      "height": float,
      "width": float,
      "isStored": Js.Nullable.t(bool),
      "playableDuration": float,
    },
    "timestamp": float,
    "location":
      Js.Nullable.t({
        .
        "latitude": Js.Nullable.t(float),
        "longitude": Js.Nullable.t(float),
        "altitude": Js.Nullable.t(float),
        "heading": Js.Nullable.t(float),
        "speed": Js.Nullable.t(float),
      }),
  },
};
```

## Example

```reason
open ReactNative;

let windowWidth = Dimensions.get(`window)##width;
let windowHeight = Dimensions.get(`window)##height;

type state = {
  tag: string,
  path: option(string),
  photos: array(CameraRoll.photoIdentifier),
};

type action =
  | SetTag(string)
  | SetPath(string)
  | SetPhotos(array(CameraRoll.photoIdentifier));

let styles = Style.(
  StyleSheet.create({
    "container":
      style(
        ~flex=1.,
        ~flexDirection=`column,
        ~alignItems=`center,
        ~justifyContent=`spaceBetween,
        (),
      ),
    "getPhotosExample":
      style(
        ~height=pt(0.25 *. windowHeight),
        ~justifyContent=`spaceBetween,
        (),
      ),
    "saveToCameraRollExample":
      style(
        ~width=pt(0.8 *. windowWidth),
        ~height=pt(0.6 *. windowHeight),
        ~margin=pt(0.1 *. windowWidth),
        ~justifyContent=`spaceAround,
        (),
      ),
    "image":
      style(
        ~width=pt(0.8 *. windowWidth),
        ~height=pt(0.56 *. windowWidth),
        (),
      ),
    "imageContainer":
      style(
        ~width=pt(0.8 *. windowWidth),
        ~height=pt(0.56 *. windowWidth),
        ~borderWidth=1.,
        ~justifyContent=`center,
        (),
      ),
    "text": style(~textAlign=`center, ()),
    "textInput":
      style(
        ~textAlign=`center,
        ~borderRadius=8.,
        ~padding=pt(4.),
        ~borderWidth=1.,
        ~backgroundColor=Color.linen,
        (),
      ),
    "thumbnail":
      style(
        ~width=pt(0.21 *. windowHeight),
        ~height=pt(0.15 *. windowHeight),
        (),
      ),
    "thumbnails":
      style(
        ~height=pt(0.15 *. windowHeight),
        (),
      ),
  })
);

let styledText = s => {
  <Text style=styles##text> s->React.string </Text>;
};

let thumbnails = photos => {
  <View style=styles##thumbnails>
    <ScrollView horizontal=true>
      {photos
       ->Belt.Array.mapWithIndex((i, s) =>
           <Image
             style=styles##thumbnail
             source={Image.Source.fromUriSource(
               Image.uriSource(~uri=s##node##image##uri, ()),
             )}
             key={string_of_int(i)}
           />
         )
       ->React.array}
    </ScrollView>
  </View>;
};

let inputBox = (tag, dispatch) => {
  <TextInput
    style=styles##textInput
    multiline=true
    defaultValue="https://images.unsplash.com/photo-1520453803296-c39eabe2dab4"
    value=tag
    onChangeText={s => dispatch(SetTag(s))}
  />;
};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | SetTag(uri) => {...state, tag: uri}
        | SetPath(uri) => {...state, path: Some(uri)}
        | SetPhotos(a) => {...state, photos: a}
        },
      {
        tag: "https://images.unsplash.com/photo-1520453803296-c39eabe2dab4",
        path: None,
        photos: [||],
      },
    );

  let getPhotos = () => {
    Js.Promise.(
      CameraRoll.getPhotos(
        CameraRoll.getPhotosParams(
          ~first=20,
          ~assetType=`Photos,
          ~groupTypes=`All,
          (),
        ),
      )
      |> then_(r => resolve(dispatch(SetPhotos(r##edges))))
      |> catch(err => resolve(Js.Console.warn(err)))
      |> ignore
    );
  };

  let savePhoto = uri => {
    Js.Promise.(
      CameraRoll.saveToCameraRoll(uri)
      |> then_(r => resolve(dispatch(SetPath(r))))
      |> catch(err => resolve(Js.Console.warn(err)))
      |> ignore
    );
  };

  <View style=styles##container>
    <View style=styles##saveToCameraRollExample>
      <View style=styles##imageContainer>
        {switch (state.path) {
         | None =>
           // default view, before a photo is saved to the Camera Roll or Photo Library
           <View>
             {styledText("Press the Save Photo button")}
             {styledText("below to load photo")}
           </View>
         | Some(p) =>
           // Once a photo is saved to the Camera Roll or Photo Library, it will be displayed in this view
           <Image
             style=styles##image
             source={Image.Source.fromUriSource(Image.uriSource(~uri=p, ()))}
           />
         }}
      </View>
      <View>
        {styledText("Enter a path for a photo to save,")}
        {styledText("or try the example given below")}
        // TextInput box to try other photo sources
        {inputBox(state.tag, dispatch)}
        // An attempt will be made to save the photo file specified in the TextInput box to the Camera Roll or Photo Library once the button below is pressed
        <Button
          onPress={_ => savePhoto(state.tag)}
          title={js|Save a Photo|js}
        />
      </View>
    </View>
    <View style=styles##getPhotosExample>
      <View>
        {styledText("Saved photo will appear in the Camera Roll")}
        // An attempt will be made to get the most recent 20 photos from the Camera Roll or Photo Library
        <Button onPress={_ => getPhotos()} title={js|Open CameraRoll|js} />
      </View>
      {thumbnails(state.photos)}
    </View>
  </View>;
};

```
