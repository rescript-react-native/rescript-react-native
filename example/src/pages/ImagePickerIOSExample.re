open BsReactNative;

open Utils;

let exampleType = Multiple;

let displayName = "ImagePickerIOS";

let title = "<ImagePickerIOSExample>";

let description = "ImagePickerIOS API";

let styles =
  StyleSheet.create(
    Style.{
      "pageStyle": style([flex(1.), flexGrow(1.)]),
      "viewPager":
        style([alignItems(Center), padding(Pt(20.)), height(Pt(400.))]),
    },
  );

module CanRecordVideosExample = {
  type action =
    | UpdateCanRecordVideos(bool);

  type state = {canRecordVideos: bool};

  let component = ReasonReact.reducerComponent("CanRecordVideosExample");

  let make = _children => {
    ...component,
    initialState: () => {canRecordVideos: false},
    reducer: (action: action, _state: state) =>
      switch (action) {
      | UpdateCanRecordVideos(canRecordVideos) =>
        Update({canRecordVideos: canRecordVideos})
      },
    didMount: ({send}) =>
      ImagePickerIOS.canRecordVideos(() =>
        send(UpdateCanRecordVideos(true))
      ),
    render: ({state}) =>
      <View style=styles##pageStyle key="1">
        <Text> {ReasonReact.string("Can we record videos?")} </Text>
        <Text>
          {ReasonReact.string(string_of_bool(state.canRecordVideos))}
        </Text>
      </View>,
  };
};

module CanUseCameraExample = {
  type action =
    | UpdateCanUseCamera(bool);

  type state = {canUseCamera: bool};

  let component = ReasonReact.reducerComponent("CanRecordVideosExample");

  let make = _children => {
    ...component,
    initialState: () => {canUseCamera: false},
    reducer: (action: action, _state: state) =>
      switch (action) {
      | UpdateCanUseCamera(canRecordVideos) =>
        Update({canUseCamera: canRecordVideos})
      },
    didMount: ({send}) =>
      ImagePickerIOS.canUseCamera(() => send(UpdateCanUseCamera(true))),
    render: ({state}) =>
      <View style=styles##pageStyle key="1">
        <Text> {ReasonReact.string("Can we use camera?")} </Text>
        <Text>
          {ReasonReact.string(string_of_bool(state.canUseCamera))}
        </Text>
      </View>,
  };
};

module CameraDialogExample = {
  type action =
    | UpdateCanUseCamera(bool);

  type state = {canUseCamera: bool};

  let component = ReasonReact.reducerComponent("CanRecordVideosExample");

  let openCameraDialog = (_event, _self) =>
    ImagePickerIOS.openCameraDialog(
      ~videoMode=false,
      ~onSuccess=_uri => Js.log("Success!"),
      ~onError=error => Js.log(error),
    );

  let make = _children => {
    ...component,
    initialState: () => {canUseCamera: false},
    reducer: (action: action, _state: state) =>
      switch (action) {
      | UpdateCanUseCamera(canRecordVideos) =>
        Update({canUseCamera: canRecordVideos})
      },
    render: ({handle}) =>
      <View style=styles##pageStyle key="1">
        <TouchableOpacity onPress={handle(openCameraDialog)}>
          <Text> {ReasonReact.string("OPEN CAMERA DIALOG")} </Text>
        </TouchableOpacity>
      </View>,
  };
};

module SelectDialogExample = {
  type action =
    | UpdateImageUri(string);

  type state = {imageUri: string};

  let component = ReasonReact.reducerComponent("CanRecordVideosExample");

  let openCameraDialog = (_event, {ReasonReact.send}) =>
    ImagePickerIOS.openSelectDialog(
      ~showImages=true,
      ~showVideos=true,
      ~onSuccess=uri => send(UpdateImageUri(uri)),
      ~onError=error => Js.log(error),
    );

  let make = _children => {
    ...component,
    initialState: () => {imageUri: ""},
    reducer: (action: action, _state: state) =>
      switch (action) {
      | UpdateImageUri(imageUri) => Update({imageUri: imageUri})
      },
    render: ({handle, state}) =>
      <View style=styles##pageStyle key="1">
        <TouchableOpacity onPress={handle(openCameraDialog)}>
          <Text> {ReasonReact.string("OPEN SELECT DIALOG")} </Text>
        </TouchableOpacity>
        <Text> {ReasonReact.string("image Uri:" ++ state.imageUri)} </Text>
      </View>,
  };
};

let examples: array(Example.t) = [|
  {
    title: "ImagePickerIOS.canRecordVideos(callback)",
    description: None,
    render: () => <CanRecordVideosExample />,
  },
  {
    title: "ImagePickerIOS.canUseCamera(callback)",
    description: None,
    render: () => <CanUseCameraExample />,
  },
  {
    title: "ImagePickerIOS.openCameraDialog(~videoMode, successCallback, cancelCallback)",
    description: None,
    render: () => <CameraDialogExample />,
  },
  {
    title: "ImagePickerIOS.openSelectDialog(~showImages, ~showVideos, successCallback, cancelCallback)",
    description: None,
    render: () => <SelectDialogExample />,
  },
|];
