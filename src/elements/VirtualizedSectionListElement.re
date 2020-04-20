type element;
type ref = React.Ref.t(Js.nullable(element));

include VirtualizedSectionListMethods.Make({
  type t = element;
});
