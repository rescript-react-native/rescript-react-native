let make:
  (
    ~accessibilityLabel: string=?,
    ~color: string=?,
    ~disabled: bool=?,
    ~onPress: unit => unit,
    ~testID: string=?,
    ~title: string,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );