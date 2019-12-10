open NativeTypes;

module Make = (T: {type t;}) => {
  [@bs.module "react-native"]
  external findNodeHandle: T.t => nodeHandle = "findNodeHandle";

  [@bs.send]
  external setNativeProps: (T.t, Js.t('a)) => unit = "setNativeProps";

  [@bs.send] external focus: T.t => unit = "focus";
  [@bs.send] external blur: T.t => unit = "blur";

  [@bs.send]
  external measure: (T.t, measureResult => unit) => unit = "measure";
  [@bs.send]
  external measureInWindow: (T.t, measureInWindowResult => unit) => unit =
    "measureInWindow";

  [@bs.send]
  external measureLayout:
    (
      T.t,
      ~relativeToNativeNode: nodeHandle,
      ~onSuccess: measureResult => unit,
      ~onFail: measureError => unit
    ) =>
    unit =
    "measureLayout";
};
