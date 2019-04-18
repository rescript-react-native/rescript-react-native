module Permission = {
  type t = string;

  [@bs.inline]
  let readCalendar = "READ_CALENDAR";

  [@bs.inline]
  let writeCalendar = "WRITE_CALENDAR";

  [@bs.inline]
  let camera = "CAMERA";

  [@bs.inline]
  let readContacts = "READ_CONTACTS";

  [@bs.inline]
  let writeContacts = "WRITE_CONTACTS";

  [@bs.inline]
  let getAccounts = "GET_ACCOUNTS";

  [@bs.inline]
  let accessFineLocation = "ACCESS_FINE_LOCATION";

  [@bs.inline]
  let accessCoarseLocation = "ACCESS_COARSE_LOCATION";

  [@bs.inline]
  let recordAudio = "RECORD_AUDIO";

  [@bs.inline]
  let readPhoneState = "READ_PHONE_STATE";

  [@bs.inline]
  let callPhone = "CALL_PHONE";

  [@bs.inline]
  let readCallLog = "READ_CALL_LOG";

  [@bs.inline]
  let writeCallLog = "WRITE_CALL_LOG";

  [@bs.inline]
  let addVoicemail = "ADD_VOICEMAIL";

  [@bs.inline]
  let useSip = "USE_SIP";

  [@bs.inline]
  let processOutgoingCalls = "PROCESS_OUTGOING_CALLS";

  [@bs.inline]
  let bodySensors = "BODY_SENSORS";

  [@bs.inline]
  let sendSms = "SEND_SMS";

  [@bs.inline]
  let receiveSms = "RECEIVE_SMS";

  [@bs.inline]
  let readSms = "READ_SMS";

  [@bs.inline]
  let receiveWapPush = "RECEIVE_WAP_PUSH";

  [@bs.inline]
  let receiveMms = "RECEIVE_MMS";

  [@bs.inline]
  let readExternalStorage = "READ_EXTERNAL_STORAGE";

  [@bs.inline]
  let writeExternalStorage = "WRITE_EXTERNAL_STORAGE";

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

[@bs.scope "PermissionsAndroid"] [@bs.module "react-native"]
external check: Permission.t => Js.Promise.t(Js.Null.t(bool)) = "check";

[@bs.scope "PermissionsAndroid"] [@bs.module "react-native"]
external request: Permission.t => Js.Promise.t(Js.Null.t(string)) =
  "request";

[@bs.scope "PermissionsAndroid"] [@bs.module "react-native"]
external requestWithRationale:
  (Permission.t, rationale) => Js.Promise.t(Js.Null.t(string)) =
  "request";

[@bs.scope "PermissionsAndroid"] [@bs.module "react-native"]
external requestMultiple:
  array(Permission.t) => Js.Promise.t(Js.Dict.t(string)) =
  "request";
