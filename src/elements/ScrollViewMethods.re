module Make = (T: {type t;}) => {
  type scrollToParams;
  [@bs.obj]
  external scrollToParams:
    (~x: float, ~y: float, ~animated: bool=?, ~duration: float=?, unit) =>
    scrollToParams;
  [@bs.send] external scrollTo: (T.t, scrollToParams) => unit = "scrollTo";

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
};
