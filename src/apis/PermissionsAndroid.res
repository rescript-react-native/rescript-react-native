module Permission = {
  type t = string

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external acceptHandover: t = "ACCEPT_HANDOVER"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external accessBackgroundLocation: t = "ACCESS_BACKGROUND_LOCATION"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external accessCoarseLocation: t = "ACCESS_COARSE_LOCATION"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external accessFineLocation: t = "ACCESS_FINE_LOCATION"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external accessMediaLocation: t = "ACCESS_MEDIA_LOCATION"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external activityRecognition: t = "ACTIVITY_RECOGNITION"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external addVoicemail: t = "ADD_VOICEMAIL"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external answerPhoneCalls: t = "ANSWER_PHONE_CALLS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external bluetoothAdvertise: t = "BLUETOOTH_ADVERTISE"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external bluetoothConnect: t = "BLUETOOTH_CONNECT"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external bluetoothScan: t = "BLUETOOTH_SCAN"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external bodySensors: t = "BODY_SENSORS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external bodySensorsBackground: t = "BODY_SENSORS_BACKGROUND"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external callPhone: t = "CALL_PHONE"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external camera: t = "CAMERA"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external getAccounts: t = "GET_ACCOUNTS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external nearbyWifiDevices: t = "NEARBY_WIFI_DEVICES"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external postNotifications: t = "POST_NOTIFICATIONS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external processOutgoingCalls: t = "PROCESS_OUTGOING_CALLS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external readCalendar: t = "READ_CALENDAR"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external readCallLog: t = "READ_CALL_LOG"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external readContacts: t = "READ_CONTACTS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external readExternalStorage: t = "READ_EXTERNAL_STORAGE"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external readMediaAudio: t = "READ_MEDIA_AUDIO"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external readMediaImages: t = "READ_MEDIA_IMAGES"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external readMediaVideo: t = "READ_MEDIA_VIDEO"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external readPhoneNumbers: t = "READ_PHONE_NUMBERS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external readPhoneState: t = "READ_PHONE_STATE"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external readSms: t = "READ_SMS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external readVoicemail: t = "READ_VOICEMAIL"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external receiveMms: t = "RECEIVE_MMS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external receiveSms: t = "RECEIVE_SMS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external receiveWapPush: t = "RECEIVE_WAP_PUSH"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external recordAudio: t = "RECORD_AUDIO"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external sendSms: t = "SEND_SMS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external useSip: t = "USE_SIP"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external uwbRanging: t = "UWB_RANGING"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external writeCalendar: t = "WRITE_CALENDAR"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external writeCallLog: t = "WRITE_CALL_LOG"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external writeContacts: t = "WRITE_CONTACTS"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external writeExternalStorage: t = "WRITE_EXTERNAL_STORAGE"

  @module("react-native") @scope(("PermissionsAndroid", "PERMISSIONS"))
  external writeVoicemail: t = "WRITE_VOICEMAIL"
}

module Result = {
  type t

  @module("react-native") @scope(("PermissionsAndroid", "RESULTS"))
  external denied: t = "DENIED"

  @module("react-native") @scope(("PermissionsAndroid", "RESULTS"))
  external granted: t = "GRANTED"

  @module("react-native") @scope(("PermissionsAndroid", "RESULTS"))
  external neverAskAgain: t = "NEVER_ASK_AGAIN"
}

type rationale = {
  title: string,
  message: string,
  buttonPositive: string,
  buttonNegative?: string,
  buttonNeutral?: string,
}

type dict = dict<Result.t>

@scope("PermissionsAndroid") @module("react-native")
external check: Permission.t => promise<bool> = "check"

// multiple externals
@scope("PermissionsAndroid") @module("react-native")
external request: Permission.t => promise<Result.t> = "request"

// multiple externals
@scope("PermissionsAndroid") @module("react-native")
external requestWithRationale: (Permission.t, rationale) => promise<Result.t> = "request"

@scope("PermissionsAndroid") @module("react-native")
external requestMultiple: array<Permission.t> => promise<dict> = "requestMultiple"

@get_index external get: (dict, Permission.t) => option<Result.t> = ""
