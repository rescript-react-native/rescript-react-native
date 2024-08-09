include NativeElement

type props = {
  ref?: ref,
  ...View.viewProps,
  colors?: array<Color.t>,
  enabled?: bool,
  onRefresh?: unit => unit,
  progressBackgroundColor?: Color.t,
  progressViewOffset?: float,
  refreshing: bool,
  size?: [#default | #large],
  tintColor?: Color.t,
  title?: string,
  titleColor?: Color.t,
}

@module("react-native")
external make: React.component<props> = "RefreshControl"
