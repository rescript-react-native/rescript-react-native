/**
[AlertIOS] provides functionality to create an iOS alert dialog with a message or create a prompt for user input.


You can read more on [AlertIOS] API usage in official docs: {{:https://facebook.github.io/react-native/docs/alertios}}

{2 Example of use}
{4 alert}
{[
  AlertIOS.alert(
    ~title="This is an alert",
    ~message="Do something about it",
    ~buttons=[
      {
        text: Some("Agree"),
        onPress: Some(() => Js.log("You pressed the default button")),
        style: Some(`default),
      },
      {
        text: Some("Cancel"),
        onPress: Some(() => Js.log("You pressed the cancel button")),
        style: Some(`cancel),
      },
      {
        text: Some("Disagree"),
        onPress:
          Some(() => Js.log("You pressed the destructive button")),
        style: Some(`destructive),
      },
    ],
    (),
  );
]}
{4 prompt}
{[
  AlertIOS.prompt(
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
{2 Function parameters}
{3 [alert]}
{4 title}
{[
  ~title: string
]}
{4 message}
{[
  ~message: string=?
]}

{4 buttons }
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

{4 type_ }
{[
  ~type_: [< | `default | `loginPassword | `plainText | `secureText]=?
]}

{4 non-labeled argument }
{[ unit ]}

{3 [prompt]}
{4 title }
{[
  ~title: string
]}
{4 message }
{[
  ~message: string=?
]}
{4 buttons }
{[
  ~buttons: list(button)=?
]}

{4 type_ }
{[
  ~type_: [< | `default | `loginPassword | `plainText | `secureText]=?
]}
{4 defaultValue }
{[
  ~defaultValue: string=?
]}
{4 keyboardType }
{[
  ~keyboardType: [<
                  | `asciiCapable
                  | `decimalPad
                  | `default
                  | `emailAddress
                  | `namePhonePad
                  | `numberPad
                  | `numbersAndPunctuation
                  | `numeric
                  | `phonePad
                  | `twitter
                  | `url
                  | `webSearch
                ]
                  =?
]}
{4 non-labeled argument }
{[ unit ]}

*/

type type_ = [ | `default | `loginPassword | `plainText | `secureText];

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
    ~type_: [< | `default | `loginPassword | `plainText | `secureText]=?,
    unit
  ) =>
  unit;

let prompt:
  (
    ~title: string,
    ~message: string=?,
    ~buttons: list(button)=?,
    ~type_: [< | `default | `loginPassword | `plainText | `secureText]=?,
    ~defaultValue: string=?,
    ~keyboardType: [<
                     | `asciiCapable
                     | `decimalPad
                     | `default
                     | `emailAddress
                     | `namePhonePad
                     | `numberPad
                     | `numbersAndPunctuation
                     | `numeric
                     | `phonePad
                     | `twitter
                     | `url
                     | `webSearch
                   ]
                     =?,
    unit
  ) =>
  unit;
