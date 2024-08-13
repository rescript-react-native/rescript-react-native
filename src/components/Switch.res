include NativeElement

type trackColor = {
  \"true"?: Color.t,
  \"false"?: Color.t,
}

@deprecated("Directly create record instead") @obj
external trackColor: (~\"true": Color.t=?, ~\"false": Color.t=?, unit) => trackColor = ""

type props = {
  ref?: ref,
  ...View.viewProps,
  disabled?: bool,
  trackColor?: trackColor,
  ios_backgroundColor?: Color.t,
  onValueChange?: bool => unit,
  thumbColor?: Color.t,
  value?: bool,
}

@module("react-native")
external make: React.component<props> = "Switch"
