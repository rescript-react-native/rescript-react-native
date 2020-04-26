type element;
type ref = Ref.t(element);

include TextInputMethods.Make({
  type t = element;
});

include NativeMethods.Make({
  type t = element;
});
