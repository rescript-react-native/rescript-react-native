[@bs.deriving abstract]
type rationale = {
  [@bs.optional]
  title: string,
  [@bs.optional]
  message: string,
};

module Permission = {
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

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readCalendar: string = "READ_CALENDAR";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external writeCalendar: string = "WRITE_CALENDAR";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external camera: string = "CAMERA";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readContacts: string = "READ_CONTACTS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external writeContacts: string = "WRITE_CONTACTS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external getAccounts: string = "GET_ACCOUNTS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external accessFineLocation: string = "ACCESS_FINE_LOCATION";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external accessCoarseLocation: string = "ACCESS_COARSE_LOCATION";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external recordAudio: string = "RECORD_AUDIO";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readPhoneState: string = "READ_PHONE_STATE";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external callPhone: string = "CALL_PHONE";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readCallLog: string = "READ_CALL_LOG";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external writeCallLog: string = "WRITE_CALL_LOG";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external addVoicemail: string = "permission.ADD_VOICEMAIL";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external useSip: string = "USE_SIP";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external processOutgoingCalls: string = "PROCESS_OUTGOING_CALLS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external bodySensors: string = "BODY_SENSORS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external sendSms: string = "SEND_SMS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external receiveSms: string = "RECEIVE_SMS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readSms: string = "READ_SMS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external receiveWapPush: string = "RECEIVE_WAP_PUSH";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external receiveMms: string = "RECEIVE_MMS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readExternalStorage: string = "READ_EXTERNAL_STORAGE";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external writeExternalStorage: string = "WRITE_EXTERNAL_STORAGE";

  let getPermission = value =>
    switch (value) {
    | READ_CALENDAR => readCalendar
    | WRITE_CALENDAR => writeCalendar
    | CAMERA => camera
    | READ_CONTACTS => readContacts
    | WRITE_CONTACTS => writeContacts
    | GET_ACCOUNTS => getAccounts
    | ACCESS_FINE_LOCATION => accessFineLocation
    | ACCESS_COARSE_LOCATION => accessCoarseLocation
    | RECORD_AUDIO => recordAudio
    | READ_PHONE_STATE => readPhoneState
    | CALL_PHONE => callPhone
    | READ_CALL_LOG => readCallLog
    | WRITE_CALL_LOG => writeCallLog
    | ADD_VOICEMAIL => addVoicemail
    | USE_SIP => useSip
    | PROCESS_OUTGOING_CALLS => processOutgoingCalls
    | BODY_SENSORS => bodySensors
    | SEND_SMS => sendSms
    | RECEIVE_SMS => receiveSms
    | READ_SMS => readSms
    | RECEIVE_WAP_PUSH => receiveWapPush
    | RECEIVE_MMS => receiveMms
    | READ_EXTERNAL_STORAGE => readExternalStorage
    | WRITE_EXTERNAL_STORAGE => writeExternalStorage
    };
};

type result =
  | GRANTED
  | DENIED
  | NEVER_ASK_AGAIN;

[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external granted: string = "GRANTED";

[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external denied: string = "DENIED";

[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external neverAskAgain: string = "NEVER_ASK_AGAIN";

let getResult = r =>
  switch (r) {
  | r when r === granted => GRANTED
  | r when r === denied => DENIED
  | r when r === neverAskAgain => NEVER_ASK_AGAIN
  | _ => DENIED
  };

[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external _check: string => Js.Promise.t(bool) = "check";

let check = permission => _check(Permission.getPermission(permission));

[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external _request:
  (~permission: string, ~rationale: rationale=?, unit) => Js.Promise.t(string) =
  "request";

let request = (~permission, ~rationale=?, ()) =>
  switch (rationale) {
  | Some(rationale) =>
    _request(
      ~permission=Permission.getPermission(permission),
      ~rationale,
      (),
    )
    |> Js.Promise.then_(res => Js.Promise.resolve(getResult(res)))
  | None =>
    _request(~permission=Permission.getPermission(permission), ())
    |> Js.Promise.then_(res => Js.Promise.resolve(getResult(res)))
  };

[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external _requestMultiple: array(string) => Js.Promise.t(Js.Dict.t('a)) =
  "requestMultiple";

let requestMultiple = (~permissions: list(Permission.t)) => {
  let permissions =
    permissions |> List.map(Permission.getPermission) |> ArrayLabels.of_list;

  _requestMultiple(permissions)
  |> Js.Promise.then_(result => Js.Promise.resolve(result));
};
