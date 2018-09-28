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

type result =
  | GRANTED
  | DENIED
  | NEVER_ASK_AGAIN;

let check: Permission.t => Js.Promise.t(bool);

let request:
  (~permission: Permission.t, ~rationale: rationale=?, unit) =>
  Js.Promise.t(result);

let requestMultiple:
  (~permissions: list(Permission.t)) => Js.Promise.t(Js.Dict.t('a));