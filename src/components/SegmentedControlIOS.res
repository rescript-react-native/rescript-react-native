include NativeElement

module ChangeEvent = {
  type payload = {
    value: string,
    selectedSegmentIndex: int,
  }

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type changeEvent = ChangeEvent.t

type segmentControlIOSProps = {
  ref?: ref,
  ...View.viewProps,
  enabled?: bool,
  momentary?: bool,
  onChange?: changeEvent => unit,
  onValueChange?: int => unit,
  selectedIndex?: int,
  tintColor?: string,
  values?: array<string>,
}

@react.component(: segmentControlIOSProps) @module("react-native")
external make: segmentControlIOSProps => React.element = "SegmentedControlIOS"
