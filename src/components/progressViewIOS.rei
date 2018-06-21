let make:
  (
    ~progress: float=?,
    ~progressImage: Image.imageSource=?,
    ~progressTintColor: string=?,
    ~progressViewStyle: Style.t=?,
    ~trackImage: Image.imageSource=?,
    ~trackTintColor: string=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );