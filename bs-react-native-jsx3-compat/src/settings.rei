/**
{b iOS only}

On iOS you can easily add your app custom settings into Settings app built-in iOS system. You can do it by adding Settings bundle into your Xcode project - [New File -> Settings Bundle -> Create]. Than you can compose your settings shape by modyfying [Settings.bundle/Root.plist].

You can read more on [Settings] API usage in official docs: {{:https://facebook.github.io/react-native/docs/settings}}

{3 Example of use }
{[
type action =
  | SetVersion(string);

type state = {version: string};

let component = ReasonReact.reducerComponent("SetExample");

let make = _children => {
  ...component,
  initialState: () => {version: "1.0"},
  reducer: (action: action, state: state) =>
    switch (action) {
    | SetVersion(version) => ReasonReact.Update({...state, version})
    },
  render: self =>
    <View>
      <TextInput
        value=self.state.version
        onChangeText=(text => self.send(SetVersion(text)))
      />
      <Button
        onPress=(
          () => {
            let settings = Js.Dict.empty();
            Js.Dict.set(settings, "version_preference", self.state.version);

            Settings.set(settings);
          }
        )
        title="Set version"
        accessibilityLabel="See an informative alert"
      />
      <Button
        onPress=(
          () => {
            let version = Settings.get("version_preference");
            Alert.alert(~title="version -> " ++ version, ());
          }
        )
        title="Get version"
        accessibilityLabel="See an informative alert"
      />
    </View>,
};

]}
{3 Methods}
{4 get }
Returns the value of one setting.

{[ let get: string => string; ]}
{4 set}
Sets values for settings. It will accept [Js.Dict] with your settings Identifiers as keys.

{[ let set: Js.Dict.t(string) => unit; ]}
{4 watchKeys }
Creates settings change listener. It will be fired after user change setting value in syste Settings app.

{[ let watchKeys: (list(string), unit => unit) => int; ]}
{4 clearWatch}
Removes listener by its id.

{[ let clearWatch: int => unit; ]}

*/

let get: string => string;

let set: Js.Dict.t(string) => unit;

type watchToken;

let watchKeys: (list(string), unit => unit) => watchToken;

let clearWatch: watchToken => unit;
