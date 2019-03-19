/**
Launches an alert dialog with the specified title and message.

Optionally provide a list of buttons. Tapping any button will fire the respective onPress callback and dismiss the alert. By default, the only button will be an 'OK' button.

This is an API that works both on iOS and Android and can show static alerts. To show an alert that prompts the user to enter some information, see {{:\BsReactNative/AlertIOS-BsReactNative} [AlertIOS] }; entering text in an alert is common on iOS only.

You can read more on [Alert] API usage in official docs: {{:https://facebook.github.io/react-native/docs/alert}}


{3 Example of use}

{[
  Alert.alert(
  ~title="This is an alert",
  ~message="Do something about it",
  ~type_=`secureText,
  ~buttons=[
    {
      text: Some("Something bad will happen"),
      onPress: Some(() => Js.log("Bad happened")),
      style: Some(`destructive),
    },
  ],
  (),
);
]}

{3 Function parameters}

{4 title}

{[ ~title: string ]}

{4 message}

{[
   ~message: string=?
]}

{4 button}
{[
  ~buttons: list(button)=?
]}

reference:

{[
  type button = {
    text: option(string),
    onPress: option((unit => unit)),
    style: option([ | `cancel | `default | `destructive])
  };
]}

{4 options }
{[
  ~options: options=?
]}
reference:

{[
  type options = {
    cancelable: option(bool),
    onDismiss: option((unit => unit))
  }
]}

{4 type_ }
{[
  type type_ = [ | `default | `loginPassword | `plainText | `secureText];
]}

{4 non-labeled argument }
{[ unit ]}

*/
type type_ = [ | `default | `loginPassword | `plainText | `secureText];

type options = {
  cancelable: option(bool),
  onDismiss: option(unit => unit),
};

type button = {
  text: option(string),
  onPress: option(unit => unit),
  style: option([ | `cancel | `default | `destructive]),
};

let alert:
  (
    ~title: string,
    ~message: string=?,
    ~buttons: list(button)=?,
    ~options: options=?,
    ~type_: [< | `default | `loginPassword | `plainText | `secureText]=?,
    unit
  ) =>
  unit;
