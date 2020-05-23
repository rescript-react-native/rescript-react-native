type element;
type ref = Ref.t(element);

include VirtualizedSectionListMethods.Make({
  type t = element;
});
