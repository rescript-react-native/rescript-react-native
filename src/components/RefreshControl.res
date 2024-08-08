include NativeElement

type refreshControlProps = {
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

@react.component(: refreshControlProps) @module("react-native")
external make: refreshControlProps => React.element = "RefreshControl"
