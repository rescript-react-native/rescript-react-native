type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

external asVirtualizedSectionListElement: DOMAPI.anyElement => element = "%identity"

include VirtualizedSectionListMethods.Make({
  type t = element
})
