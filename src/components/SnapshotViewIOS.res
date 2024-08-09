module SnapshotReadyEvent = {
  type payload = {testIdentifier: string}

  include Event.SyntheticEvent({
    type _payload = payload
  })
}

type snapshotReadyEvent = SnapshotReadyEvent.t

type props = {
  ...View.viewProps,
  onSnapshotReady?: snapshotReadyEvent => unit,
  testIdentifier?: string,
}

@module("react-native")
external make: React.component<props> => React.element = "SnapshotViewIOS"
