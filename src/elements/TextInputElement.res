type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

external asTextInputElement: DOMAPI.anyElement => element = "%identity"

include TextInputMethods.Make({
  type t = element
})
