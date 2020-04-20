module Make = (T: {type t;}) => {
  type scrollToEndOptions;
  [@bs.obj]
  external scrollToEndOptions:
    (~animated: bool=?, ~duration: float=?, unit) => scrollToEndOptions;

  // multiple externals
  [@bs.send] external scrollToEnd: T.t => unit = "scrollToEnd";

  // multiple externals
  [@bs.send]
  external scrollToEndWithOptions: (T.t, scrollToEndOptions) => unit =
    "scrollToEnd";

  [@bs.send]
  external flashScrollIndicators: T.t => unit = "flashScrollIndicators";

  [@bs.send]
  external setNativeProps: (T.t, Js.t('a)) => unit = "setNativeProps";
};
