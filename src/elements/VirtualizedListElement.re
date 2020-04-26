type element;
type ref = Ref.t(element);

include VirtualizedListMethods.Make({
  type t = element;
});

include ScrollViewMethods.Make({
  type t = element;
});
