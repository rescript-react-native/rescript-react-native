// Methods available on every native element
module Methods = {
  include NativeMethods
  include DOMAPI.Element
}

// Defines `element`, `ref`, `unsafeFromAnyElement` and the native element methods.
// Public API for element modules, here and in third-party bindings:
//
//   type nativeElement
//   include NativeElement.Impl({type t = nativeElement})
module Impl = (
  T: {
    type t
  },
) => {
  type element = DOMAPI.element<T.t>
  type ref = Ref.t<element>

  external unsafeFromAnyElement: DOMAPI.anyElement => element = "%identity"

  include Methods
}
