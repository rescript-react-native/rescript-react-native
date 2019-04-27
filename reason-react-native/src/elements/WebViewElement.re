type element;
type ref = React.Ref.t(Js.nullable(element));

include WebViewMethods.Make({
  type t = element;
});

include NativeMethods.Make({
  type t = element;
});
