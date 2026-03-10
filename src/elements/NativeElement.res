type element = DOMAPI.element
type ref = Ref.t<element>

include NativeMethods.Make({
  type t = element
})

include DOMAPI.Element.Impl({
  type t = element
})
