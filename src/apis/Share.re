type content;
type options;

[@bs.obj]
external content:
  (~title: string=?, ~message: string=?, ~url: string=?, unit) => content;

[@bs.obj]
external options:
  (
    ~subject: string=?,
    ~tintColor: string=?,
    ~excludedActivityTypes: array(string)=?,
    ~dialogTitle: string=?,
    unit
  ) =>
  options;

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
