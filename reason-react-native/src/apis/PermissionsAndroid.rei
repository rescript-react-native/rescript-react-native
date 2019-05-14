module Permission: {
  type t;

  [@bs.inline "READ_CALENDAR"]
  let readCalendar: t;

  [@bs.inline "WRITE_CALENDAR"]
  let writeCalendar: t;

  [@bs.inline "CAMERA"]
  let camera: t;

  [@bs.inline "READ_CONTACTS"]
  let readContacts: t;

  [@bs.inline "WRITE_CONTACTS"]
  let writeContacts: t;

  [@bs.inline "GET_ACCOUNTS"]
  let getAccounts: t;

  [@bs.inline "ACCESS_FINE_LOCATION"]
  let accessFineLocation: t;

  [@bs.inline "ACCESS_COARSE_LOCATION"]
  let accessCoarseLocation: t;

  [@bs.inline "RECORD_AUDIO"]
  let recordAudio: t;

  [@bs.inline "READ_PHONE_STATE"]
  let readPhoneState: t;

  [@bs.inline "CALL_PHONE"]
  let callPhone: t;

  [@bs.inline "READ_CALL_LOG"]
  let readCallLog: t;

  [@bs.inline "WRITE_CALL_LOG"]
  let writeCallLog: t;

  [@bs.inline "ADD_VOICEMAIL"]
  let addVoicemail: t;

  [@bs.inline "USE_SIP"]
  let useSip: t;

  [@bs.inline "PROCESS_OUTGOING_CALLS"]
  let processOutgoingCalls: t;

  [@bs.inline "BODY_SENSORS"]
  let bodySensors: t;

  [@bs.inline "SEND_SMS"]
  let sendSms: t;

  [@bs.inline "RECEIVE_SMS"]
  let receiveSms: t;

  [@bs.inline "READ_SMS"]
  let readSms: t;

  [@bs.inline "RECEIVE_WAP_PUSH"]
  let receiveWapPush: t;

  [@bs.inline "RECEIVE_MMS"]
  let receiveMms: t;

  [@bs.inline "READ_EXTERNAL_STORAGE"]
  let readExternalStorage: t;

  [@bs.inline "WRITE_EXTERNAL_STORAGE"]
  let writeExternalStorage: t;

  external toString: t => string = "%identity";
};

type rationale;
[@bs.obj]
external rationale:
  (
    ~title: string,
    ~message: string,
    ~buttonPositive: string,
    ~buttonNegative: string=?,
    ~buttonNeutral: string=?,
    unit
  ) =>
  rationale =
  "";

[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external check: Permission.t => Js.Promise.t(Js.Null.t(bool)) = "";

// multiple externals
[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external request: Permission.t => Js.Promise.t(Js.Null.t(string)) = "";

// multiple externals
[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external requestWithRationale:
  (Permission.t, rationale) => Js.Promise.t(Js.Null.t(string)) =
  "request";

// multiple externals
[@bs.module "react-native"] [@bs.scope "PermissionsAndroid"]
external requestMultiple:
  array(Permission.t) => Js.Promise.t(Js.Dict.t(string)) =
  "request";
