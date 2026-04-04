type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

external asTouchableOpacityElement: DOMAPI.anyElement => element = "%identity"

include TouchableOpacityMethods.Make({
  type t = element
})
