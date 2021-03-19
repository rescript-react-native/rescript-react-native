type content
type options

@obj
external content: (~title: string=?, ~message: string=?, ~url: string=?, unit) => content = ""

@obj
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
  activityType: option<string>,
}

// multiple externals
@module("react-native") @scope("Share")
external share: content => Js.Promise.t<shareResult> = "share"

// multiple externals
@module("react-native") @scope("Share")
external shareWithOptions: (content, options) => Js.Promise.t<bool> = "share"
