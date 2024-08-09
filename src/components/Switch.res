include NativeElement

type trackColor = {
  \"true"?: Color.t,
  \"false"?: Color.t,
}

@obj
external // @deprecated("Directly create record instead")
trackColor: (~\"true": Color.t=?, ~\"false": Color.t=?, unit) => trackColor = ""

type switchProps = {
  ref?: ref,
  ...View.viewProps,
  disabled?: bool,
  trackColor?: trackColor,
  ios_backgroundColor?: Color.t,
  onValueChange?: bool => unit,
  thumbColor?: Color.t,
  value?: bool,
}

@react.component(: switchProps) @module("react-native")
external make: switchProps => React.element = "Switch"
