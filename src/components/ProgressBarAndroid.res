type nativeElement

include NativeElement.Impl({type t = nativeElement})

type styleAttr = [
  | #Horizontal
  | #Normal
  | #Small
  | #Large
  | #Inverse
  | #SmallInverse
  | #LargeInverse
]

type props = {
  ref?: ref,
  ...View.viewProps,
  animating?: bool,
  color?: Color.t,
  indeterminate?: bool,
  progress?: float,
  styleAttr?: styleAttr,
}

@deprecated(
  "ProgressBarAndroid has been extracted from react-native core and will be removed in a future release, use @react-native-community/progress-bar-android instead."
)
@module("react-native")
external make: React.component<props> = "ProgressBarAndroid"
