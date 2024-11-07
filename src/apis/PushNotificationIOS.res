module Notification = {
  type t

  @send @return(nullable)
  external getAlert: t => option<Js.Json.t> = "getAlert"

  @send @return(nullable)
  external getMessage: t => option<Js.Json.t> = "getMessage"

  @send @return(nullable)
  external getSound: t => option<string> = "getSound"

  @send @return(nullable)
  external getCategory: t => option<string> = "getCategory"

  // Actually type ContentAvailable = 1 | null | void ...
  @send external getContentAvailable: t => bool = "getContentAvailable"

  @send @return(nullable)
  external getBadgeCount: t => option<int> = "getBadgeCount"

  @send @return(nullable)
  external getData: t => option<Js.Json.t> = "getData"

  @send @return(nullable)
  external getThreadID: t => option<string> = "getThreadID"
}

type repeatInterval = [#minute | #hour | #day | #week | #month | #year]

type localNotification = {
  alertBody?: string,
  alertTitle?: string,
  alertAction?: string,
  soundName?: string,
  isSilent?: bool,
  category?: string,
  userInfo?: Js.Json.t,
  applicationIconBadgeNumber?: int,
  fireDate?: Js.Date.t,
  repeatInterval?: repeatInterval,
}

@deprecated("Directly create record instead") @obj
external localNotification: (
  ~alertBody: string=?,
  ~alertTitle: string=?,
  ~alertAction: string=?,
  ~soundName: string=?,
  ~isSilent: bool=?,
  ~category: string=?,
  ~userInfo: Js.Json.t=?,
  ~applicationIconBadgeNumber: int=?,
  ~fireDate: Js.Date.t=?,
  ~repeatInterval: repeatInterval=?,
  unit,
) => localNotification = ""

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external presentLocalNotification: localNotification => unit = "presentLocalNotification"

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external scheduleLocalNotification: localNotification => unit = "scheduleLocalNotification"

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external cancelAllLocalNotifications: unit => unit = "cancelAllLocalNotifications"

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external removeAllDeliveredNotifications: unit => unit = "removeAllDeliveredNotifications"

type deliveredNotification = {
  identifier: string,
  date: Js.Nullable.t<string>,
  title: Js.Nullable.t<string>,
  body: Js.Nullable.t<string>,
  category: Js.Nullable.t<string>,
  \"thread-id": Js.Nullable.t<string>,
  userInfo: Js.Nullable.t<Js.Json.t>,
}

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external getDeliveredNotifications: (array<deliveredNotification> => unit) => unit =
  "getDeliveredNotifications"

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external removeDeliveredNotifications: (~identifiers: array<string>) => unit =
  "removeDeliveredNotifications"

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external setApplicationIconBadgeNumber: int => unit = "setApplicationIconBadgeNumber"

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external getApplicationIconBadgeNumber: (int => unit) => unit = "getApplicationIconBadgeNumber"

// multiple externals
@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external cancelLocalNotifications: unit => unit = "cancelLocalNotifications"

// multiple externals
@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external cancelLocalNotificationsWithUserInfo: Js.Json.t => unit = "cancelLocalNotifications"

type formattedLocalNotification = {
  fireDate: Js.Nullable.t<string>,
  alertAction: Js.Nullable.t<string>,
  alertBody: Js.Nullable.t<string>,
  applicationIconBadgeNumber: Js.Nullable.t<int>,
  category: Js.Nullable.t<string>,
  soundName: Js.Nullable.t<string>,
  userInfo: Js.Nullable.t<Js.Json.t>,
}

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external getScheduledLocalNotifications: (array<formattedLocalNotification> => unit) => unit =
  "getScheduledLocalNotifications"

type registrationError<'a> = {
  message: string,
  code: int,
  details: Js.t<'a>,
}

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external addEventListener: @string
[
  | #notification(Notification.t => unit)
  | #localNotification(Notification.t => unit)
  | #register((~deviceToken: string) => unit)
  | #registrationError(registrationError<'a> => unit)
] => unit = "addEventListener"

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external removeEventListener: @string
[
  | #notification(Notification.t => unit)
  | #localNotification(Notification.t => unit)
  | #register((~deviceToken: string) => unit)
  | #registrationError(registrationError<'a> => unit)
] => unit = "removeEventListener"

type permissions = {"alert": bool, "badge": bool, "sound": bool}

type checkedPermissions = {
  "alert": bool,
  "badge": bool,
  "sound": bool,
  "critical": bool,
  "lockScreen": bool,
  "notificationCenter": bool,
  "autorizationStatus": int,
}

type requestPermissionsOptions = {
  alert?: bool,
  badge?: bool,
  sound?: bool,
}

@deprecated("Directly create record instead") @obj
external requestPermissionsOptions: (
  ~alert: bool=?,
  ~badge: bool=?,
  ~sound: bool=?,
  unit,
) => requestPermissionsOptions = ""

// multiple externals
@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external requestPermissions: unit => promise<permissions> = "requestPermissions"

// multiple externals
@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external requestPermissionsWithOptions: requestPermissionsOptions => promise<permissions> =
  "requestPermissions"

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external abandonPermissions: unit => unit = "abandonPermissions"

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external checkPermissions: (unit => checkedPermissions) => unit = "checkPermissions"

type fetchResult = {
  \"NewData"?: string,
  \"NoData"?: string,
  \"ResultFailed"?: string,
}

@deprecated("Directly create record instead") @obj
external fetchResult: (
  ~\"NewData": string=?,
  ~\"NoData": string=?,
  ~\"ResultFailed": string=?,
  unit,
) => fetchResult = ""

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external finish: fetchResult => unit = "fetchResult"

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external getInitialNotification: unit => promise<Js.Nullable.t<Notification.t>> =
  "getInitialNotification"

@deprecated(
  "PushNotificationIOS is deprecated, migrate to @react-native-community/push-notification-ios"
)
@module("react-native")
@scope("PushNotificationIOS")
external getAuthorizationStatus: (float => unit) => unit = "getAuthorizationStatus"
