type element;
type ref = Ref.t(element);

include TouchableOpacityMethods.Make({
  type t = element;
});

include NativeMethods.Make({
  type t = element;
});
