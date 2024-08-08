include NativeElement

type styleAttr = [
  | #Horizontal
  | #Normal
  | #Small
  | #Large
  | #Inverse
  | #SmallInverse
  | #LargeInverse
]

type progressBarAndroidProps = {
  ref?: ref,
  ...View.viewProps,
  animating?: bool,
  color?: Color.t,
  indeterminate?: bool,
  progress?: float,
  styleAttr?: styleAttr,
}

@react.component(: progressBarAndroidProps) @module("react-native")
external make: progressBarAndroidProps => React.element = "ProgressBarAndroid"
