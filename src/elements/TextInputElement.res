type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

include TextInputMethods.Make({
  type t = element
})
