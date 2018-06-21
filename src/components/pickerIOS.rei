module Item: {
  let make:
    (
      ~label: string,
      ~value: 'value=?,
      ~color: string=?,
      array(ReasonReact.reactElement)
    ) =>
    ReasonReact.component(
      ReasonReact.stateless,
      ReasonReact.noRetainedProps,
      unit,
    );
};

let make:
  (
    ~itemStyle: Style.t=?,
    ~onValueChange: 'value => unit=?,
    ~selectedValue: 'value=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    unit,
  );