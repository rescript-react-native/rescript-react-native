---
id: apis/CameraRoll
title: CameraRoll
wip: false
---

## Methods

- `saveToCameraRoll` allows saving photos and videos to the Camera Roll. File to be saved is specified as a tag which can be

   - on Android, a local image or video URI, such as "file:///sdcard/img.png"
   - on iOS, a local video URI or any image URI (local, remote asset-library, or base64 data URIs)

Media type (photo or video) will be automatically inferred; any file will be inferred to be a photo, unless the file extension is `mov` or `mp4`, then it will be inferred to be a video.

```reason
saveToCameraRoll(tag)
```

The function will return the URI for the saved file as a string wrapped in a Promise, `Js.Promise.t(string)`.

- `saveToCameraRollWithType` allows saving photos and videos to the Camera Roll, where the tag will be specified as above, overriding the automatically determined type.

```reason
saveToCameraRollWithType(tag, _type)
```

where `_type` can be `` `photo `` or `` `video ``.

The function will return the URI for the saved file as a string wrapped in a Promise, `Js.Promise.t(string)`.

- `getPhotos` takes as argument `getPhotosParams`

```reason
getPhotos(getPhotosParams)
```

The function will return a `photoIdentifiersPage` object wrapped in a Promise, that is `Js.Promise.t(photoIdentifiersPage)`. Array of `photoIdentifier` will contain details of photos or videos matching parameters provided in the `getPhotosParam` object.


## Types

- `getPhotosParams` can be constructed with its eponymous constructor

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
  )
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

let windowWidth = float_of_int(Dimensions.get(`window)##width);
let windowHeight = float_of_int(Dimensions.get(`window)##height);

type state = {
  tag: string,
  path: option(string),
  photos: array(CameraRoll.photoIdentifier),
};

type action =
  | SetTag(string)
  | SetPath(string)
  | SetPhotos(array(CameraRoll.photoIdentifier));

let textStyle = Style.style(~textAlign=`center, ());

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

  <View
    style={Style.style(
      ~flex=1.,
      ~flexDirection=`column,
      ~alignItems=`center,
      ~justifyContent=`spaceBetween,
      (),
    )}>
    <View
      style={Style.style(
        ~width=Style.pt(0.8 *. windowWidth),
        ~height=Style.pt(0.6 *. windowHeight),
        ~margin=Style.pt(0.1 *. windowWidth),
        // ~marginBottom=Style.pt(0.1 *. windowWidth),
        ~justifyContent=`spaceAround,
        (),
      )}>
      <View
        style={Style.style(
          ~width=Style.pt(0.8 *. windowWidth),
          ~height=Style.pt(0.56 *. windowWidth),
          ~borderWidth=1.,
          ~justifyContent=`center,
          (),
        )}>
        {switch (state.path) {
         | None =>
           <View>
             <Text style=textStyle>
               "Press the Save Photo button"->React.string
             </Text>
             <Text style=textStyle> "below to load photo"->React.string </Text>
           </View>

         | Some(p) =>
           <Image
             style={Style.style(
               ~width=Style.pt(0.8 *. windowWidth),
               ~height=Style.pt(0.56 *. windowWidth),
               (),
             )}
             source={Image.Source.fromUriSource(Image.uriSource(~uri=p, ()))}
           />
         }}
      </View>
      <View>
        <Text style=textStyle>
          "Enter a path for a photo to save,"->React.string
        </Text>
        <Text style=textStyle>
          "or try the example given below"->React.string
        </Text>
        <TextInput
          style={Style.array([|
            textStyle,
            Style.style(
              ~borderRadius=8.,
              ~padding=Style.pt(4.),
              ~borderWidth=1.,
              ~backgroundColor=Color.linen,
              (),
            ),
          |])}
          multiline=true
          defaultValue="https://images.unsplash.com/photo-1520453803296-c39eabe2dab4"
          value={state.tag}
          onChangeText={s => dispatch(SetTag(s))}
        />
        <Button
          onPress={_ => savePhoto(state.tag)}
          title={js|Save a Photo|js}
        />
      </View>
    </View>
    <View
      style={Style.style(
        ~height=Style.pt(0.25 *. windowHeight),
        ~justifyContent=`spaceBetween,
        (),
      )}>
      <View>
        <Text style=textStyle>
          "Saved photo will be in the Camera Roll"->React.string
        </Text>
        <Button onPress={_ => getPhotos()} title={js|Open CameraRoll|js} />
      </View>
      <View style={Style.style(~height=Style.pt(0.15 *. windowHeight), ())}>
        <ScrollView horizontal=true>
          {React.array(
             Array.mapi(
               (i, s) =>
                 <Image
                   style={Style.style(
                     ~width=Style.pt(0.21 *. windowHeight),
                     ~height=Style.pt(0.15 *. windowHeight),
                     (),
                   )}
                   source={Image.Source.fromUriSource(
                     Image.uriSource(~uri=s##node##image##uri, ()),
                   )}
                   key={string_of_int(i)}
                 />,
               state.photos,
             ),
           )}
        </ScrollView>
      </View>
    </View>
  </View>;
};

```
