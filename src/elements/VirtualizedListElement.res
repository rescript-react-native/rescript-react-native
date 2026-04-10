type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

include VirtualizedListMethods.Make({
  type t = element
})

include ScrollViewMethods.Make({
  type t = element
})
