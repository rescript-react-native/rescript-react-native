open NativeTypes

module Make = (
  T: {
    type t
  },
) => {
  @bs.module("react-native")
  external findNodeHandle: T.t => nodeHandle = "findNodeHandle"

  @bs.send
  external setNativeProps: (T.t, Js.t<'a>) => unit = "setNativeProps"

  @bs.send external focus: T.t => unit = "focus"
  @bs.send external blur: T.t => unit = "blur"

  @bs.send
  external measure: (
    T.t,
    (~x: float, ~y: float, ~width: float, ~height: float, ~pageX: float, ~pageY: float) => unit,
  ) => unit = "measure"
  @bs.send
  external measureInWindow: (
    T.t,
    (~x: float, ~y: float, ~width: float, ~height: float) => unit,
  ) => unit = "measureInWindow"

  @bs.send
  external measureLayout: (
    T.t,
    ~relativeToNativeNode: nodeHandle,
    ~onSuccess: (~left: float, ~top: float, ~width: float, ~height: float) => unit,
    ~onFail: unit => unit,
  ) => unit = "measureLayout"
}
