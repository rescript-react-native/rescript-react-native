open BsReactNative;
open Utils;

let exampleType = Multiple;

let displayName = "SettingsExample";

let title = "SettingsExample";

let description = "SettingsExample (iOS only)";

module SetExample = {
  type action =
    | SetVersion(string);

  type state = {version: string};

  let component = ReasonReact.reducerComponent("SetExample");

  let make = _children => {
    ...component,
    initialState: () => {version: "1.0"},
    reducer: (action: action, _state: state) =>
      switch (action) {
      | SetVersion(version) => ReasonReact.Update({version: version})
      },
    didMount: _self => {
      let _ =
        Settings.watchKeys(
          ["name_preference"],
          _ => {
            Js.log("New value set");
            ();
          },
        );
      let id =
        Settings.watchKeys(["name_preference"], _ =>
          Js.log("New value set 2")
        );
      Settings.clearWatch(id);
    },
    render: self =>
      <View>
        <TextInput
          value={self.state.version}
          onChangeText={text => self.send(SetVersion(text))}
        />
        <Button
          onPress={_ => {
            let settings = Js.Dict.empty();
            Js.Dict.set(settings, "version_preference", self.state.version);

            Settings.set(settings);
          }}
          title="Set version"
          accessibilityLabel="See an informative alert"
        />
      </View>,
  };
};

let examples: array(Example.t) = [|
  {
    title: "Set",
    description: Some("Set Settings values"),
    render: () => <SetExample />,
  },
  {
    title: "Get",
    description: Some("Get Settings value"),
    render: () =>
      <Button
        onPress={_ => {
          let version = Settings.get("version_preference");
          Alert.alert(~title="version -> " ++ version, ());
        }}
        title="Get version"
        accessibilityLabel="See an informative alert"
      />,
  },
|];
