include NativeElement

@unboxed
type size = | @as("small") Small | @as("large") Large | Number(float)

type activityIndicatorProps = {
  ...View.viewProps,
  animating?: bool,
  color?: Color.t,
  size?: size,
  hidesWhenStopped?: bool,
}

@react.component(: activityIndicatorProps) @module("react-native")
external make: activityIndicatorProps => React.element = "ActivityIndicator"
