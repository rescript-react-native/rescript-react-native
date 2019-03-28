open BsReactNative;
open Utils;

let exampleType = Multiple;

let displayName = "PermissionsAndroid";

let title = "PermissionsAndroid";

let description = "Example of getting SEND_SMS via PermissionsAndroid (only Android)";

module ExampleSingle = {
  let component =
    ReasonReact.statelessComponent("PermissionsAndroidExampleContent");

  let requestPermissions = () =>
    PermissionsAndroid.request(
      ~permission=PermissionsAndroid.Permission.SEND_SMS,
      ~rationale=
        PermissionsAndroid.rationale(
          ~title="Hello!",
          ~message="Cool app wants to send SMS...",
          (),
        ),
      (),
    )
    |> Js.Promise.then_(permissions => {
         Js.log(permissions);
         Js.Promise.resolve();
       })
    |> ignore;

  let make = _children => {
    ...component,
    render: _children =>
      <View>
        <TouchableNativeFeedback
          background={TouchableNativeFeedback.selectableBackground()}
          onPress={_ => requestPermissions()}>
          <View style=Style.(style([backgroundColor(String("#03DAC5"))]))>
            <Text
              style=Style.(
                style([
                  marginVertical(Pt(20.)),
                  textAlign(Center),
                  fontSize(Float(20.)),
                ])
              )>
              {ReasonReact.string("Get SEND_SMS permission")}
            </Text>
          </View>
        </TouchableNativeFeedback>
      </View>,
  };
};

module ExampleMultiple = {
  let component =
    ReasonReact.statelessComponent("PermissionsAndroidExampleContent");

  let requestMultiplePermissions = () => {
    PermissionsAndroid.requestMultiple(
      ~permissions=[
        PermissionsAndroid.Permission.SEND_SMS,
        PermissionsAndroid.Permission.READ_EXTERNAL_STORAGE,
        PermissionsAndroid.Permission.WRITE_EXTERNAL_STORAGE,
      ],
    )
    |> Js.Promise.then_(res => {
         Js.log(res);
         Js.Promise.resolve();
       })
    |> ignore;

    ();
  };

  let make = _children => {
    ...component,
    render: _children =>
      <View>
        <TouchableNativeFeedback
          background={TouchableNativeFeedback.selectableBackground()}
          onPress={_ => requestMultiplePermissions()}>
          <View style=Style.(style([backgroundColor(String("#03DAC5"))]))>
            <Text
              style=Style.(
                style([
                  marginVertical(Pt(20.)),
                  textAlign(Center),
                  fontSize(Float(20.)),
                ])
              )>
              {ReasonReact.string("Get multiple permissions")}
            </Text>
          </View>
        </TouchableNativeFeedback>
      </View>,
  };
};

let examples: array(Example.t) = [|
  {
    title: "PermissionsAndroid",
    description: Some("Single permissions"),
    render: () => <ExampleSingle />,
  },
  {
    title: "PermissionsAndroid",
    description: Some("Multiple permissions"),
    render: () => <ExampleMultiple />,
  },
|];
