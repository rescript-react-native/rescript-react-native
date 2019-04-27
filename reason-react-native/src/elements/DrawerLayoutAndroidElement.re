type element;
type ref = React.Ref.t(Js.nullable(element));

include DrawerLayoutAndroidMethods.Make({
  type t = element;
});

include NativeMethods.Make({
  type t = element;
});
