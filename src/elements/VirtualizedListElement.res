type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

external asVirtualizedListElement: DOMAPI.anyElement => element = "%identity"

include VirtualizedListMethods.Make({
  type t = element
})

include ScrollViewMethods.Make({
  type t = element
})
