type element;
type ref = React.Ref.t(Js.nullable(element));

include NativeMethods.Make({
  type t = element;
});
