type element;
type ref = React.ref(element);

include NativeMethods.Make({
  type t = element;
});
