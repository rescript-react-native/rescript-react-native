type element;
type ref = Ref.t(element);

include ScrollViewMethods.Make({
  type t = element;
});

type scrollToParams;
[@bs.obj]
external scrollToParams:
  (~x: float, ~y: float, ~animated: bool=?, ~duration: float=?, unit) =>
  scrollToParams;
[@bs.send] external scrollTo: (element, scrollToParams) => unit = "scrollTo";
