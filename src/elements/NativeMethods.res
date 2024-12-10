open NativeTypes

module Make = (
  T: {
    type t
  },
) => {
  @module("react-native")
  external findNodeHandle: T.t => nodeHandle = "findNodeHandle"

  @send
  external setNativeProps: (T.t, {..}) => unit = "setNativeProps"

  @send external focus: T.t => unit = "focus"
  @send external blur: T.t => unit = "blur"

  @send
  external measure: (
    T.t,
    (~x: float, ~y: float, ~width: float, ~height: float, ~pageX: float, ~pageY: float) => unit,
  ) => unit = "measure"
  @send
  external measureInWindow: (
    T.t,
    (~x: float, ~y: float, ~width: float, ~height: float) => unit,
  ) => unit = "measureInWindow"

  @send
  external measureLayout: (
    T.t,
    ~relativeToNativeNode: nodeHandle,
    ~onSuccess: (~left: float, ~top: float, ~width: float, ~height: float) => unit,
    ~onFail: unit => unit,
  ) => unit = "measureLayout"
}
