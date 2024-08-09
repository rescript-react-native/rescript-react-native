include NativeElement

@unboxed
type size = | @as("small") Small | @as("large") Large | Number(float)

type props = {
  ref?: ref,
  ...View.viewProps,
  animating?: bool,
  color?: Color.t,
  size?: size,
  hidesWhenStopped?: bool,
}

@module("react-native")
external make: React.component<props> = "ActivityIndicator"
