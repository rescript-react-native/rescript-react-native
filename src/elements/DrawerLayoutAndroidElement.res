type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

include DrawerLayoutAndroidMethods.Make({
  type t = element
})
