type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

include TouchableOpacityMethods.Make({
  type t = element
})
