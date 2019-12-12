type content = {
  title: option(string),
  message: option(string),
  url: option(string),
};
type options = {
  subject: option(string),
  tintColor: option(string),
  excludedActivityTypes: option(array(string)),
  dialogTitle: option(string),
};

type action;

[@bs.module "react-native"] [@bs.scope "Share"]
external sharedAction: action = "sharedAction";

[@bs.module "react-native"] [@bs.scope "Share"]
external dismissedAction: action = "dismissedAction";

type shareResult = {
  action,
  activityType: option(string),
};

// multiple externals
[@bs.module "react-native"] [@bs.scope "Share"]
external share: content => Js.Promise.t(shareResult) = "share";

// multiple externals
[@bs.module "react-native"] [@bs.scope "Share"]
external shareWithOptions: (content, options) => Js.Promise.t(bool) = "share";
