type element;
type ref = Ref.t(element);

include NativeMethods.Make({
  type t = element;
});
