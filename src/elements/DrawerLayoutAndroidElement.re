type element;
type ref = Ref.t(element);

include DrawerLayoutAndroidMethods.Make({
  type t = element;
});

include NativeMethods.Make({
  type t = element;
});
