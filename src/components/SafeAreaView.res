include NativeElement

@react.component(: View.viewProps) @module("react-native")
external make: View.viewProps => React.element = "SafeAreaView"
