include NativeElement

type safeAreaViewProps = {
  ref?: ref,
  ...View.viewProps,
}

@react.component(: safeAreaViewProps) @module("react-native")
external make: safeAreaViewProps => React.element = "SafeAreaView"
