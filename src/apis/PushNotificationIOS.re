module Notification = {
  type t;

  [@bs.send] [@bs.return nullable]
  external getAlert: t => option(Js.Json.t) = "getAlert";

  [@bs.send] [@bs.return nullable]
  external getMessage: t => option(Js.Json.t) = "getMessage";

  [@bs.send] [@bs.return nullable]
  external getSound: t => option(string) = "getSound";

  [@bs.send] [@bs.return nullable]
  external getCategory: t => option(string) = "getCategory";

  // Actually type ContentAvailable = 1 | null | void ...
  [@bs.send] external getContentAvailable: t => bool = "getContentAvailable";

  [@bs.send] [@bs.return nullable]
  external getBadgeCount: t => option(int) = "getBadgeCount";

  [@bs.send] [@bs.return nullable]
  external getData: t => option(Js.Json.t) = "getData";

  [@bs.send] [@bs.return nullable]
  external getThreadID: t => option(string) = "getThreadID";
};

type localNotification;

[@bs.obj]
external localNotification:
  (
    ~alertBody: string=?,
    ~alertTitle: string=?,
    ~alertAction: string=?,
    ~soundName: string=?,
    ~isSilent: bool=?,
    ~category: string=?,
    ~userInfo: Js.Json.t=?,
    ~applicationIconBadgeNumber: int=?,
    ~fireDate: Js.Date.t=?,
    ~repeatInterval: [@bs.string] [
                       | `minute
                       | `hour
                       | `day
                       | `week
                       | `month
                       | `year
                     ]
                       =?,
    unit
  ) =>
  localNotification;

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external presentLocalNotification: localNotification => unit =
  "presentLocalNotification";

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external scheduleLocalNotification: localNotification => unit =
  "scheduleLocalNotification";

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external cancelAllLocalNotifications: unit => unit =
  "cancelAllLocalNotifications";

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external removeAllDeliveredNotifications: unit => unit =
  "removeAllDeliveredNotifications";

type deliveredNotification = {
  identifier: string,
  date: Js.Nullable.t(string),
  title: Js.Nullable.t(string),
  body: Js.Nullable.t(string),
  category: Js.Nullable.t(string),
  [@bs.as "thread-id"]
  threadId: Js.Nullable.t(string),
  userInfo: Js.Nullable.t(Js.Json.t),
};

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external getDeliveredNotifications:
  (array(deliveredNotification) => unit) => unit =
  "getDeliveredNotifications";

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external removeDeliveredNotifications: (~identifiers: array(string)) => unit =
  "removeDeliveredNotifications";

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external setApplicationIconBadgeNumber: int => unit =
  "setApplicationIconBadgeNumber";

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external getApplicationIconBadgeNumber: (int => unit) => unit =
  "getApplicationIconBadgeNumber";

// multiple externals
[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external cancelLocalNotifications: unit => unit = "cancelLocalNotifications";

// multiple externals
[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external cancelLocalNotificationsWithUserInfo: Js.Json.t => unit =
  "cancelLocalNotifications";

type formattedLocalNotification = {
  fireDate: Js.Nullable.t(string),
  alertAction: Js.Nullable.t(string),
  alertBody: Js.Nullable.t(string),
  applicationIconBadgeNumber: Js.Nullable.t(int),
  category: Js.Nullable.t(string),
  soundName: Js.Nullable.t(string),
  userInfo: Js.Nullable.t(Js.Json.t),
};

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external getScheduledLocalNotifications:
  (array(formattedLocalNotification) => unit) => unit =
  "getScheduledLocalNotifications";

type registrationError('a) = {
  message: string,
  code: int,
  details: Js.t('a),
};

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external addEventListener:
  (
  [@bs.string]
  [
    | `notification(Notification.t => unit)
    | `localNotification(Notification.t => unit)
    | `register((~deviceToken: string) => unit)
    | `registrationError(registrationError('a) => unit)
  ]
  ) =>
  unit =
  "addEventListener";

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external removeEventListener:
  (
  [@bs.string]
  [
    | `notification(Notification.t => unit)
    | `localNotification(Notification.t => unit)
    | `register((~deviceToken: string) => unit)
    | `registrationError(registrationError('a) => unit)
  ]
  ) =>
  unit =
  "removeEventListener";

type permissions = {
  .
  "alert": bool,
  "badge": bool,
  "sound": bool,
};

type requestPermissionsOptions;
[@bs.obj]
external requestPermissionsOptions:
  (~alert: bool=?, ~badge: bool=?, ~sound: bool=?, unit) =>
  requestPermissionsOptions;

// multiple externals
[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external requestPermissions: unit => Js.Promise.t(permissions) =
  "requestPermissions";

// multiple externals
[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external requestPermissionsWithOptions:
  requestPermissionsOptions => Js.Promise.t(permissions) =
  "requestPermissions";

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external abandonPermissions: unit => unit = "abandonPermissions";

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external checkPermissions: (unit => permissions) => unit = "checkPermissions";

type fetchResult;
[@bs.obj]
external fetchResult:
  (~_NewData: string=?, ~_NoData: string=?, ~_ResultFailed: string=?, unit) =>
  fetchResult;

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external finish: fetchResult => unit = "fetchResult";

[@bs.module "react-native"] [@bs.scope "PushNotificationIOS"]
external getInitialNotification:
  unit => Js.Promise.t(Js.Nullable.t(Notification.t)) =
  "getInitialNotification";
