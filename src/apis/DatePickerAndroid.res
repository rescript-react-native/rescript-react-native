type options

type date

type action

external calendarDate: Js.Date.t => date = "%identity"
external timestamp: float => date = "%identity"

type mode = [#calendar | #spinner | #default]

@obj
external options: (
  ~date: date=?,
  ~minDate: date=?,
  ~maxDate: date=?,
  ~mode: mode=?,
  unit,
) => options = ""

type response = {
  action: action,
  year: int,
  month: int,
  day: int,
}

@module("react-native") @scope("DatePickerAndroid")
external open_: options => Js.Promise.t<response> = "open"

@module("react-native") @scope("DatePickerAndroid")
external dateSetAction: action = "dateSetAction"

@module("react-native") @scope("DatePickerAndroid")
external dismissedAction: action = "dismissedAction"
