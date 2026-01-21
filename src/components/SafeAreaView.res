include NativeElement

type props = {
  ref?: ref,
  ...View.viewProps,
}

@deprecated(
  "Legacy <SafeAreaView> component is deprecated, use more portable and flexible solutions, such as react-native-safe-area-context."
)
@module("react-native")
external make: React.component<props> = "SafeAreaView"
