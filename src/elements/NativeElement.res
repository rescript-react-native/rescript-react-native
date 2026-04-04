module Impl = (
  T: {
    type t
  },
) => {
  type element = DOMAPI.element<T.t>
  type ref = Ref.t<element>

  include NativeMethods.Make({
    type t = element
  })

  include DOMAPI.Element.Impl({
    type t = element
  })
}
