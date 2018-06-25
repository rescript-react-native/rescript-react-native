let make:
  (
    ~color: string=?,
    ~animating: bool=?,
    ~indeterminate: bool=?,
    ~progress: float=?,
    ~styleAttr: [
                  | `Horizontal
                  | `Normal
                  | `Small
                  | `Large
                  | `Inverse
                  | `SmallInverse
                  | `LargeInverse
                ]
                  =?,
    ~testID: string=?,
    array(ReasonReact.reactElement)
  ) =>
  ReasonReact.component(
    ReasonReact.stateless,
    ReasonReact.noRetainedProps,
    ReasonReact.actionless,
  );