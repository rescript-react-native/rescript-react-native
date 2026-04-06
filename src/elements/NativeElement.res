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

@deprecated(
  "Bindings maintainers: please use NativeElement.Impl instead of accessing the types directly."
)
include Impl({
  type t = DOMAPI.anyElement
})
