let make:
  (
    ~onSnapshotReady: unit => unit=?,
    ~testIdentifier: string=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );