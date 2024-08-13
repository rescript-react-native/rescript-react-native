include NativeElement

type props = {
  ref?: ref,
  ...View.viewProps,
}

@module("react-native")
external make: React.component<props> = "SafeAreaView"
