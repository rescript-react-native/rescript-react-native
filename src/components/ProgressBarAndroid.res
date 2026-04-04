type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

external asProgressBarAndroidElement: DOMAPI.anyElement => element = "%identity"

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

@module("react-native")
external make: React.component<props> = "ProgressBarAndroid"
