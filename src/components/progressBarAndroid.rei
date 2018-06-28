let make:
  (
    ~animating: bool=?,
    ~color: string=?,
    ~indeterminate: bool=?,
    ~progress: float=?,
    ~styleAttr: [
                  | `Horizontal
                  | `Inverse
                  | `Large
                  | `LargeInverse
                  | `Normal
                  | `Small
                  | `SmallInverse
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