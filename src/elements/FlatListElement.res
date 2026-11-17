// a FlatList is a VirtualizedList with a few methods of its own
type nativeElement = [#scrollView | #virtualizedList | #flatList]
include NativeElement.Impl({type t = nativeElement})
include ScrollViewMethods
include VirtualizedListMethods

// the underlying scroll view element
@send @return(nullable)
external getNativeScrollRef: element => option<ScrollViewElement.element> = "getNativeScrollRef"
