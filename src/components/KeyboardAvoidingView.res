include NativeElement

type behavior = [#height | #position | #padding]

type props = {
  ref?: ref,
  ...View.viewProps,
  behavior?: behavior,
  contentContainerStyle?: Style.t,
  enabled?: bool,
  keyboardVerticalOffset?: float,
}

@module("react-native")
external make: React.component<props> = "KeyboardAvoidingView"
