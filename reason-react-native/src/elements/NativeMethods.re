open NativeTypes;

module Make = (T: {type t;}) => {
  [@bs.module "react-native"] external findNodeHandle: T.t => nodeHandle = "";

  [@bs.send] external setNativeProps: (T.t, Js.t('a)) => unit = "";

  [@bs.send] external focus: T.t => unit = "";
  [@bs.send] external blur: T.t => unit = "";

  [@bs.send] external measure: (T.t, measureResult => unit) => unit = "";
  [@bs.send]
  external measureInWindow: (T.t, measureInWindowResult => unit) => unit = "";

  [@bs.send]
  external measureLayout:
    (
      T.t,
      ~relativeToNativeNode: nodeHandle,
      ~onSuccess: measureResult => unit,
      ~onFail: measureError => unit
    ) =>
    unit =
    "";
};
