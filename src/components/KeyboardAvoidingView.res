include NativeElement

type behavior = [#height | #position | #padding]

type keyboardAvoidingViewProps = {
  ...View.viewProps,
  behavior?: behavior,
  contentContainerStyle?: Style.t,
  enabled?: bool,
  keyboardVerticalOffset?: float,
}

@react.component(: keyboardAvoidingViewProps) @module("react-native")
external make: keyboardAvoidingViewProps => React.element = "KeyboardAvoidingView"
