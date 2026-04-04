type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

external asDrawerLayoutAndroidElement: DOMAPI.anyElement => element = "%identity"

include DrawerLayoutAndroidMethods.Make({
  type t = element
})
