type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

type trackColor = {
  \"true"?: Color.t,
  \"false"?: Color.t,
}

type props = {
  ref?: ref,
  ...View.viewProps,
  disabled?: bool,
  trackColor?: trackColor,
  ios_backgroundColor?: Color.t,
  onChange?: Event.switchChangeEvent => unit,
  onValueChange?: bool => unit,
  thumbColor?: Color.t,
  value?: bool,
}

@module("react-native")
external make: React.component<props> = "Switch"
