/**

You can read more on [PermissionsAndroid] API usage in official docs: {{:https://facebook.github.io/react-native/docs/permissionAndroid}}

{3 Example of use}
{4 Requesting single permission. }
{[
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
]}

{4 Requesting multiple permissions.}
{[
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
]}

{4 Functions}
{3 check}
{[
  let check: Permission.t => Js.Promise.t(bool);
]}
{4 request}
{[
  let request:
    (~permission: Permission.t, ~rationale: rationale=?, unit) =>
    Js.Promise.t(result);
]}
To create rationale paramters use [PermissionsAndroid.rationale] function.

{[
  PermissionsAndroid.rationale(
    ~title="Hello!",
    ~message="Cool app wants to send SMS...",
    (),
  ),
]}

{4 requestMultiple }
{[

  let requestMultiple:
    (~permissions: list(Permission.t)) => Js.Promise.t(Js.Dict.t('a));
]}
{4 rationale }
To create rationale for showing why you want to get permission.

{[ let requestMultiple: (~title=string=?, ~message=string=?, unit) => rationale; ]}
{3 Permissions that require prompting the user }
All possieble values are avaliable via PermissionsAndroid.Permission
{[

  PermissionsAndroid.Permission.READ_CALENDAR;
  PermissionsAndroid.Permission.WRITE_CALENDAR;
  PermissionsAndroid.Permission.CAMERA;
  PermissionsAndroid.Permission.READ_CONTACTS;
  PermissionsAndroid.Permission.WRITE_CONTACTS;
  PermissionsAndroid.Permission.GET_ACCOUNTS;
  PermissionsAndroid.Permission.ACCESS_FINE_LOCATION;
  PermissionsAndroid.Permission.ACCESS_COARSE_LOCATION;
  PermissionsAndroid.Permission.RECORD_AUDIO;
  PermissionsAndroid.Permission.READ_PHONE_STATE;
  PermissionsAndroid.Permission.CALL_PHONE;
  PermissionsAndroid.Permission.READ_CALL_LOG;
  PermissionsAndroid.Permission.WRITE_CALL_LOG;
  PermissionsAndroid.Permission.ADD_VOICEMAIL;
  PermissionsAndroid.Permission.USE_SIP;
  PermissionsAndroid.Permission.PROCESS_OUTGOING_CALLS;
  PermissionsAndroid.Permission.BODY_SENSORS;
  PermissionsAndroid.Permission.SEND_SMS;
  PermissionsAndroid.Permission.RECEIVE_SMS;
  PermissionsAndroid.Permission.READ_SMS;
  PermissionsAndroid.Permission.RECEIVE_WAP_PUSH;
  PermissionsAndroid.Permission.RECEIVE_MMS;
  PermissionsAndroid.Permission.READ_EXTERNAL_STORAGE;
  PermissionsAndroid.Permission.WRITE_EXTERNAL_STORAGE;
]}

{4 Results for requesting }
{[
  PermissionsAndroid.GRANTED
  PermissionsAndroid.DENIED
  PermissionsAndroid.NEVER_ASK_AGAIN
]}

*/

type result =
  | GRANTED
  | DENIED
  | NEVER_ASK_AGAIN;

[@bs.deriving abstract]
type rationale = {
  [@bs.optional]
  title: string,
  [@bs.optional]
  message: string,
};

module Permission: {
  type t =
    | READ_CALENDAR
    | WRITE_CALENDAR
    | CAMERA
    | READ_CONTACTS
    | WRITE_CONTACTS
    | GET_ACCOUNTS
    | ACCESS_FINE_LOCATION
    | ACCESS_COARSE_LOCATION
    | RECORD_AUDIO
    | READ_PHONE_STATE
    | CALL_PHONE
    | READ_CALL_LOG
    | WRITE_CALL_LOG
    | ADD_VOICEMAIL
    | USE_SIP
    | PROCESS_OUTGOING_CALLS
    | BODY_SENSORS
    | SEND_SMS
    | RECEIVE_SMS
    | READ_SMS
    | RECEIVE_WAP_PUSH
    | RECEIVE_MMS
    | READ_EXTERNAL_STORAGE
    | WRITE_EXTERNAL_STORAGE;
};

let check: Permission.t => Js.Promise.t(bool);

let request:
  (~permission: Permission.t, ~rationale: rationale=?, unit) =>
  Js.Promise.t(result);

let requestMultiple:
  (~permissions: list(Permission.t)) => Js.Promise.t(Js.Dict.t('a));
