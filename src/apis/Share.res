type content = {
  title?: string,
  message?: string,
  url?: string,
}

@obj // @deprecated("Directly create record instead")
external content: (~title: string=?, ~message: string=?, ~url: string=?, unit) => content = ""

type options = {
  subject?: string,
  tintColor?: string,
  excludedActivityTypes?: array<string>,
  dialogTitle?: string,
}

@obj // @deprecated("Directly create record instead")
external options: (
  ~subject: string=?,
  ~tintColor: string=?,
  ~excludedActivityTypes: array<string>=?,
  ~dialogTitle: string=?,
  unit,
) => options = ""

type action

@module("react-native") @scope("Share")
external sharedAction: action = "sharedAction"

@module("react-native") @scope("Share")
external dismissedAction: action = "dismissedAction"

type shareResult = {
  action: action,
  activityType?: string,
}

// multiple externals
@module("react-native") @scope("Share")
external share: content => Js.Promise.t<shareResult> = "share"

// multiple externals
@module("react-native") @scope("Share")
external shareWithOptions: (content, options) => Js.Promise.t<bool> = "share"
