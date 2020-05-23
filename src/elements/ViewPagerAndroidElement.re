type element;
type ref = Ref.t(element);

include ViewPagerAndroidMethods.Make({
  type t = element;
});

include NativeMethods.Make({
  type t = element;
});
