open NativeTypes

// Methods available on every native element

@module("react-native")
external findNodeHandle: DOMAPI.element<'nativeElement> => nodeHandle = "findNodeHandle"

@send
external setNativeProps: (DOMAPI.element<'nativeElement>, {..}) => unit = "setNativeProps"

@send external focus: DOMAPI.element<'nativeElement> => unit = "focus"
@send external blur: DOMAPI.element<'nativeElement> => unit = "blur"

@send
external measure: (
  DOMAPI.element<'nativeElement>,
  (~x: float, ~y: float, ~width: float, ~height: float, ~pageX: float, ~pageY: float) => unit,
) => unit = "measure"
@send
external measureInWindow: (
  DOMAPI.element<'nativeElement>,
  (~x: float, ~y: float, ~width: float, ~height: float) => unit,
) => unit = "measureInWindow"

@send
external measureLayout: (
  DOMAPI.element<'nativeElement>,
  ~relativeToNativeNode: nodeHandle,
  ~onSuccess: (~left: float, ~top: float, ~width: float, ~height: float) => unit,
  ~onFail: unit => unit,
) => unit = "measureLayout"
