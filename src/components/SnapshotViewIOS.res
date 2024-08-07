module SnapshotReadyEvent = {
  type payload = {testIdentifier: string}

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type snapshotReadyEvent = SnapshotReadyEvent.t

type scrollViewPropsnapshotViewIOSProps = {
  ...View.viewProps,
  onSnapshotReady?: snapshotReadyEvent => unit,
  testIdentifier?: string,
}

@react.component(: scrollViewPropsnapshotViewIOSProps) @module("react-native")
external make: scrollViewPropsnapshotViewIOSProps => React.element = "SnapshotViewIOS"
