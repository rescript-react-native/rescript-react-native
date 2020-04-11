module Permission: {
  type t;

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readCalendar: t = "READ_CALENDAR";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external writeCalendar: t = "WRITE_CALENDAR";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external camera: t = "CAMERA";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readContacts: t = "READ_CONTACTS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external writeContacts: t = "WRITE_CONTACTS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external getAccounts: t = "GET_ACCOUNTS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external accessFineLocation: t = "ACCESS_FINE_LOCATION";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external accessCoarseLocation: t = "ACCESS_COARSE_LOCATION";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external recordAudio: t = "RECORD_AUDIO";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readPhoneState: t = "READ_PHONE_STATE";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external callPhone: t = "CALL_PHONE";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readCallLog: t = "READ_CALL_LOG";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external writeCallLog: t = "WRITE_CALL_LOG";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external addVoicemail: t = "ADD_VOICEMAIL";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external useSip: t = "USE_SIP";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external processOutgoingCalls: t = "PROCESS_OUTGOING_CALLS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external bodySensors: t = "BODY_SENSORS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external sendSms: t = "SEND_SMS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external receiveSms: t = "RECEIVE_SMS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readSms: t = "READ_SMS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external receiveWapPush: t = "RECEIVE_WAP_PUSH";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external receiveMms: t = "RECEIVE_MMS";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external readExternalStorage: t = "READ_EXTERNAL_STORAGE";

  [@bs.module "react-native"]
  [@bs.scope ("PermissionsAndroid", "PERMISSIONS")]
  external writeExternalStorage: t = "WRITE_EXTERNAL_STORAGE";
};

module Result: {
  type t;

  [@bs.module "react-native"] [@bs.scope ("PermissionsAndroid", "RESULTS")]
  external granted: t = "GRANTED";

  [@bs.module "react-native"] [@bs.scope ("PermissionsAndroid", "RESULTS")]
  external denied: t = "DENIED";

  [@bs.module "react-native"] [@bs.scope ("PermissionsAndroid", "RESULTS")]
  external neverAskAgain: t = "NEVER_ASK_AGAIN";
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
  rationale;

type dict;

[@bs.scope "PermissionsAndroid"] [@bs.module "react-native"]
external check: Permission.t => Js.Promise.t(bool) = "check";

// multiple externals
[@bs.scope "PermissionsAndroid"] [@bs.module "react-native"]
external request: Permission.t => Js.Promise.t(Result.t) = "request";

// multiple externals
[@bs.scope "PermissionsAndroid"] [@bs.module "react-native"]
external requestWithRationale:
  (Permission.t, rationale) => Js.Promise.t(Result.t) =
  "request";

[@bs.scope "PermissionsAndroid"] [@bs.module "react-native"]
external requestMultiple: array(Permission.t) => Js.Promise.t(dict) =
  "requestMultiple";

[@bs.get_index] external get: (dict, Permission.t) => option(Result.t);
