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

type props = {
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

@module("react-native")
external make: React.component<props> = "SegmentedControlIOS"
