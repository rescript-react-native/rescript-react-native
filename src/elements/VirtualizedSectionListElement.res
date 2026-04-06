type nativeElement

include NativeElement.Impl({
  type t = nativeElement
})

include VirtualizedSectionListMethods.Make({
  type t = element
})
