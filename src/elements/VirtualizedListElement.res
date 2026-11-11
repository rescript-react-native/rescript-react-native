type nativeElement = [#scrollView | #virtualizedList]
include NativeElement.Impl({type t = nativeElement})
include ScrollViewMethods
include VirtualizedListMethods
